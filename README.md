<div align="center">

# DSA-CPP

### Daily Data Structures & Algorithms practice in C++ — every approach, not just the answer.

![C++](https://img.shields.io/badge/C%2B%2B-STL-00599C?logo=cplusplus&logoColor=white)
![Problems Solved](https://img.shields.io/badge/Problems%20Solved-300%2B-success)
![Daily Practice](https://img.shields.io/badge/Consistent%20Practice-85%2B%20days-orange)
![Last Commit](https://img.shields.io/github/last-commit/harshiljain2911/DSA-CPP)

</div>

---

**300+ C++ solutions across 85+ days of consistent daily practice**, organized day
by day and indexed by topic — from arrays and sliding window through linked lists,
trees, graphs, and a deep dynamic-programming track.

## Repository Highlights

- 🔁 **Brute → Better → Optimal** — most problems are solved in multiple
  approaches, kept side by side so the optimization path stays visible.
- 🧠 **Three formulations per DP problem** — memoization, tabulation, and
  space-optimisation written as separate solutions, not one merged answer.
- 📅 **Daily consistency** — one focused session per day, logged as `Day_N`,
  for 85+ days and counting.
- 🗂️ **Topic-wise organization** — a full navigation index maps every topic to
  its practice days and representative problems.
- 🧪 **Two formats per problem where useful** — LeetCode submission format plus
  a standalone locally-runnable version for debugging.

## Purpose

To master the data structures and algorithms expected in software-engineering
interviews — in C++ with STL — to the point where I can:

1. Recognize the underlying pattern of an unseen problem.
2. State the brute-force solution and its complexity immediately.
3. Derive the optimal approach and justify its time/space trade-offs.

This repository is the working record of that process, and my revision reference
before contests and interviews.

## Repository Structure

```
DSA-CPP/
├── Day_1/                  ← one folder per practice day
│   ├── LCtwosum.cpp        ← LC prefix: LeetCode submission format
│   ├── VStwosum.cpp        ← VS prefix: standalone version, runs locally
│   └── readme.md           ← occasional day notes
├── Day_2/
├── ...
└── Day_N/                  ← latest practice day
```

| Naming convention | Meaning |
| :--- | :--- |
| `LC*.cpp` / `VS*.cpp` | LeetCode submission format / locally runnable with `main()` |
| `*BRUTE` / `*BETTER` / `*BEST` | multiple approaches to the same problem |
| `*_memoized` / `*_tabulation` / `*_space_optimised` | the three classic DP formulations |

## Topic-wise Navigation

| Topic | Where | Representative problems |
| :--- | :--- | :--- |
| Arrays & STL basics | [Day 1](Day_1) – 8 | Two Sum · Remove Duplicates · Move Zeroes |
| Strings | [Day 10](Day_10) – 12, 29 – 30, 35 – 36 | Valid Anagram · Longest Common Prefix · atoi |
| Sliding Window & Prefix Sum | [Day 13](Day_13) – 18, 31 – 33, 37 | Longest Substring w/o Repeating · Subarray Sum = K |
| Two Pointers | [Day 19](Day_19) – 20, 42 | Two Sum II · 3Sum · 4Sum |
| Stacks & Monotonic Stack | [Day 21](Day_21) – 23, 34 – 35 | Largest Rectangle · Next Greater Element · Remove K Digits |
| Binary Search | [Day 24](Day_24) – 25, 28, 42 | Rotated Sorted Array · Peak Element · Koko Eating Bananas |
| Linked Lists | [Day 38](Day_38) – 40 | Reverse LL · Detect Cycle · Sort LL · Add Two Numbers |
| Greedy | [Day 41](Day_41) – 42, 65, 72 | Jump Game I/II · Candy · Lemonade Change |
| Binary Trees | [Day 45](Day_45) – 49, 65 | Traversals (recursive + iterative) · Diameter · Max Path Sum |
| Binary Search Trees | [Day 50](Day_50) – 52 | Validate BST · LCA · BST Iterator · Recover BST |
| Graphs — BFS/DFS | [Day 43](Day_43) – 44, 53 – 55 | Rotting Oranges · Course Schedule I/II · Alien Dictionary |
| Graphs — Shortest Paths & DSU | [Day 56](Day_56) – 60, 83, 85 | Dijkstra · Bellman-Ford · Accounts Merge · Islands II |
| Bit Manipulation & Math | [Day 61](Day_61), 88 – 89 | Count Primes · Divide Two Integers · GCD problems |
| Dynamic Programming | [Day 62](Day_62) – 87 | Coin Change I/II · LCS · Edit Distance · Wildcard Matching · Stock Buy & Sell II–IV |

## Progress Tracker

**300+ solutions · 85+ practice days · updated daily**

- [x] Arrays, Hashing & STL
- [x] Strings
- [x] Sliding Window & Prefix Sum
- [x] Two Pointers
- [x] Stacks & Monotonic Stack
- [x] Binary Search
- [x] Greedy
- [x] Linked Lists
- [x] Binary Trees & BSTs
- [x] Graphs — BFS/DFS, Topological Sort, Dijkstra, Bellman-Ford, DSU
- [x] Bit Manipulation
- [x] Dynamic Programming — 1-D, grid, subset/knapsack, strings, stocks
- [ ] Heaps & Priority Queues
- [ ] Tries
- [ ] Backtracking (beyond subsets/parentheses)
- [ ] Segment Trees & advanced structures

## Complexity Notation Legend

| Notation | Name | Intuition |
| :--- | :--- | :--- |
| O(1) | Constant | same cost regardless of input size |
| O(log n) | Logarithmic | halves the search space each step |
| O(n) | Linear | touches each element once |
| O(n log n) | Linearithmic | efficient sorting, divide & conquer |
| O(n²) | Quadratic | nested loops over the input |
| O(2ⁿ) | Exponential | explores every subset |

Where a problem has multiple solution files, they are ordered by decreasing
complexity — the brute-force file shows the idea, the optimal file the best bound.

## Study Strategy

1. **Understand before optimizing** — the naive solution is written first;
   optimization is a refinement, not a leap.
2. **Convert, don't memorize, DP** — writing memoization, tabulation, and
   space-optimisation separately internalizes the transformation between them.
3. **Spaced revision** — dedicated revision days revisit earlier topics after a gap.
4. **Debug locally, submit clean** — standalone `main()` versions for
   experimenting, LeetCode-format files for the final submission.

## Resources

- [LeetCode](https://leetcode.com) — primary problem source
- [cppreference](https://en.cppreference.com) — STL containers & algorithms reference
