import matplotlib.pyplot as plt
import networkx as nx

def visualize_graph(adj_list, path):
    G = nx.DiGraph()
    for node, neighbors in adj_list.items():
        for neighbor, weight in neighbors:
            G.add_edge(node, neighbor, weight=weight)

    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=700, font_weight="bold")
    nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)})

    if path:
        path_edges = list(zip(path[:-1], path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color="red", width=2)

    plt.title("Graph Visualization with Shortest Path")
    plt.show()
