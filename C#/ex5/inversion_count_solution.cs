// Solution Ex 5 — Inversion count (merge sort)
using System;
using System.Linq;

class Program {
    static long MergeCount(int[] a, int l, int r) {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2;
        long cnt = MergeCount(a, l, m) + MergeCount(a, m, r);
        int i = l, j = m;
        var tmp = new int[r-l];
        int k = 0;
        while (i < m && j < r) {
            if (a[i] <= a[j]) tmp[k++] = a[i++];
            else { tmp[k++] = a[j++]; cnt += (m - i); }
        }
        while (i < m) tmp[k++] = a[i++];
        while (j < r) tmp[k++] = a[j++];
        Array.Copy(tmp, 0, a, l, tmp.Length);
        return cnt;
    }

    static void Main() {
        string? line = Console.ReadLine();
        if (line == null) return;
        int n = int.Parse(line.Trim());
        var parts = Console.ReadLine()?.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries) ?? Array.Empty<string>();
        int[] a = parts.Select(int.Parse).ToArray();
        if (a.Length != n) {
            var list = a.ToList();
            while (list.Count < n) {
                var ln = Console.ReadLine();
                if (ln == null) break;
                foreach (var t in ln.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries)) list.Add(int.Parse(t));
            }
            a = list.ToArray();
        }
        long res = MergeCount(a, 0, n);
        Console.WriteLine(res);
    }
}
