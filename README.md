# NavGraph

NavGraph is a comprehensive project for managing, analyzing, and visualizing directed graphs. It includes a robust implementation in C++ for graph data management and pathfinding, combined with Python-based visualization using NetworkX and Matplotlib.

---

## Features

### C++ Implementation
- **Graph Operations**:
  - Add, remove nodes and edges
  - Save graph to a text file
- **A* Pathfinding Algorithm**:
  - Heuristic-based shortest path computation
- **Graph Statistics**:
  - Node and edge counts
  - Average edge weight
  - Graph density

### Python Visualization
- **Graph Loading**:
  - Reads the graph from the C++ output file
- **Visualization**:
  - Node and edge rendering
  - Displays edge weights and directed edges
  - Clean and customizable layout

---

## Installation

### Prerequisites
- C++17 or later
- Python 3.8 or later
- Required Python libraries:
  ```bash
  pip install networkx matplotlib
  ```

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/WasayJatt/Routing-system.git
   ```
2. Compile the C++ code:
   ```bash
   g++ -o NavGraph main.cpp -std=c++17
   ```
3. Run the Python script:
   ```bash
   python Graph_Visualizer.py
   ```

---

## Usage

### C++ Application
1. Execute the compiled C++ program:
   ```bash
   ./navgraph
   ```
2. Use the interactive menu to perform operations such as adding nodes, adding edges, removing edges, and finding paths.
3. Save the graph to a file for visualization.

### Python Visualization
1. Ensure the graph text file (e.g., `graph.txt`) is available.
2. Run the Python visualization script:
   ```bash
   python Graph_Visualizer.py
   ```
3. View the generated graph with nodes, edges, and weights.


---

## Examples

### C++ Application
Example graph operations:
- Adding nodes and edges
  ```
  Enter node ID: 1
  Enter label: Start
  Enter source node, destination node, and weight: 1 2 10
  ```
- Finding the shortest path using A*:
  ```
  Enter start node: 1
  Enter goal node: 5
  Shortest path from 1 to 5: 1 -> 2 -> 5
  ```

### Python Visualization
Example graph visualization:
![Graph Visualization](C:/Users/wasay/OneDrive/Documents/old_graph/plot2.png)

---

## License

This project is licensed under the MIT License. See `LICENSE` for more details.

---


## Contact

For questions or suggestions, feel free to reach out:
- **Author**: Abdul Wasay Ali Khaled
- **Email**: wasay@outlook.com
  