/**
 * Exercise 19: Merge Sort Algorithm
 * Difficulty: *** (3/5)
 * 
 * Implement the merge sort algorithm to sort a vector of integers.
 * Merge sort is a divide-and-conquer sorting algorithm with O(n log n) time complexity.
 * 
 * Input:
 * - First line: number of elements (n)
 * - Second line: n integers to be sorted
 * 
 * Output:
 * - Print the sorted vector in ascending order (space-separated)
 */

#include <bits/stdc++.h>
using namespace std;

// TODO: Implement merge sort algorithm
// Hint: Use divide-and-conquer to recursively sort and merge

// TODO: Implement merge function to combine two sorted subarrays

// TODO: Print the sorted vector

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // TODO: Call merge sort function
    
    // TODO: Print sorted vector
    
    return 0;
}
