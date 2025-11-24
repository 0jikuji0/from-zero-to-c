/**
 * Exercise 34: Suffix Array and LCP Array (Advanced String Processing)
 * Difficulty: ****** (6/5) - BONUS CHALLENGE
 * 
 * Implement a Suffix Array construction algorithm with O(n log n) complexity
 * and compute the Longest Common Prefix (LCP) array using Kasai's algorithm.
 * Use these structures to solve various string problems:
 * - Find longest repeated substring
 * - Count distinct substrings
 * - Find longest common substring between two strings
 * 
 * This is an advanced data structure combining sorting, ranking, and efficient
 * string comparison techniques used in competitive programming and bioinformatics.
 * 
 * Input:
 * - First line: operation type ("lrs", "count", or "lcs")
 * - Second line: string S (for lrs and count)
 * - For "lcs": Second line: string S1, Third line: string S2
 * 
 * Output:
 * - For "lrs": print the longest repeated substring (or "No repeat" if none)
 * - For "count": print the number of distinct substrings
 * - For "lcs": print the longest common substring (or "No common substring")
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Suffix : IComparable<Suffix>
{
    public int Index { get; set; }
    public int[] Rank { get; set; }

    public Suffix()
    {
        Rank = new int[2];
    }

    public int CompareTo(Suffix other)
    {
        if (Rank[0] != other.Rank[0])
            return Rank[0].CompareTo(other.Rank[0]);
        return Rank[1].CompareTo(other.Rank[1]);
    }
}

class Program
{
    static int[] BuildSuffixArray(string text)
    {
        int n = text.Length;
        List<Suffix> suffixes = new List<Suffix>();

        for (int i = 0; i < n; i++)
        {
            suffixes.Add(new Suffix
            {
                Index = i,
                Rank = new int[] { text[i], (i + 1 < n) ? text[i + 1] : -1 }
            });
        }

        suffixes.Sort();

        int[] ind = new int[n];

        for (int k = 4; k < 2 * n; k *= 2)
        {
            int rank = 0;
            int prevRank = suffixes[0].Rank[0];
            suffixes[0].Rank[0] = rank;
            ind[suffixes[0].Index] = 0;

            for (int i = 1; i < n; i++)
            {
                if (suffixes[i].Rank[0] == prevRank &&
                    suffixes[i].Rank[1] == suffixes[i - 1].Rank[1])
                {
                    prevRank = suffixes[i].Rank[0];
                    suffixes[i].Rank[0] = rank;
                }
                else
                {
                    prevRank = suffixes[i].Rank[0];
                    suffixes[i].Rank[0] = ++rank;
                }
                ind[suffixes[i].Index] = i;
            }

            for (int i = 0; i < n; i++)
            {
                int nextIndex = suffixes[i].Index + k / 2;
                suffixes[i].Rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].Rank[0] : -1;
            }

            suffixes.Sort();
        }

        int[] suffixArr = new int[n];
        for (int i = 0; i < n; i++)
        {
            suffixArr[i] = suffixes[i].Index;
        }

        return suffixArr;
    }

    static int[] BuildLCPArray(string text, int[] suffixArr)
    {
        int n = text.Length;
        int[] lcp = new int[n];
        int[] invSuff = new int[n];

        for (int i = 0; i < n; i++)
        {
            invSuff[suffixArr[i]] = i;
        }

        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (invSuff[i] == n - 1)
            {
                k = 0;
                continue;
            }

            int j = suffixArr[invSuff[i] + 1];

            while (i + k < n && j + k < n && text[i + k] == text[j + k])
            {
                k++;
            }

            lcp[invSuff[i]] = k;

            if (k > 0)
            {
                k--;
            }
        }

        return lcp;
    }

    static void LongestRepeatedSubstring(string text)
    {
        int n = text.Length;
        int[] suffixArr = BuildSuffixArray(text);
        int[] lcp = BuildLCPArray(text, suffixArr);

        int maxLCP = 0;
        int maxIndex = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (lcp[i] > maxLCP)
            {
                maxLCP = lcp[i];
                maxIndex = suffixArr[i];
            }
        }

        if (maxLCP == 0)
        {
            Console.WriteLine("No repeat");
        }
        else
        {
            Console.WriteLine(text.Substring(maxIndex, maxLCP));
        }
    }

    static void CountDistinctSubstrings(string text)
    {
        int n = text.Length;
        int[] suffixArr = BuildSuffixArray(text);
        int[] lcp = BuildLCPArray(text, suffixArr);

        long total = (long)n * (n + 1) / 2;
        long lcpSum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            lcpSum += lcp[i];
        }

        Console.WriteLine(total - lcpSum);
    }

    static void LongestCommonSubstring(string s1, string s2)
    {
        int n1 = s1.Length;
        int n2 = s2.Length;

        string combined = s1 + "#" + s2;
        int n = combined.Length;

        int[] suffixArr = BuildSuffixArray(combined);
        int[] lcp = BuildLCPArray(combined, suffixArr);

        int maxLCP = 0;
        int maxIndex = 0;

        for (int i = 0; i < n - 1; i++)
        {
            bool first = (suffixArr[i] < n1);
            bool second = (suffixArr[i + 1] > n1);

            if ((first && second) || (second && first))
            {
                if (lcp[i] > maxLCP)
                {
                    maxLCP = lcp[i];
                    maxIndex = suffixArr[i];
                }
            }
        }

        if (maxLCP == 0)
        {
            Console.WriteLine("No common substring");
        }
        else
        {
            Console.WriteLine(combined.Substring(maxIndex, maxLCP));
        }
    }

    static void Main()
    {
        string operation = Console.ReadLine();

        if (operation == "lrs")
        {
            string text = Console.ReadLine();
            LongestRepeatedSubstring(text);
        }
        else if (operation == "count")
        {
            string text = Console.ReadLine();
            CountDistinctSubstrings(text);
        }
        else if (operation == "lcs")
        {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            LongestCommonSubstring(s1, s2);
        }
    }
}
