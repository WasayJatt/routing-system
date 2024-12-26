#include <iostream>  // Providing input-output functionalities
#include <vector>    // Including dynamic array functionalities
#include <unordered_map>  // Offering hash table-based map implementation
#include <queue>     // Providing queue and priority queue functionalities
#include <fstream>   // Allowing file input/output operations
#include <climits>   // Defining constants for integer limits
#include <algorithm> // Enabling standard algorithms like sort, remove_if
#include <set>       // Providing ordered set functionalities
#include <cmath>     // Offering mathematical functions like min, abs
#include <limits>    // Providing limits for numeric types

using namespace std;

// Defining a structure to represent an edge with destination and weight
struct Edge {
    int to;
    int weight;
};

class Graph {
public:
    unordered_map<int, vector<Edge>> adjList; // Storing adjacency list for the graph
    unordered_map<int, string> nodeLabels;   // Storing node labels

    // Adding an edge between two nodes with a specified weight
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
    }

    // Removing an edge between two nodes
    void removeEdge(int u, int v) {
        auto removeEdgeHelper = [](vector<Edge>& edges, int target) {
            edges.erase(
                remove_if(edges.begin(), edges.end(), [target](Edge e) { return e.to == target; }),
                edges.end()
            );
        };

        if (adjList.count(u)) removeEdgeHelper(adjList[u], v);
    }

    // Adding a node to the graph with an optional label
    void addNode(int u, const string& label = "") {
        if (adjList.find(u) != adjList.end()) {
            cout << "Node " << u << " already exists.\n";
            return;
        }
        adjList[u] = {};
        if (!label.empty()) nodeLabels[u] = label;
    }

    // Removing a node and its associated edges
    void removeNode(int u) {
        adjList.erase(u);
        for (auto& pair : adjList) {
            pair.second.erase(
                remove_if(pair.second.begin(), pair.second.end(), [u](Edge e) { return e.to == u; }),
                pair.second.end()
            );
        }
        nodeLabels.erase(u);
    }

    // Calculating a heuristic for A* algorithm based on edge weights
    int heuristic(int node, int goal) {
        if (adjList.find(node) == adjList.end()) return 0;
        int min_weight = INT_MAX;
        for (const auto& edge : adjList[node]) {
            if (edge.to == goal) {
                return edge.weight; // Returning weight for direct connection
            }
            min_weight = min(min_weight, edge.weight); // Finding minimum edge weight
        }
        return min_weight == INT_MAX ? 0 : min_weight; // Returning 0 if no outgoing edges
    }

    // Implementing A* algorithm to find the shortest path
    vector<int> AStar(int start, int goal) {
        unordered_map<int, int> dist, parent;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (const auto& node : adjList) dist[node.first] = INT_MAX;

        dist[start] = 0;
        pq.push({0 + heuristic(start, goal), start}); // Calculating f(n)

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (u == goal) break;

            for (const auto& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                int g = dist[u] + weight; // Calculating g(n)
                int h = heuristic(v, goal); // Calculating h(n)
                int f = g + h; // Calculating f(n)

                if (g < dist[v]) {
                    dist[v] = g;
                    parent[v] = u;
                    pq.push({f, v}); // Adding to priority queue
                }
            }
        }

        if (parent.find(goal) == parent.end()) {
            cout << "No path found from " << start << " to " << goal << ".\n";
            return {};
        }

        vector<int> path;
        for (int at = goal; at != start; at = parent[at]) path.push_back(at);
        path.push_back(start);
        reverse(path.begin(), path.end()); // Reversing path to correct order
        return path;
    }

    // Writing graph details to a file
    void writeGraphToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Cannot open file " << filename << "\n";
            return;
        }

        file << "Nodes:\n";
        for (const auto& node : adjList) {
            file << node.first << "\n"; // Writing node IDs
        }

        file << "Edges:\n";
        for (const auto& pair : adjList) {
            for (const auto& edge : pair.second) {
                file << pair.first << " -> " << edge.to << " [weight=" << edge.weight << "]\n";
            }
        }

        file.close();
    }

    // Displaying statistics about the graph
    void displayGraphStatistics() {
        int totalNodes = adjList.size();
        int totalEdges = 0;
        double totalWeight = 0.0;

        for (const auto& pair : adjList) {
            for (const auto& edge : pair.second) {
                totalEdges++;
                totalWeight += edge.weight;
            }
        }

        double averageWeight = (totalEdges > 0) ? totalWeight / totalEdges : 0.0;
        double density = (totalNodes > 1) ? static_cast<double>(totalEdges) / (totalNodes * (totalNodes - 1)) : 0.0;

        cout << "\nGraph Statistics:\n";
        cout << "Total Nodes: " << totalNodes << "\n";
        cout << "Total Edges: " << totalEdges << "\n";
        cout << "Average Edge Weight: " << averageWeight << "\n";
        cout << "Graph Density: " << density << "\n";
    }
};

int main() {
    Graph g;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Node\n";
        cout << "2. Remove Node\n";
        cout << "3. Add Edge\n";
        cout << "4. Remove Edge\n";
        cout << "5. Write Graph to File\n";
        cout << "6. Display Graph Statistics\n";
        cout << "7. Find Shortest Path (A*)\n";
        cout << "8. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice.\n";
            continue;
        }

        if (choice == 1) {
            int node;
            string label;
            cout << "Enter node ID: ";
            cin >> node;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter label: ";
            getline(cin, label);
            g.addNode(node, label); // Adding node with optional label
            cout << "Node " << node << " added.\n";
        } else if (choice == 2) {
            int node;
            cout << "Enter node ID to remove: ";
            cin >> node;
            g.removeNode(node); // Removing specified node
            cout << "Node " << node << " removed.\n";
        } else if (choice == 3) {
            int u, v, weight;
            cout << "Enter source node, destination node, and weight: ";
            cin >> u >> v >> weight;
            g.addEdge(u, v, weight); // Adding edge with weight
            cout << "Edge added.\n";
        } else if (choice == 4) {
            int u, v;
            cout << "Enter source and destination nodes to remove edge: ";
            cin >> u >> v;
            g.removeEdge(u, v); // Removing specified edge
            cout << "Edge removed.\n";
        } else if (choice == 5) {
            g.writeGraphToFile("graph.txt"); // Writing graph to file
            cout << "Graph saved to file.\n";
        } else if (choice == 6) {
            g.displayGraphStatistics(); // Displaying graph statistics
        } else if (choice == 7) {
            int start, goal;
            cout << "Enter start node: ";
            cin >> start;
            cout << "Enter goal node: ";
            cin >> goal;
            vector<int> path = g.AStar(start, goal); // Finding shortest path
            if (!path.empty()) {
                cout << "Shortest path from " << start << " to " << goal << ": ";
                for (int node : path) cout << node << " ";
                cout << endl;
            }
        } else if (choice == 8) {
            cout << "Exiting...\n"; // Exiting the program
            break;
        } else {
            cout << "Invalid choice. Try again.\n"; // Handling invalid input
        }
    }

    return 0;
}
