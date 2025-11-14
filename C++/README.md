# C++ Language Exercises

This folder contains 15 C++ exercises. Each exercise is in its own folder `exN`.

Structure for each exercise folder (topic-based filenames):

- `ex0/hello_world.cpp` and `ex0/hello_world_solution.cpp` - print "Hello, World!"
- `ex1/add.cpp` and `ex1/add_solution.cpp` - sum / add function
- `ex2/palindrome.cpp` and `ex2/palindrome_solution.cpp` - palindrome check
- `ex3/selection_sort.cpp` and `ex3/selection_sort_solution.cpp` - selection sort
- `ex4/linked_list_reverse.cpp` and `ex4/linked_list_reverse_solution.cpp` - linked list reversal
- `ex5/inversion_count.cpp` and `ex5/inversion_count_solution.cpp` - inversion counting
- `ex6/longest_increasing_subsequence.cpp` and `ex6/longest_increasing_subsequence_solution.cpp` - longest increasing subsequence (LIS)
- `ex7/binary_search.cpp` and `ex7/binary_search_solution.cpp` - binary search (find element index in sorted array)
- `ex8/pointer_arithmetic.cpp` and `ex8/pointer_arithmetic_solution.cpp` - access vector elements via pointer arithmetic
- `ex9/vector_modify.cpp` and `ex9/vector_modify_solution.cpp` - modify vector elements via reference return
- `ex10/string_reverse.cpp` and `ex10/string_reverse_solution.cpp` - reverse a string using std::reverse
- `ex11/gcd.cpp` and `ex11/gcd_solution.cpp` - find greatest common divisor using __gcd
- `ex12/matrix_transpose.cpp` and `ex12/matrix_transpose_solution.cpp` - transpose a matrix using vector of vectors
- `ex13/bubble_sort.cpp` and `ex13/bubble_sort_solution.cpp` - sort vector using bubble sort algorithm
- `ex14/string_length.cpp` and `ex14/string_length_solution.cpp` - find longest and shortest string

Each C++ file includes a comment at the top with the exercise title and difficulty (stars using `*`).

How to compile (PowerShell on Windows):

```
# compile an exercise (example: ex1 solution)
g++ "ex1/add_solution.cpp" -O2 -std=c++17 -o "ex1\add_solution.exe"
& "ex1\add_solution.exe"
```

If `g++` is not available on your system, install MinGW-w64 or use WSL.
