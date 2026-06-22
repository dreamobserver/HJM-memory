using DSPI.Improved.Processing;

namespace DSPI.Improved;

internal static class Program
{
    [STAThread]
    private static void Main(string[] args)
    {
        if (args.Contains("--self-test", StringComparer.OrdinalIgnoreCase))
        {
            AlgorithmSelfTest.Run();
            return;
        }

        ApplicationConfiguration.Initialize();
        var snapshotIndex = Array.FindIndex(args, a => a.Equals("--ui-snapshot", StringComparison.OrdinalIgnoreCase));
        if (snapshotIndex >= 0 && snapshotIndex + 1 < args.Length)
        {
            using var form = new MainForm
            {
                WindowState = FormWindowState.Normal,
                StartPosition = FormStartPosition.Manual,
                Location = new Point(-32000, -32000),
                Size = new Size(1600, 950)
            };
            form.Show();
            Application.DoEvents();
            using var bitmap = new Bitmap(form.ClientSize.Width, form.ClientSize.Height);
            form.DrawToBitmap(bitmap, new Rectangle(Point.Empty, bitmap.Size));
            bitmap.Save(args[snapshotIndex + 1]);
            form.Close();
            return;
        }
        Application.Run(new MainForm());
    }
}
