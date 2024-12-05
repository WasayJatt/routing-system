#include "graph.h"
#include <iostream>
#include <set>
#include <limits>
#include <queue>
#include <cmath>
#include <algorithm>

// Constructor
Graph::Graph() {}

// Add an edge to the adjacency list
void Graph::addEdge(int u, int v, double weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); // For undirected graphs
}

// Add coordinates for a node
void Graph::addNodeCoordinates(int node, double x, double y) {
    nodeCoordinates[node] = {x, y};
}

// Display the adjacency list
void Graph::displayAdjList() const {
    for (const auto& node : adjList) {
        std::cout << "Node " << node.first << ": ";
        for (const auto& neighbor : node.second) {
            std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Heuristic function: Euclidean distance
static double calculateHeuristic(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
}

// A* Algorithm
std::vector<int> Graph::aStar(int start, int goal) const {
    std::unordered_map<int, double> gScore, fScore;
    std::unordered_map<int, int> cameFrom;

    for (const auto& node : adjList) {
        gScore[node.first] = std::numeric_limits<double>::infinity();
        fScore[node.first] = std::numeric_limits<double>::infinity();
    }
    gScore[start] = 0;
    fScore[start] = calculateHeuristic(nodeCoordinates.at(start), nodeCoordinates.at(goal));

    auto cmp = [&fScore](int left, int right) {
        return fScore.at(left) > fScore.at(right);
    };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> openSet(cmp);
    openSet.push(start);

    while (!openSet.empty()) {
        int current = openSet.top();
        openSet.pop();

        if (current == goal) {
            // Reconstruct the path
            std::vector<int> path;
            while (cameFrom.find(current) != cameFrom.end()) {
                path.push_back(current);
                current = cameFrom[current];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : adjList.at(current)) {
            int neighborNode = neighbor.first;
            double tentativeGScore = gScore[current] + neighbor.second;

            if (tentativeGScore < gScore[neighborNode]) {
                cameFrom[neighborNode] = current;
                gScore[neighborNode] = tentativeGScore;
                fScore[neighborNode] = tentativeGScore + calculateHeuristic(nodeCoordinates.at(neighborNode), nodeCoordinates.at(goal));

                openSet.push(neighborNode);
            }
        }
    }
    return {}; // Return empty if no path found
}
