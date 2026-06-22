using System.Drawing;

namespace DSPI.Improved.Processing;

public sealed record PhaseFrame(float[] Wrapped, float[] Quality, int Width, int Height);
public sealed record UnwrapResult(float[] Values, byte[] Display, int Width, int Height,
                                  double FringeOrder, float Minimum, float Maximum);

public static class PhaseAlgorithms
{
    public const float TwoPi = 2f * MathF.PI;

    public static byte[] SaturatingFringeDifference(ReadOnlySpan<byte> current,
                                                     ReadOnlySpan<byte> reference,
                                                     float contrast)
    {
        if (current.Length != reference.Length) throw new ArgumentException("图像尺寸不一致。");
        var output = new byte[current.Length];
        contrast = Math.Max(0f, contrast);
        for (var i = 0; i < output.Length; i++)
        {
            var value = contrast * Math.Abs(current[i] - reference[i]);
            output[i] = (byte)Math.Clamp((int)MathF.Round(value), 0, 255);
        }
        return output;
    }

    public static PhaseFrame FourStep(ReadOnlySpan<byte> i1, ReadOnlySpan<byte> i2,
                                      ReadOnlySpan<byte> i3, ReadOnlySpan<byte> i4,
                                      int width, int height)
    {
        var count = checked(width * height);
        if (i1.Length < count || i2.Length < count || i3.Length < count || i4.Length < count)
            throw new ArgumentException("四步相移图像尺寸不足。");

        var phase = new float[count];
        var quality = new float[count];
        for (var i = 0; i < count; i++)
        {
            var x = i1[i] - i3[i];
            var y = i4[i] - i2[i];
            var angle = MathF.Atan2(y, x);
            phase[i] = angle < 0f ? angle + TwoPi : angle;
            quality[i] = MathF.Sqrt(x * x + y * y);
        }
        return new PhaseFrame(phase, quality, width, height);
    }

    public static PhaseFrame CircularDifference(PhaseFrame current, PhaseFrame reference)
    {
        EnsureSameSize(current, reference);
        var phase = new float[current.Wrapped.Length];
        var quality = new float[phase.Length];
        for (var i = 0; i < phase.Length; i++)
        {
            phase[i] = WrapToPi(current.Wrapped[i] - reference.Wrapped[i]);
            quality[i] = MathF.Min(current.Quality[i], reference.Quality[i]);
        }
        return new PhaseFrame(phase, quality, current.Width, current.Height);
    }

    public static PhaseFrame CircularMean(PhaseFrame source, int passes)
    {
        if (passes < 1) return source with { Wrapped = (float[])source.Wrapped.Clone() };
        var width = source.Width;
        var height = source.Height;
        var current = (float[])source.Wrapped.Clone();
        var next = new float[current.Length];

        for (var pass = 0; pass < passes; pass++)
        {
            for (var y = 0; y < height; y++)
            for (var x = 0; x < width; x++)
            {
                double sin = 0, cos = 0, weightSum = 0;
                for (var ky = -1; ky <= 1; ky++)
                for (var kx = -1; kx <= 1; kx++)
                {
                    var yy = Math.Clamp(y + ky, 0, height - 1);
                    var xx = Math.Clamp(x + kx, 0, width - 1);
                    var index = yy * width + xx;
                    var weight = Math.Max(1e-3f, source.Quality[index]);
                    sin += weight * Math.Sin(current[index]);
                    cos += weight * Math.Cos(current[index]);
                    weightSum += weight;
                }
                next[y * width + x] = (float)Math.Atan2(sin / weightSum, cos / weightSum);
            }
            (current, next) = (next, current);
        }

        return new PhaseFrame(current, (float[])source.Quality.Clone(), width, height);
    }

    public static UnwrapResult QualityGuidedUnwrap(PhaseFrame source, Rectangle roi)
    {
        roi = Rectangle.Intersect(roi, new Rectangle(0, 0, source.Width, source.Height));
        if (roi.Width < 2 || roi.Height < 2) throw new ArgumentException("请先框选至少 2×2 的有效区域。");

        var count = checked(roi.Width * roi.Height);
        var wrapped = new float[count];
        var quality = new float[count];
        var seed = 0;
        for (var y = 0; y < roi.Height; y++)
        for (var x = 0; x < roi.Width; x++)
        {
            var dst = y * roi.Width + x;
            var src = (roi.Y + y) * source.Width + roi.X + x;
            wrapped[dst] = source.Wrapped[src];
            quality[dst] = source.Quality[src];
            if (quality[dst] > quality[seed]) seed = dst;
        }

        var values = new float[count];
        var visited = new bool[count];
        var queue = new PriorityQueue<(int From, int To), float>();
        visited[seed] = true;
        values[seed] = wrapped[seed];
        EnqueueNeighbors(seed);

        while (queue.TryDequeue(out var edge, out _))
        {
            if (visited[edge.To]) continue;
            values[edge.To] = values[edge.From] + WrapToPi(wrapped[edge.To] - wrapped[edge.From]);
            visited[edge.To] = true;
            EnqueueNeighbors(edge.To);
        }

        var min = values.Min();
        var max = values.Max();
        var range = max - min;
        var display = new byte[count];
        if (range > 1e-9f)
            for (var i = 0; i < count; i++)
                display[i] = (byte)Math.Clamp((int)MathF.Round((values[i] - min) * 255f / range), 0, 255);

        return new UnwrapResult(values, display, roi.Width, roi.Height, range / TwoPi, min, max);

        void EnqueueNeighbors(int from)
        {
            var x = from % roi.Width;
            var y = from / roi.Width;
            Add(x - 1, y); Add(x + 1, y); Add(x, y - 1); Add(x, y + 1);
            void Add(int nx, int ny)
            {
                if ((uint)nx >= (uint)roi.Width || (uint)ny >= (uint)roi.Height) return;
                var to = ny * roi.Width + nx;
                if (!visited[to]) queue.Enqueue((from, to), -MathF.Min(quality[from], quality[to]));
            }
        }
    }

    public static byte[] PhaseToGray(ReadOnlySpan<float> phase)
    {
        var output = new byte[phase.Length];
        for (var i = 0; i < output.Length; i++)
        {
            var normalized = phase[i] % TwoPi;
            if (normalized < 0) normalized += TwoPi;
            output[i] = (byte)Math.Clamp((int)MathF.Round(normalized * 255f / TwoPi), 0, 255);
        }
        return output;
    }

    public static byte[] Jet(ReadOnlySpan<byte> gray)
    {
        var rgb = new byte[gray.Length * 3];
        for (var i = 0; i < gray.Length; i++)
        {
            var x = gray[i] / 255f;
            var r = Math.Clamp(1.5f - Math.Abs(4f * x - 3f), 0f, 1f);
            var g = Math.Clamp(1.5f - Math.Abs(4f * x - 2f), 0f, 1f);
            var b = Math.Clamp(1.5f - Math.Abs(4f * x - 1f), 0f, 1f);
            rgb[3 * i] = (byte)MathF.Round(r * 255f);
            rgb[3 * i + 1] = (byte)MathF.Round(g * 255f);
            rgb[3 * i + 2] = (byte)MathF.Round(b * 255f);
        }
        return rgb;
    }

    public static float WrapToPi(float value)
    {
        value = (value + MathF.PI) % TwoPi;
        if (value < 0) value += TwoPi;
        return value - MathF.PI;
    }

    private static void EnsureSameSize(PhaseFrame a, PhaseFrame b)
    {
        if (a.Width != b.Width || a.Height != b.Height || a.Wrapped.Length != b.Wrapped.Length)
            throw new ArgumentException("相位图尺寸不一致。");
    }
}
