#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <algorithm>
#include <tuple>

class Graph {
public:
    Graph(int n);

    void addEdge(int u, int v, double weight);
    std::vector<int> aStar(int start, int goal) const;
    void addNodeCoordinates(int node, double x, double y);
    void displayAdjList() const;

private:
    int nodes;
    std::unordered_map<int, std::vector<std::pair<int, double>>> adjList;
    std::unordered_map<int, std::pair<double, double>> nodeCoordinates;  // Node coordinates for heuristic

    double heuristic(int node, int goal) const;  // Heuristic function
};

Graph::Graph(int n) : nodes(n) {}

void Graph::addEdge(int u, int v, double weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); // Assuming an undirected graph
}

void Graph::addNodeCoordinates(int node, double x, double y) {
    nodeCoordinates[node] = {x, y};
}

double Graph::heuristic(int node, int goal) const {
    double dx = nodeCoordinates.at(node).first - nodeCoordinates.at(goal).first;
    double dy = nodeCoordinates.at(node).second - nodeCoordinates.at(goal).second;
    return std::sqrt(dx * dx + dy * dy);
}

void Graph::displayAdjList() const {
    for (const auto& [node, neighbors] : adjList) {
        std::cout << node << ": ";
        for (const auto& [neighbor, weight] : neighbors) {
            std::cout << "(" << neighbor << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Graph::aStar(int start, int goal) const {
    std::unordered_map<int, double> gScore, fScore;
    std::unordered_map<int, int> cameFrom;
    for (int i = 0; i < nodes; ++i) {
        gScore[i] = std::numeric_limits<double>::infinity();
        fScore[i] = std::numeric_limits<double>::infinity();
    }
    gScore[start] = 0;
    fScore[start] = heuristic(start, goal);

    auto cmp = [&fScore](int left, int right) { return fScore[left] > fScore[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> openSet(cmp);
    openSet.push(start);

    while (!openSet.empty()) {
        int current = openSet.top();
        openSet.pop();

        if (current == goal) {
            std::vector<int> path;
            for (int node = goal; node != start; node = cameFrom[node]) {
                path.push_back(node);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (auto &[neighbor, weight] : adjList.at(current)) {
            double tentative_gScore = gScore[current] + weight;
            if (tentative_gScore < gScore[neighbor]) {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, goal);
                openSet.push(neighbor);
            }
        }
    }
    return {}; // Return an empty path if no route exists
}

int main() {
    Graph g(6);  // Assuming 6 nodes

    g.addEdge(0, 1, 1.0);
    g.addEdge(1, 2, 2.5);
    g.addEdge(2, 3, 1.2);
    g.addEdge(3, 4, 3.0);
    g.addEdge(4, 5, 2.3);
    g.addEdge(0, 5, 10.0);

    g.addNodeCoordinates(0, 0.0, 0.0);
    g.addNodeCoordinates(1, 1.0, 0.0);
    g.addNodeCoordinates(2, 2.0, 0.0);
    g.addNodeCoordinates(3, 3.0, 0.0);
    g.addNodeCoordinates(4, 4.0, 0.0);
    g.addNodeCoordinates(5, 5.0, 0.0);

    std::cout << "Graph adjacency list:\n";
    g.displayAdjList();

    int startNode = 0;
    int goalNode = 5;
    std::vector<int> path = g.aStar(startNode, goalNode);

    if (!path.empty()) {
        std::cout << "\nShortest path from node " << startNode << " to node " << goalNode << ":\n";
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "\nNo path found from node " << startNode << " to node " << goalNode << ".\n";
    }

    return 0;
}
