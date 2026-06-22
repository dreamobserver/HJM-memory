using System.Drawing;

namespace DSPI.Improved.Processing;

internal static class AlgorithmSelfTest
{
    public static void Run()
    {
        TestSaturatingDifference();
        TestCircularMeanBoundary();
        TestQualityGuidedUnwrap();
        Console.WriteLine("All DSPI algorithm self-tests passed.");
    }

    private static void TestSaturatingDifference()
    {
        var result = PhaseAlgorithms.SaturatingFringeDifference([250], [0], 2f);
        Assert(result[0] == 255, "条纹差分必须饱和到 255，不能回绕。");
    }

    private static void TestCircularMeanBoundary()
    {
        var phase = new[] { 0.02f, PhaseAlgorithms.TwoPi - 0.02f, 0.01f };
        var frame = new PhaseFrame(phase, [1f, 1f, 1f], 3, 1);
        var filtered = PhaseAlgorithms.CircularMean(frame, 1);
        Assert(Math.Abs(PhaseAlgorithms.WrapToPi(filtered.Wrapped[1])) < 0.05,
               "圆周均值不能把 0/2π 边界错误平均到 π。");
    }

    private static void TestQualityGuidedUnwrap()
    {
        const int width = 32, height = 24;
        var truth = new float[width * height];
        var wrapped = new float[truth.Length];
        var quality = Enumerable.Repeat(1f, truth.Length).ToArray();
        for (var y = 0; y < height; y++)
        for (var x = 0; x < width; x++)
        {
            var i = y * width + x;
            truth[i] = 0.35f * x + 0.18f * y;
            wrapped[i] = PhaseAlgorithms.WrapToPi(truth[i]);
        }
        var result = PhaseAlgorithms.QualityGuidedUnwrap(new PhaseFrame(wrapped, quality, width, height),
                                                         new Rectangle(0, 0, width, height));
        var offset = result.Values[0] - truth[0];
        var maxError = result.Values.Select((v, i) => Math.Abs(v - truth[i] - offset)).Max();
        Assert(maxError < 1e-4, $"解包裹误差过大：{maxError}");
    }

    private static void Assert(bool condition, string message)
    {
        if (!condition) throw new InvalidOperationException(message);
    }
}
