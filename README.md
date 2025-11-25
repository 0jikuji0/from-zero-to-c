# From Zero to C - Programming Skill Tree

<div align="center">

![C Programming Badge](https://img.shields.io/badge/C-41_exercises-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++ Badge](https://img.shields.io/badge/C++-35_exercises-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![C# Badge](https://img.shields.io/badge/C%23-35_exercises-239120?style=for-the-badge&logo=csharp&logoColor=white)

**A systematic approach to mastering C, C++, and C# through hands-on coding exercises**

</div>

---

## 🎯 About This Skill Tree

C programming is fundamental to computer science. This Skill Tree presents a systematic approach to learning C language. Ideal for programming beginners, it offers a clear roadmap to understand **memory management**, **pointers**, and **system-level programming**. Hands-on, non-video courses and coding exercises in an interactive C language playground ensure you develop practical skills in writing efficient C programs.

**Key Features:**
- ✅ **111 total exercises** across C, C++, and C#
- ✅ **Parallel implementations** - same algorithms in different languages
- ✅ **Progressive difficulty** - from ⭐ beginner to ⭐⭐⭐⭐⭐⭐ expert level
- ✅ **Complete solutions** - every exercise includes template + full solution
- ✅ **Real-world algorithms** - competitive programming & industry-standard techniques

---

## 📊 Exercise Statistics

| Language | Exercises | Difficulty Range | Status |
|----------|-----------|------------------|--------|
| **C** | 41 | ⭐ to ⭐⭐⭐⭐⭐⭐ | ✅ Complete |
| **C++** | 35 | ⭐ to ⭐⭐⭐⭐⭐⭐ | ✅ Complete |
| **C#** | 35 | ⭐ to ⭐⭐⭐⭐⭐⭐ | ✅ Complete |

---

## 🗂️ Exercise Index

### 🟢 Beginner Level (⭐ - ⭐⭐)
**Index** | **Name** | **Level** | **Start**
---|---|---|---
01 | Building Flappy Bird Using C | ⭐⭐☆ | 🚀 [Start](C/ex0/)
02 | Making a Simple Calculator Using C | ⭐⭐☆ | 🚀 [Start](C/ex1/)
03 | Creating a Gomoku Game in C | ⭐⭐☆ | 🚀 [Start](C/ex2/)
04 | Creating a Snake Game in C | ⭐⭐☆ | 🚀 [Start](C/ex3/)
05 | File Type Statistics Using C | ⭐⭐☆ | 🚀 [Start](C/ex4/)

### 🟡 Intermediate Level (⭐⭐⭐)
**Index** | **Name** | **Level** | **Start**
---|---|---|---
06 | Typing Practice Program Using C | ⭐⭐⭐ | 🚀 [Start](C/ex5/)
07 | Creating a 2048 Game in C | ⭐⭐⭐ | 🚀 [Start](C/ex6/)
08 | Creating a Code Rain in C Using Ncurses | ⭐⭐⭐ | 🚀 [Start](C/ex7/)
09 | Creating a Simple Tic-Tac-Toe Game in C | ⭐⭐⭐ | 🚀 [Start](C/ex8/)
10 | Create a Simple Stopwatch App Using GTK | ⭐⭐⭐ | 🚀 [Start](C/ex9/)

### 🟠 Advanced Level (⭐⭐⭐⭐)
**Index** | **Name** | **Level** | **Start**
---|---|---|---
11 | Creating a Simple Clock Animation Using OpenGL | ⭐⭐⭐ | 🚀 [Start](C/ex10/)
12 | Creating a Dynamic Heart Animation With C | ⭐⭐⭐ | 🚀 [Start](C/ex11/)
13 | Implementing Callback Functions in C | ⭐⭐⭐ | 🚀 [Start](C/ex12/)
14 | Synchronize Multithreaded Printing with Mutex | ⭐⭐⭐ | 🚀 [Start](C/ex13/)

### 🔴 Expert Level (⭐⭐⭐⭐⭐)
**Index** | **Name** | **Level** | **Start**
---|---|---|---
15-25 | Data Structures & Algorithms | ⭐⭐⭐⭐⭐ | 🚀 [Start](C/ex15/)
26-35 | Graph Algorithms & Advanced Trees | ⭐⭐⭐⭐⭐ | 🚀 [Start](C/ex26/)
36-40 | Expert Algorithms & MST | ⭐⭐⭐⭐⭐ | 🚀 [Start](C/ex36/)

### 💎 Bonus Challenge (⭐⭐⭐⭐⭐⭐)
**Index** | **Name** | **Level** | **Project Link**
---|---|---|---
40 | **Suffix Array & LCP Array** | ⭐⭐⭐⭐⭐⭐ | 🚀 [Start](C/ex40/)

---

## 🚀 Repository Structure

```
from-zero-to-c/
│
├── C/                          # 41 C exercises
│   ├── ex0/ to ex40/
│   └── README.md
│
├── C++/                        # 35 C++ exercises
│   ├── ex0/ to ex34/
│   └── README.md
│
├── C#/                         # 35 C# exercises
│   ├── ex0/ to ex34/
│   └── README.md
│
└── README.md                   # This file
```

Each exercise folder contains:
- A **template file** with TODOs for you to complete
- A **solution file** with the full implementation

## 🛠️ Installation & Getting Started

### Prerequisites

**For C:**
```bash
# Install GCC (Linux/WSL)
sudo apt install gcc

# Install MinGW-w64 (Windows)
# Download from: https://www.mingw-w64.org/
```

**For C++:**
```bash
# Install G++ (Linux/WSL)
sudo apt install g++
```

**For C#:**
```bash
# Install .NET SDK (recommended)
# Download from: https://dotnet.microsoft.com/download

# Or install Mono
sudo apt install mono-mcs
```

### Running Your First Exercise

#### C Example:
```bash
cd C/ex1
gcc add_solution.c -o add_solution
./add_solution
```

#### C++ Example:
```bash
cd C++/ex1
g++ add_solution.cpp -std=c++17 -o add_solution
./add_solution
```

#### C# Example:
```bash
cd C#/ex1
dotnet run add_solution.cs
# OR with Mono:
mcs add_solution.cs -out:add_solution.exe
mono add_solution.exe
```

---

## 🎓 What You'll Learn

### C Programming
- ✅ Manual memory management (malloc/free)
- ✅ Pointer arithmetic and manipulation
- ✅ Struct-based data structures
- ✅ Low-level system programming
- ✅ Performance optimization

### C++ Programming
- ✅ STL containers (vector, map, set)
- ✅ Object-oriented programming
- ✅ RAII and smart pointers
- ✅ Templates and generic programming
- ✅ Modern C++17 features

### C# Programming
- ✅ Managed memory and garbage collection
- ✅ LINQ and functional programming
- ✅ Properties and interfaces
- ✅ Generic collections (List<T>, Dictionary<K,V>)
- ✅ .NET ecosystem integration

---

## 🔥 Featured Algorithms

### Graph Algorithms
- Depth-First Search (DFS)
- Dijkstra's Shortest Path
- Bellman-Ford (negative weights)
- Floyd-Warshall (all-pairs shortest path)
- Topological Sort
- Strongly Connected Components (Kosaraju)
- Maximum Flow (Ford-Fulkerson)
- Minimum Spanning Tree (Kruskal's & Prim's)

### String Algorithms
- Rabin-Karp (rolling hash)
- KMP String Matching
- **Suffix Array & LCP** (⭐⭐⭐⭐⭐⭐ bonus)

### Data Structures
- Binary Search Trees
- AVL Trees (self-balancing)
- Tries (prefix trees)
- Segment Trees
- Disjoint Set Union (Union-Find)
- Hash Tables
- LRU Cache

### Classic Algorithms
- Sorting (QuickSort, MergeSort, Bubble Sort)
- Kadane's Algorithm (max subarray)
- Sieve of Eratosthenes
- Huffman Coding
- Euclidean GCD

---

## 🎯 Difficulty Rating System

| Stars | Level | Description |
|-------|-------|-------------|
| ⭐ | Beginner | Basic syntax, simple logic |
| ⭐⭐ | Easy | Control flow, basic algorithms |
| ⭐⭐⭐ | Intermediate | Data structures, recursion |
| ⭐⭐⭐⭐ | Advanced | Complex algorithms, optimization |
| ⭐⭐⭐⭐⭐ | Expert | Competitive programming level |
| ⭐⭐⭐⭐⭐⭐ | **BONUS** | Research-level algorithms |

## 🤝 Contributing

This is a personal learning repository, but suggestions are welcome! If you find bugs or have ideas for new exercises:

1. Open an issue describing the problem/suggestion
2. Fork the repository
3. Create a feature branch with your changes
4. Submit a pull request

---

## 📜 License

This project is open source and available for educational purposes.

---

## 🌟 Support

If you find this repository useful, please consider giving it a ⭐ on GitHub! Your support helps other learners discover this resource.

---

## 🙏 Acknowledgments

Inspired by competitive programming platforms and computer science curricula worldwide. Special focus on:
- Classic algorithm textbooks (CLRS, Sedgewick)
- Competitive programming resources (Codeforces, LeetCode)
- System programming best practices

---

<div align="center">

**Happy Coding! 🚀**

Made with ❤️ for aspiring programmers

Repository owner: **jikuji**

</div>
