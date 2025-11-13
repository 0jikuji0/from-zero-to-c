# C# Language Exercises

This folder contains 5 C# exercises. Each exercise is in its own folder `exN` and contains a template exercise file and a solution file.

Structure for each exercise folder:

- `ex1/add.cs` and `ex1/add_solution.cs` - sum / add function
- `ex2/palindrome.cs` and `ex2/palindrome_solution.cs` - palindrome check
- `ex3/selection_sort.cs` and `ex3/selection_sort_solution.cs` - selection sort
- `ex4/linked_list_reverse.cs` and `ex4/linked_list_reverse_solution.cs` - linked list reversal
- `ex5/inversion_count.cs` and `ex5/inversion_count_solution.cs` - inversion counting

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
