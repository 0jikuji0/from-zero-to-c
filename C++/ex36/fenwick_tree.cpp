/**
 * Exercise 36: Fenwick Tree (Binary Indexed Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Fenwick Tree (Binary Indexed Tree) for efficient range queries
 * and point updates on an array. This data structure supports:
 * - Update(index, value): Add value to element at index (1-indexed)
 * - Query(index): Get prefix sum from 1 to index
 * - RangeQuery(left, right): Get sum of elements from left to right
 * 
 * Both operations run in O(log n) time, making it efficient for problems
 * requiring frequent updates and range sum queries.
 * 
 * The tree uses bit manipulation to navigate parent-child relationships:
 * - Parent: index - (index & -index)
 * - Next: index + (index & -index)
 * 
 * Input:
 * - First line: size of array N
 * - Second line: N space-separated integers (initial array values)
 * - Third line: number of operations Q
 * - Next Q lines: operation commands
 *   - "update I V": add V to element at index I (1-indexed)
 *   - "query I": get prefix sum from 1 to I
 *   - "range L R": get sum from L to R (inclusive)
 * 
 * Output:
 * - For "query I": print the prefix sum
 * - For "range L R": print the range sum
 * 
 * Example:
 * Input:
 * 5
 * 1 3 5 7 9
 * 4
 * query 3
 * range 2 4
 * update 3 2
 * range 2 4
 * 
 * Output:
 * 9
 * 15
 * 17
 */

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;
    
    // TODO: Implement LSB(index): return index & -index (least significant bit)
    
    // TODO: Implement updateHelper(index, delta): add delta to tree[index]
    //       and propagate to parents
    
    // TODO: Implement queryHelper(index): compute prefix sum from 1 to index
    
public:
    // TODO: Constructor: initialize tree with size n+1 (1-indexed)
    //       and build tree from initial array
    
    // TODO: Implement update(index, value): add value to position index
    
    // TODO: Implement query(index): return prefix sum from 1 to index
    
    // TODO: Implement rangeQuery(left, right): return sum from left to right
    //       using query(right) - query(left-1)
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    FenwickTree ft(arr);
    
    int q;
    cin >> q;
    cin.ignore();
    
    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
