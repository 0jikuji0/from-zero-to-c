# C Language Exercises

This workspace contains 5 C language exercises. Each exercise is in its own folder `exN`.

Structure for each exercise folder (topic-based filenames):

- `ex1/add.c` and `ex1/add_solution.c` - sum / add function
- `ex2/palindrome.c` and `ex2/palindrome_solution.c` - palindrome check
- `ex3/selection_sort.c` and `ex3/selection_sort_solution.c` - selection sort
- `ex4/linked_list_reverse.c` and `ex4/linked_list_reverse_solution.c` - linked list reversal
- `ex5/inversion_count.c` and `ex5/inversion_count_solution.c` - inversion counting
- `ex0/hello_world.c` and `ex0/hello_world_solution.c` - print "Hello, World!"
- `ex1/add.c` and `ex1/add_solution.c` - sum / add function
- `ex2/palindrome.c` and `ex2/palindrome_solution.c` - palindrome check
- `ex3/selection_sort.c` and `ex3/selection_sort_solution.c` - selection sort
- `ex4/linked_list_reverse.c` and `ex4/linked_list_reverse_solution.c` - linked list reversal
- `ex5/inversion_count.c` and `ex5/inversion_count_solution.c` - inversion counting
 - `ex6/...` (other exercises)
 - `ex8/prime_sieve.c` and `ex8/prime_sieve_solution.c` - count primes <= n (Sieve of Eratosthenes)
 - `ex9/two_sum.c` and `ex9/two_sum_solution.c` - find two indices with sum t (Two Sum)
 - `ex10/pointer_swap.c` and `ex10/pointer_swap_solution.c` - swap two integers using pointers
 - `ex11/dynamic_array.c` and `ex11/dynamic_array_solution.c` - dynamic array allocation and modification

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
