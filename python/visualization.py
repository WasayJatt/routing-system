import matplotlib.pyplot as plt
import networkx as nx

def visualize_graph(adj_list, path):
    """
    Visualizes the graph and highlights the shortest path.
    :param adj_list: Dictionary representing adjacency list (node -> [(neighbor, weight), ...]).
    :param path: List of nodes representing the shortest path.
    """
    # Create a graph object
    G = nx.DiGraph()
    
    # Add edges to the graph
    for node, neighbors in adj_list.items():
        for neighbor, weight in neighbors:
            G.add_edge(node, neighbor, weight=weight)
    
    # Plot the graph
    pos = nx.spring_layout(G)  # Position nodes using spring layout
    
    # Draw nodes and edges
    nx.draw(G, pos, with_labels=True, node_size=700, node_color="lightblue", font_weight="bold")
    nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)})

    # Highlight the shortest path
    if path:
        path_edges = list(zip(path[:-1], path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color="red", width=2)

    plt.title("Graph Visualization with Shortest Path")
    plt.show()
