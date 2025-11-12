# C++ Language Exercises

This folder contains 5 C++ exercises. Each exercise is in its own folder `exN`.

Structure for each exercise folder (topic-based filenames):

- `ex1/add.cpp` and `ex1/add_solution.cpp` - sum / add function
- `ex2/palindrome.cpp` and `ex2/palindrome_solution.cpp` - palindrome check
- `ex3/selection_sort.cpp` and `ex3/selection_sort_solution.cpp` - selection sort
- `ex4/linked_list_reverse.cpp` and `ex4/linked_list_reverse_solution.cpp` - linked list reversal
- `ex5/inversion_count.cpp` and `ex5/inversion_count_solution.cpp` - inversion counting

Each C++ file includes a comment at the top with the exercise title and difficulty (stars using `*`).

How to compile (PowerShell on Windows):

```
# compile an exercise (example: ex1 solution)
g++ "ex1/add_solution.cpp" -O2 -std=c++17 -o "ex1\add_solution.exe"
& "ex1\add_solution.exe"
```

If `g++` is not available on your system, install MinGW-w64 or use WSL.
