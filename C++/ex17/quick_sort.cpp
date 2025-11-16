/**
 * Exercise 17: Quicksort Algorithm
 * Difficulty: *** (3/5)
 * 
 * Implement the quicksort algorithm to sort a vector of integers.
 * Quicksort uses a divide-and-conquer approach with a pivot element.
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

// TODO: Implement the quicksort algorithm
// Hint: Use a partition function to divide the array

// TODO: Implement the partition function that places a pivot
// in its correct sorted position and returns the pivot index

// TODO: Print the array in sorted order (space-separated)

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // TODO: Call quicksort function
    
    // TODO: Print sorted array
    
    return 0;
}
