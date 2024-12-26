import networkx as nx
import matplotlib.pyplot as plt

def read_graph_from_file(filename):
    graph = nx.DiGraph()  # Creating a directed graph
    with open(filename, 'r') as file:  # Opening the file for reading
        lines = file.readlines()  # Reading all lines from the file
        nodes_section = True  # Indicating the section currently being read

        for line in lines:  # Iterating over each line in the file
            line = line.strip()  # Removing leading and trailing whitespace
            if not line:
                continue  # Skipping empty lines

            if line.startswith("Nodes:"):
                continue  # Skipping the "Nodes:" header
            
            if line.startswith("Edges:"):
                nodes_section = False  # Switching to edges section
                continue  # Skipping the "Edges:" header
            
            if nodes_section:
                try:
                    node = int(line)  # Trying to parse the node ID
                    graph.add_node(node)  # Adding the node to the graph
                except ValueError:
                    print(f"Warning: Skipping invalid node line: '{line}'")  # Printing warning for invalid lines
            else:
                try:
                    # Parsing edge (format: "u -> v [weight=w]")
                    parts = line.split("->")  # Splitting the source and destination
                    u = int(parts[0].strip())  # Parsing source node
                    rest = parts[1].split("[weight=")  # Extracting destination and weight
                    v = int(rest[0].strip())  # Parsing destination node
                    weight = int(rest[1].strip("]"))  # Parsing weight

                    # Adding edge only if reverse edge does not exist
                    if not graph.has_edge(v, u):  # Checking for reverse edge
                        graph.add_edge(u, v, weight=weight)  # Adding edge to the graph
                except ValueError:
                    print(f"Warning: Skipping invalid edge line: '{line}'")  # Printing warning for invalid lines

    return graph  # Returning the constructed graph

def visualize_graph(graph): 
    pos = nx.spring_layout(graph)  # Generating positions for nodes
    labels = nx.get_edge_attributes(graph, 'weight')  # Extracting edge weights as labels

    # Drawing nodes
    nx.draw_networkx_nodes(graph, pos, node_color='orange', node_size=390)
    # Drawing node labels
    nx.draw_networkx_labels(graph, pos, font_size=12, font_weight='bold')

    # Drawing directed edges with arrows
    nx.draw_networkx_edges(
        graph, pos, edge_color='black', arrows=True, arrowstyle="-|>", arrowsize=15, width=1
    )
    
    # Drawing edge labels (weights)
    nx.draw_networkx_edge_labels(graph, pos, edge_labels=labels, font_size=10)

    # Adding title with styling
    props = {'family': 'Sans-serif', 'color': 'darkred', 'weight': 'bold', 'size': 16}
    plt.title("Directed Graph Visualization", fontdict=props, pad=20)
    
    plt.show()  # Displaying the graph visualization

if __name__ == "__main__":
    filename = "C:\\Users\\wasay\\OneDrive\\Documents\\Navigation Routing System\\cpp\\graph.txt"  # Specifying the input file path
    graph = read_graph_from_file(filename)  # Reading the graph from the file
    visualize_graph(graph)  # Visualizing the graph