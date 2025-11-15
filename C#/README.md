# C# Language Exercises

This folder contains 22 C# exercises. Each exercise is in its own folder `exN` and contains a template exercise file and a solution file.

Structure for each exercise folder:

- `ex0/hello_world.cs` and `ex0/hello_world_solution.cs` - print "Hello, World!"
- `ex1/add.cs` and `ex1/add_solution.cs` - sum / add function
- `ex2/palindrome.cs` and `ex2/palindrome_solution.cs` - palindrome check
- `ex3/selection_sort.cs` and `ex3/selection_sort_solution.cs` - selection sort
- `ex4/linked_list_reverse.cs` and `ex4/linked_list_reverse_solution.cs` - linked list reversal
- `ex5/inversion_count.cs` and `ex5/inversion_count_solution.cs` - inversion counting
- `ex6/longest_increasing_subsequence.cs` and `ex6/longest_increasing_subsequence_solution.cs` - longest increasing subsequence (LIS)
- `ex7/reference_swap.cs` and `ex7/reference_swap_solution.cs` - swap two integers using `ref` parameters
- `ex8/list_modify.cs` and `ex8/list_modify_solution.cs` - modify a List element at a given index
- `ex9/fibonacci.cs` and `ex9/fibonacci_solution.cs` - compute n-th Fibonacci number (iterative)
- `ex10/is_prime.cs` and `ex10/is_prime_solution.cs` - check if a number is prime
- `ex11/max_subarray.cs` and `ex11/max_subarray_solution.cs` - maximum subarray sum using Kadane's algorithm
- `ex12/string_reverse.cs` and `ex12/string_reverse_solution.cs` - reverse a string using LINQ
- `ex13/gcd.cs` and `ex13/gcd_solution.cs` - find greatest common divisor
- `ex14/matrix_transpose.cs` and `ex14/matrix_transpose_solution.cs` - transpose a matrix using List of Lists
- `ex15/bubble_sort.cs` and `ex15/bubble_sort_solution.cs` - sort list using bubble sort algorithm
- `ex16/string_length.cs` and `ex16/string_length_solution.cs` - find longest and shortest string
- `ex17/bst.cs` and `ex17/bst_solution.cs` - binary search tree with insert and search operations
- `ex18/graph_dfs.cs` and `ex18/graph_dfs_solution.cs` - graph depth-first search (DFS) traversal
- `ex19/quick_sort.cs` and `ex19/quick_sort_solution.cs` - quicksort algorithm with partition
- `ex20/postfix_eval.cs` and `ex20/postfix_eval_solution.cs` - postfix expression evaluation using stack
- `ex21/merge_sort.cs` and `ex21/merge_sort_solution.cs` - merge sort algorithm

How to compile (Mono):

```
# compile (example: ex1 solution)
mcs -out:ex1/add_solution.exe "ex1/add_solution.cs"
mono ex1/add_solution.exe
```

How to run using `dotnet` (create a quick project):

```
# from the C# folder
mkdir tmpproj && cd tmpproj
dotnet new console --language C# --output . --no-restore
# replace Program.cs with the desired solution file content, then:
dotnet run
```

If you want, I can also add small test inputs or a script to build/run all solutions.
