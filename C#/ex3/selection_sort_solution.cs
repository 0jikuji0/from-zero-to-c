// Solution Ex 3 — Selection sort
using System;
using System.Linq;

class Program {
    static void Main() {
        string? line = Console.ReadLine();
        if (line == null) return;
        int n = int.Parse(line.Trim());
        var parts = Console.ReadLine()?.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries) ?? Array.Empty<string>();
        int[] a = parts.Select(int.Parse).ToArray();
        if (a.Length != n) {
            // try to read more tokens if needed
            var list = a.ToList();
            while (list.Count < n) {
                var next = Console.ReadLine();
                if (next == null) break;
                foreach (var t in next.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries)) list.Add(int.Parse(t));
            }
            a = list.ToArray();
        }
        for (int i = 0; i < n; ++i) {
            int best = i;
            for (int j = i+1; j < n; ++j) if (a[j] < a[best]) best = j;
            int tmp = a[i]; a[i] = a[best]; a[best] = tmp;
        }
        Console.WriteLine(string.Join(' ', a));
    }
}
