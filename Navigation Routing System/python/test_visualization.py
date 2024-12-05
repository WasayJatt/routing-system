from visualization import visualize_graph

# Example Adjacency List and Path
adj_list = {
    0: [(1, 1), (5, 10)],
    1: [(2, 2.5)],
    2: [(3, 1.2)],
    3: [(4, 3)],
    4: [(5, 2.3)],
    5: []
}

shortest_path = [0, 1, 2, 3, 4, 5]

# Call the visualization function
visualize_graph(adj_list, shortest_path)
