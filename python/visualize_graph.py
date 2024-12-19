from graph_module import Graph
from visualization import visualize_graph

# Example usage
g = Graph()
g.addEdge(0, 1, 1.0)
g.addEdge(1, 2, 2.5)
g.addEdge(2, 3, 1.2)
g.addEdge(3, 4, 3.0)
g.addEdge(0, 5, 10.0)

adj_list = g.getAdjacencyListPy()
shortest_path = [0, 1, 2, 3, 4]

visualize_graph(adj_list, shortest_path)
