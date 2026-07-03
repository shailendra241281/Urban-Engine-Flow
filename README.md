# Urban Engine Flow

A high-performance graph analytics engine developed in **C++** for transportation network analysis. The project models urban transportation systems as graph networks and applies classical graph algorithms to analyze routing efficiency, network capacity, and connectivity through a JSON-based input/output interface.

---

## 📌 Overview

Urban Engine Flow is designed to simulate and analyze transportation networks using graph theory. The application represents intersections as nodes and roads as edges, enabling efficient computation of shortest routes, maximum traffic flow, and network bottlenecks.

The project demonstrates the practical application of graph algorithms in solving real-world transportation and network optimization problems.

---

## ✨ Features

- 🚗 Compute shortest routes using **Dijkstra's Algorithm**
- 🌊 Determine maximum traffic capacity using **Dinic's Maximum Flow Algorithm**
- ✂️ Identify network bottlenecks using **Minimum Cut**
- 📄 JSON-based input and output processing
- 🛣️ Supports weighted graphs
- 🔄 Supports directed and undirected edges
- ⚡ Efficient adjacency-list graph representation

---

## 🧠 Algorithms Implemented

### 1. Dijkstra's Shortest Path

Finds the shortest path between a source and destination node in a weighted graph.

**Time Complexity**

```
O((V + E) log V)
```

---

### 2. Dinic's Maximum Flow

Computes the maximum possible flow between a source and sink using level graphs and blocking flows.

**Time Complexity**

```
O(V²E)
```

---

### 3. Minimum Cut

Determines the minimum set of edges whose removal disconnects the source from the destination.

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

The program accepts JSON input describing the graph.

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

## 📤 Output

The program returns results in JSON format.

Example (Dijkstra):

```json
{
  "algorithm": "dijkstra",
  "found": true,
  "distance": 6,
  "path": [0,1,2,4]
}
```

---

## 🛠 Technologies Used

- C++17
- Standard Template Library (STL)
- nlohmann/json
- Graph Theory
- Priority Queue
- Breadth First Search (BFS)
- Depth First Search (DFS)

---

## 🚀 Build

Compile using:

```bash
g++ -std=c++17 src/main.cpp -o UrbanEngineFlow
```

---

## ▶️ Run

```bash
./UrbanEngineFlow < input.json
```

---

## 📊 Applications

- Transportation Network Analysis
- Route Planning
- Road Network Optimization
- Traffic Flow Analysis
- Network Capacity Planning
- Graph Algorithm Education

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

## 📄 License

This project is licensed under the MIT License.
