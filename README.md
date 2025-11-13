# from-zero-to-c

This repository contains small programming exercises to learn C and its
variants (C++ and C#). Each exercise aims to be a short, self-contained
problem suitable for practice and teaching.

Overview
- Exercises are organized under three language folders: `C/`, `C++/`, and
  `C#/`.
- Each exercise lives in a folder `exN/` and typically includes two files:
  a template (the exercise) and a corresponding solution file.

Purpose
- Provide a collection of basic algorithmic and data-structure exercises
  (sorting, palindrome checks, linked list operations, inversion counting,
  longest increasing subsequence, prime sieve, etc.) for practice and study.

Repository structure
- `C/`    — C language exercises
- `C++/`  — same exercises in C++
- `C#/`   — same exercises in C#

Each language folder contains subfolders `ex1/`, `ex2/`, ... where each
`exN/` includes an exercise template and a solution file.

Example exercises included
- Hello World
- Add two integers
- Palindrome check
- Selection sort
- Linked list reversal
- Inversion count
- Longest Increasing Subsequence (C++)
- Prime sieve (C)
- Two Sum (C)
- Binary search (C++)

How to compile and run

C (gcc):
```bash
gcc -std=c11 -O2 C/ex1/add_solution.c -o C/ex1/add_solution
printf "2 3\n" | C/ex1/add_solution
```

C++ (g++):
```bash
g++ -std=c++17 -O2 C++/ex1/add_solution.cpp -o C++/ex1/add_solution
printf "2 3\n" | C++/ex1/add_solution
```

C# (Mono):
```bash
mcs -out:C#/ex1/add_solution.exe C#/ex1/add_solution.cs
mono C#/ex1/add_solution.exe
```

Or using .NET SDK (dotnet):
```bash
cd C#/ex1
dotnet new console -o tmp --no-restore --language C#
# replace Program.cs with the desired solution file content
dotnet run --project tmp
```

Contributing
- Add exercises by creating a new `exN/` folder containing a template and a
  solution file. Follow the input/output conventions used in existing
  exercises to make automated testing easier.
- Open a pull request describing the exercise and its complexity.

Notes
- Some environments may not have `mcs`/`mono` installed; in that case use
  the `dotnet` SDK if available.
- Solutions are intended to be clear and educational rather than optimized
  for every possible edge case.

Support
- If you find this repository useful, please consider giving it a star (**) on GitHub!
  Your support helps us continue improving the exercises and adding new content.
- Stars also help other learners discover this resource.

Contact
- Repository owner: jikuji</>
