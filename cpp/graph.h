#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <limits>

// Graph Class Declaration
class Graph {
private:
    std::unordered_map<int, std::vector<std::pair<int, double>>> adjList; // Adjacency list
    std::unordered_map<int, std::pair<double, double>> nodeCoordinates;  // Node coordinates

public:
    Graph();
    void addEdge(int u, int v, double weight);                            // Add edge
    void addNodeCoordinates(int node, double x, double y);               // Add node coordinates
    std::vector<int> aStar(int start, int goal) const;                   // A* algorithm
    void displayAdjList() const;                                         // Display adjacency list

    // Python-friendly functions
    std::vector<std::tuple<int, int, double>> aStarPathPy(int start, int goal) const;
    std::unordered_map<int, std::vector<std::pair<int, double>>> getAdjacencyListPy() const;
};

#endif
