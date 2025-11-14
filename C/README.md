# C Language Exercises

This workspace contains 21 C language exercises. Each exercise is in its own folder `exN`.

Structure for each exercise folder (topic-based filenames):

- `ex0/hello_world.c` and `ex0/hello_world_solution.c` - print "Hello, World!"
- `ex1/add.c` and `ex1/add_solution.c` - sum / add function
- `ex2/palindrome.c` and `ex2/palindrome_solution.c` - palindrome check
- `ex3/selection_sort.c` and `ex3/selection_sort_solution.c` - selection sort
- `ex4/linked_list_reverse.c` and `ex4/linked_list_reverse_solution.c` - linked list reversal
- `ex5/inversion_count.c` and `ex5/inversion_count_solution.c` - inversion counting
- `ex6/prime_sieve.c` and `ex6/prime_sieve_solution.c` - count primes <= n (Sieve of Eratosthenes)
- `ex7/two_sum.c` and `ex7/two_sum_solution.c` - find two indices with sum t (Two Sum)
- `ex8/pointer_swap.c` and `ex8/pointer_swap_solution.c` - swap two integers using pointers
- `ex9/dynamic_array.c` and `ex9/dynamic_array_solution.c` - dynamic array allocation and modification
- `ex10/fibonacci.c` and `ex10/fibonacci_solution.c` - compute n-th Fibonacci number (iterative)
- `ex11/is_prime.c` and `ex11/is_prime_solution.c` - check if a number is prime
- `ex12/max_subarray.c` and `ex12/max_subarray_solution.c` - maximum subarray sum using Kadane's algorithm
- `ex13/string_reverse.c` and `ex13/string_reverse_solution.c` - reverse a string in-place
- `ex14/gcd.c` and `ex14/gcd_solution.c` - find greatest common divisor (Euclid's algorithm)
- `ex15/matrix_transpose.c` and `ex15/matrix_transpose_solution.c` - transpose a matrix with dynamic allocation
- `ex16/bubble_sort.c` and `ex16/bubble_sort_solution.c` - sort array using bubble sort algorithm
- `ex17/string_length.c` and `ex17/string_length_solution.c` - find longest and shortest string
- `ex18/bst.c` and `ex18/bst_solution.c` - binary search tree with insert and search operations
- `ex19/graph_dfs.c` and `ex19/graph_dfs_solution.c` - graph depth-first search (DFS) traversal
- `ex20/quick_sort.c` and `ex20/quick_sort_solution.c` - quicksort algorithm with partition

Each C file includes a comment at the top with the exercise title and difficulty (stars using `*`).

How to compile (PowerShell on Windows):

```
# compile an exercise (example: ex1 solution)
gcc "ex1/add_solution.c" -O2 -o "ex1\add_solution.exe"
& "ex1\add_solution.exe"
```

To compile all solutions at once (example):

```
gcc "ex1/add_solution.c" -O2 -o "ex1\add_solution.exe" ;
gcc "ex2/palindrome_solution.c" -O2 -o "ex2\palindrome_solution.exe" ;
gcc "ex3/selection_sort_solution.c" -O2 -o "ex3\selection_sort_solution.exe" ;
gcc "ex4/linked_list_reverse_solution.c" -O2 -o "ex4\linked_list_reverse_solution.exe" ;
gcc "ex5/inversion_count_solution.c" -O2 -o "ex5\inversion_count_solution.exe"
```

If `gcc` is not available on your system, install a C toolchain (e.g., MinGW-w64) or use WSL.
