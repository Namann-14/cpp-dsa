<div align="center">

# 🚀 C++ Data Structures & Algorithms

### *A comprehensive collection of DSA implementations, competitive programming solutions, and interview preparation materials*

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](https://www.java.com/)
[![Algorithm](https://img.shields.io/badge/Algorithm-FF6B6B?style=for-the-badge&logo=thealgorithms&logoColor=white)](https://github.com/Namann-14/cpp-dsa)

<br/>

[![GitHub stars](https://img.shields.io/github/stars/Namann-14/cpp-dsa?style=social)](https://github.com/Namann-14/cpp-dsa/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/Namann-14/cpp-dsa?style=social)](https://github.com/Namann-14/cpp-dsa/network/members)
[![GitHub issues](https://img.shields.io/github/issues/Namann-14/cpp-dsa)](https://github.com/Namann-14/cpp-dsa/issues)
[![GitHub pull requests](https://img.shields.io/github/issues-pr/Namann-14/cpp-dsa)](https://github.com/Namann-14/cpp-dsa/pulls)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Contributions Welcome](https://img.shields.io/badge/Contributions-Welcome-brightgreen.svg?style=flat)](https://github.com/Namann-14/cpp-dsa/issues)

<br/>

<p align="center">
  <b>⭐ If you find this repository helpful, please consider giving it a star! ⭐</b>
</p>

---

</div>

## 📋 Table of Contents

- [🧠 Features](#-features)
- [📦 Tech Stack](#-tech-stack)
- [🗂️ Folder Structure](#️-folder-structure)
- [🛠 Installation & Setup](#-installation--setup)
- [🚀 Running the Code](#-running-the-code)
- [📚 Topics Covered](#-topics-covered)
- [🛣 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [⭐ Support](#-support)
- [📝 License](#-license)

---

## 🧠 Features

<div align="center">

| Feature | Description |
|---------|-------------|
| 📊 **40+ DP Problems** | Complete Dynamic Programming solutions with detailed explanations |
| 🔗 **Graph Algorithms** | BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Kruskal's, Prim's & more |
| 🌳 **Tree Structures** | Binary Trees, BST, Traversals, and tree-based problems |
| 🔄 **Sorting Algorithms** | Bubble, Selection, Insertion, Merge, Quick Sort implementations |
| 🧩 **Backtracking** | N-Queens, Sudoku Solver, Rat in a Maze |
| 🏆 **Competitive Programming** | Codeforces solutions organized by difficulty |
| 📝 **OOP Concepts** | Object-Oriented Programming implementations in C++ |
| 🔍 **Binary Search** | Comprehensive binary search patterns and variations |

</div>

---

## 📦 Tech Stack

<div align="center">

![C++](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![VSCode](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)

</div>

**Languages:**
- **C++17** - Primary language for DSA implementations
- **Java** - Alternative implementations for select problems

**Tools & Environment:**
- **G++ Compiler** (MinGW/MSYS2 on Windows)
- **Visual Studio Code** with C++ extensions
- **Git** for version control

---

## 🗂️ Folder Structure

```
cpp-dsa/
│
├── 📁 Backtracking/
│   ├── N Queens/
│   ├── Rat In A Maze/
│   └── Sudoku Solver/
│
├── 📁 Binary Trees/
│   └── main code/
│
├── 📁 C++ DSA/
│   ├── 2D array/
│   ├── Binary Search/
│   ├── Math DSA/
│   ├── OOPS/
│   ├── Pointers/
│   ├── Sorting/
│   └── Strings/
│
├── 📁 Codeforces/
│   ├── A/ (Easy)
│   ├── B/ (Medium)
│   ├── C/ (Hard)
│   └── D/ (Expert)
│
├── 📁 Dynamic Programming/
│   ├── 0-1 Knapsack Problem/
│   ├── Coin Change/
│   ├── Climbing Stairs/
│   ├── Best Time to Buy and Sell Stock (I-IV)/
│   ├── Longest Common Subsequence/
│   ├── Longest Increasing Subsequence/
│   ├── Edit Distance/
│   └── ... (40+ problems)
│
├── 📁 Graphs/
│   ├── BFS (Breadth First Search)/
│   ├── DFS (Depth First Search)/
│   ├── Dijkstra's Algorithm/
│   ├── Bellman Ford Algorithm/
│   ├── Floyd Warshall Algorithm/
│   ├── Kruskal's Algorithm/
│   ├── Prim's Algorithm/
│   ├── Kosaraju's Algorithm/
│   └── ... (15+ algorithms)
│
├── 📁 Hashmap/
├── 📁 Heaps (Priority Queue)/
├── 📁 Linked List/
├── 📁 Recursion/
├── 📁 Stack/
├── 📁 Striver/
├── 📁 Tries/
│
└── 📄 README.md
```

---

## 🛠 Installation & Setup

### Prerequisites

Make sure you have the following installed on your system:

- **G++ Compiler** (C++17 or later)
- **Git**
- **Visual Studio Code** (recommended)

### Step-by-Step Installation

**1. Clone the repository**

```bash
git clone https://github.com/Namann-14/cpp-dsa.git
```

**2. Navigate to the project directory**

```bash
cd cpp-dsa
```

**3. Open in VS Code (recommended)**

```bash
code .
```

### Windows Setup (MSYS2/MinGW)

If you don't have G++ installed on Windows:

```bash
# Install MSYS2 from https://www.msys2.org/
# Then run in MSYS2 terminal:
pacman -S mingw-w64-ucrt-x86_64-gcc
```

---

## 🚀 Running the Code

### Method 1: Command Line

```bash
# Navigate to the specific problem folder
cd "Dynamic Programming/Coin Change"

# Compile the C++ file
g++ -std=c++17 -o solution main.cpp

# Run the executable
./solution        # Linux/Mac
.\solution.exe    # Windows
```

### Method 2: VS Code Task (Recommended)

1. Open any `.cpp` file
2. Press `Ctrl + Shift + B` to build
3. Press `F5` to run with debugging

### Method 3: Single Command

```bash
# Compile and run in one command (Linux/Mac)
g++ -std=c++17 -o output main.cpp && ./output

# Windows PowerShell
g++ -std=c++17 -o output main.cpp; .\output.exe
```

---

## 📚 Topics Covered

<details>
<summary><b>🔄 Dynamic Programming (40+ Problems)</b></summary>

| Problem | Difficulty | Status |
|---------|------------|--------|
| Fibonacci | 🟢 Easy | ✅ |
| Climbing Stairs | 🟢 Easy | ✅ |
| Coin Change | 🟡 Medium | ✅ |
| 0/1 Knapsack | 🟡 Medium | ✅ |
| Longest Common Subsequence | 🟡 Medium | ✅ |
| Longest Increasing Subsequence | 🟡 Medium | ✅ |
| Edit Distance | 🟡 Medium | ✅ |
| Best Time to Buy and Sell Stock (I-IV) | 🟡 Medium | ✅ |
| Partition Equal Subset Sum | 🟡 Medium | ✅ |
| Perfect Squares | 🟡 Medium | ✅ |
| Unique Binary Search Trees | 🟡 Medium | ✅ |
| House Robbery Problem | 🟡 Medium | ✅ |
| Russian Doll Envelopes | 🔴 Hard | ✅ |
| Pizza With 3n Slices | 🔴 Hard | ✅ |
| Maximum Height By Stacking Cuboids | 🔴 Hard | ✅ |
| And many more... | | |

</details>

<details>
<summary><b>🔗 Graph Algorithms (15+ Algorithms)</b></summary>

| Algorithm | Type | Status |
|-----------|------|--------|
| BFS (Breadth First Search) | Traversal | ✅ |
| DFS (Depth First Search) | Traversal | ✅ |
| Dijkstra's Algorithm | Shortest Path | ✅ |
| Bellman-Ford Algorithm | Shortest Path | ✅ |
| Floyd-Warshall Algorithm | All Pairs Shortest Path | ✅ |
| Kruskal's Algorithm | MST | ✅ |
| Prim's Algorithm | MST | ✅ |
| Kosaraju's Algorithm | Strongly Connected Components | ✅ |
| Cycle Detection (Directed) | Utility | ✅ |
| Cycle Detection (Undirected) | Utility | ✅ |
| Topological Sort | DAG | ✅ |
| Flood Fill | Grid | ✅ |
| Bridges in Graph | Advanced | ✅ |
| Articulation Points | Advanced | ✅ |
| Negative Weight Cycle | Detection | ✅ |

</details>

<details>
<summary><b>🌳 Trees & Binary Search</b></summary>

- Binary Tree Traversals (Inorder, Preorder, Postorder)
- Binary Search variations
- BST operations
- Tree construction from traversals

</details>

<details>
<summary><b>🧩 Backtracking</b></summary>

- N-Queens Problem
- Sudoku Solver
- Rat in a Maze
- Combination/Permutation problems

</details>

<details>
<summary><b>📊 Sorting Algorithms</b></summary>

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

</details>

<details>
<summary><b>🏆 Competitive Programming (Codeforces)</b></summary>

Solutions organized by difficulty:
- **Division A** - Easy problems
- **Division B** - Medium problems
- **Division C** - Hard problems
- **Division D** - Expert problems

</details>

---

## 🛣 Roadmap

### Completed ✅
- [x] Dynamic Programming (40+ problems)
- [x] Graph Algorithms (15+ algorithms)
- [x] Backtracking Problems
- [x] Sorting Algorithms
- [x] Binary Search Patterns
- [x] OOP Concepts in C++
- [x] Codeforces Problems

### In Progress 🚧
- [ ] Segment Trees & Fenwick Trees
- [ ] Advanced String Algorithms (KMP, Z-Algorithm, Rabin-Karp)
- [ ] More Codeforces Problems
- [ ] Detailed problem explanations and comments

### Planned 📋
- [ ] Video explanations for complex problems
- [ ] Time & Space complexity analysis for each solution
- [ ] Multiple approaches for each problem
- [ ] Interview preparation guide
- [ ] LeetCode problem solutions (organized by company tags)

---

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**!

### How to Contribute

1. **Fork the Project**
   ```bash
   # Click the 'Fork' button at the top right of this page
   ```

2. **Clone your Fork**
   ```bash
   git clone https://github.com/YOUR_USERNAME/cpp-dsa.git
   ```

3. **Create your Feature Branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

4. **Add your Changes**
   ```bash
   git add .
   ```

5. **Commit your Changes**
   ```bash
   git commit -m "Add: Solution for Problem XYZ"
   ```

6. **Push to the Branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

7. **Open a Pull Request**

### Contribution Guidelines

- 📝 Add comments explaining the approach
- 🏷️ Follow the existing folder structure
- ✅ Test your code before submitting
- 📊 Include time and space complexity if possible
- 🔗 Add problem links in comments

### What You Can Contribute

- 🆕 New problem solutions
- 🐛 Bug fixes in existing solutions
- 📖 Documentation improvements
- ⚡ Code optimizations
- 🧪 Alternative approaches

---

## ⭐ Support

<div align="center">

### If this repository helped you in your DSA journey, please consider:

[![Star this repo](https://img.shields.io/badge/⭐_Star_this_repo-yellow?style=for-the-badge)](https://github.com/Namann-14/cpp-dsa)
[![Fork this repo](https://img.shields.io/badge/🍴_Fork_this_repo-blue?style=for-the-badge)](https://github.com/Namann-14/cpp-dsa/fork)
[![Follow](https://img.shields.io/badge/👤_Follow_@Namann--14-black?style=for-the-badge&logo=github)](https://github.com/Namann-14)

<br/>

**Your support motivates me to keep improving this repository!**

⭐ **Star** = Bookmark for later  
🍴 **Fork** = Create your own copy  
👤 **Follow** = Stay updated with my projects

</div>

---

## 📝 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2024 Naman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
```

---

<div align="center">

### Made with ❤️ by [Naman](https://github.com/Namann-14)

<br/>

**Happy Coding! 🚀**

<br/>

[![GitHub](https://img.shields.io/badge/GitHub-Namann--14-181717?style=for-the-badge&logo=github)](https://github.com/Namann-14)

---

<sub>If you found this helpful, don't forget to ⭐ star the repository!</sub>

</div>
