# 🗺️ City Navigation System (Graph Traversal in C++)

This project simulates a city navigation system using **graph theory** in C++. It allows users to define cities and roads (edges), then find paths between cities using **DFS** (depth-first search) and **BFS** (breadth-first search).

---

## 📌 Features

- Add cities dynamically
- Create roads (bidirectional edges)
- Display graph connections
- Search for paths using DFS (recursive)
- Search for shortest paths using BFS (queue-based)
- Console-based user interface
- Fully modular and extendable

---

## 💡 Core Concepts

- **Graph List (Adjacency List)** representation
- **Unweighted undirected graph**
- **BFS and DFS traversal**
- **Console-based interaction**

---

## 🛠️ Technologies Used

- Language: **C++**
- Data Structures: `unordered_map`, `vector`, `queue`
- Build System: Compile with `g++` or any standard C++ compiler

---

## 🚀 How to Compile and Run

### 🧱 Compile

```bash
g++ -std=c++11 -o city_navigator main.cpp
./city_navigator
CityNavigationSystem/
│
├── main.cpp        // Main logic file
├── README.md       // Project documentation
└── .gitignore      // Excludes build files (see below)

