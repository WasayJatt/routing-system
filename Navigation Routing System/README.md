# Navigation Routing System

## Description

The **Navigation Routing System** is designed to provide an efficient route-finding solution using the A* algorithm for pathfinding in a graph. This system leverages both C++ for computational efficiency and Python for high-level scripting and visualization. The core components include:

* **Graph Class**: Implements graph data structures and pathfinding algorithms.
* **A* Algorithm**: Finds the shortest path between two nodes using the Euclidean distance as a heuristic.
* **Pybind11 Integration**: Provides Python bindings for the graph class, allowing the use of C++ algorithms in Python scripts.
* **Visualization**: Utilizes Python’s `matplotlib` and `networkx` libraries to visualize graphs and the shortest path.

## Features

* Graph construction with nodes and edges.
* A* algorithm for pathfinding between two nodes.
* Visual representation of the graph and shortest path.
* Python bindings for C++ graph implementation using pybind11.
* Flexible to handle undirected weighted graphs and coordinates for heuristic-based search.

## Setup and Installation

### Prerequisites

* **CMake** version 3.10 or higher
* **Python** 3.x
* **pybind11** library for Python bindings
* **matplotlib** and **networkx** for visualization (Python)

## Installation Steps

### 1. Install CMake (if not already installed)

You can install CMake using the following commands:

For Ubuntu/Debian:
```bash
sudo apt-get install cmake
