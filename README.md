# Urban Engine Flow

A high-performance graph analytics engine developed in **C++17** for transportation network analysis. The project models transportation systems as graph networks and applies classical graph algorithms to analyze routing efficiency, network capacity, and connectivity through a JSON-based input/output interface.

---

## 📌 Overview

Urban Engine Flow is designed to simulate and analyze transportation networks using graph theory. The application represents intersections as nodes and roads as edges, enabling efficient computation of shortest routes, maximum traffic flow, and network bottlenecks.

The project demonstrates the practical application of graph algorithms in solving real-world transportation and network optimization problems.

---

## 🎯 Key Highlights

- Developed a graph analytics engine in **C++17** for transportation network analysis.
- Implemented **Dijkstra's Shortest Path**, **Dinic's Maximum Flow**, and **Minimum Cut** algorithms.
- Designed a **JSON-based input/output pipeline** for flexible graph data processing.
- Built using an efficient **adjacency-list graph representation** and STL data structures.

---

## ✨ Features

- 🚗 Compute shortest routes using **Dijkstra's Algorithm**
- 🌊 Determine maximum network flow using **Dinic's Maximum Flow Algorithm**
- ✂️ Identify network bottlenecks using **Minimum Cut**
- 📄 JSON-based input and output processing
- 🛣️ Supports weighted directed and undirected graphs
- ⚡ Efficient adjacency-list graph representation
- 🧩 Modular and scalable implementation

---

## 🧠 Algorithms Implemented

| Algorithm | Purpose | Time Complexity |
|-----------|---------|-----------------|
| Dijkstra's Algorithm | Shortest Path | **O((V + E) log V)** |
| Dinic's Algorithm | Maximum Flow | **O(V²E)** |
| Minimum Cut | Network Bottleneck Detection | **O(V²E)** |

---

## 📂 Project Structure

```text
Urban-Engine-Flow/
│
├── include/
│   └── json.hpp
│
├── src/
│   └── main.cpp
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## 📥 Input Format

The program accepts graph data in **JSON** format.

Example:

```json
{
  "algorithm": "dijkstra",
  "num_nodes": 5,
  "source": 0,
  "target": 4,
  "edges": [
    {
      "from": 0,
      "to": 1,
      "weight": 2
    },
    {
      "from": 1,
      "to": 2,
      "weight": 3
    },
    {
      "from": 2,
      "to": 4,
      "weight": 1
    },
    {
      "from": 0,
      "to": 3,
      "weight": 4
    },
    {
      "from": 3,
      "to": 4,
      "weight": 2
    }
  ]
}
```

---

## 📤 Sample Output

Example output for Dijkstra's Algorithm:

```json
{
  "algorithm": "dijkstra",
  "found": true,
  "distance": 6,
  "path": [0, 1, 2, 4]
}
```

---

## 🛠 Technologies Used

- C++17
- Standard Template Library (STL)
- nlohmann/json
- Graph Algorithms
- Priority Queue
- Breadth First Search (BFS)
- Depth First Search (DFS)

---

## 🚀 Build

Compile the project using:

```bash
g++ -std=c++17 -Iinclude src/main.cpp -o UrbanEngineFlow
```

---

## ▶️ Run

Run the executable by providing a JSON input file:

```bash
./UrbanEngineFlow < your_input_file.json
```

---

## 📊 Applications

- Transportation Network Analysis
- Route Planning
- Road Network Optimization
- Traffic Flow Analysis
- Network Capacity Planning
- Graph Algorithm Research and Education

---

## 🔮 Future Enhancements

- Bellman-Ford Algorithm
- Floyd-Warshall Algorithm
- A* Search Algorithm
- Interactive Graph Visualization
- GUI-based Network Simulator
- Performance Benchmarking

---

## 👨‍💻 Author

**Shailendra Kumar Meena**

---

## 📝 Note

This project is intended for educational and research purposes to demonstrate graph algorithm implementation and transportation network analysis using C++.

---

## 📄 License

This project is licensed under the MIT License.
