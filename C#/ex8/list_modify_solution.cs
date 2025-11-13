// List Modify (Exercise 8) - Solution
// Modify a specific element in a List at a given index.

using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        string? line = Console.ReadLine();
        if (line == null) return;
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        
        List<int> lst = new List<int>();
        foreach (string part in parts) {
            if (int.TryParse(part, out int val)) {
                lst.Add(val);
            }
        }
        
        string? modifyLine = Console.ReadLine();
        if (modifyLine == null) return;
        var modifyParts = modifyLine.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        if (modifyParts.Length < 2) return;
        
        if (int.TryParse(modifyParts[0], out int i) && int.TryParse(modifyParts[1], out int v)) {
            if (i >= 0 && i < lst.Count) {
                lst[i] = v;
            }
        }
        
        Console.WriteLine(string.Join(" ", lst));
    }
}
