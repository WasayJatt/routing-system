import networkx as nx
import matplotlib.pyplot as plt
from graph_module import Graph

# Initialize graph with 6 nodes
g = Graph(6)

# Add edges
g.addEdge(0, 1, 1.0)
g.addEdge(1, 2, 2.5)
g.addEdge(2, 3, 1.2)
g.addEdge(3, 4, 3.0)
g.addEdge(4, 5, 2.3)
g.addEdge(0, 5, 10.0)

# Fetch adjacency list
adj_list = g.getAdjacencyListPy()

# Create a NetworkX graph for visualization
G = nx.DiGraph()
for node, edges in adj_list.items():
    for edge in edges:
        G.add_edge(node, edge[0], weight=edge[1])

# Draw the graph with weights
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=2000, font_size=15)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.title("Graph Visualization")