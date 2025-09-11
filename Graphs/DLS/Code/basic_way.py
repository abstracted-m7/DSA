def dls(graph, start, goal, limit, path=None):
    if path is None:
        path = []
    
    path.append(start)

    #if start is goal -> success
    if start == goal:
        return path
    
    #if depth limit reached -> stop
    if limit <= 0:
        return None
    
    #Explore neighbors
    for neighbors in graph.get(start,[]):
        if neighbors not in path:
            new_path = dls(graph, neighbors, goal, limit-1, path.copy())
            if new_path:
                return new_path
    return None


#Main Function

if __name__ == "__main__":
    graph = {}
    edges = int(input("Enter the number of edges: "))
    print("Enter edges (format: u v): ")
    for _ in range(edges):
        u, v = input().split()
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append(v)
        graph[v].append(u)
    
    start = input("Enter the start Node: ")
    goal = input("Enter the Goal Node: ")
    limit = input("Enter the Depth limit: ")


    print(20*"==")
    print(f"Graph: {graph}")
    print(f"Start: {start}, Goal: {goal}, Limit: {limit}")

    result = dls(graph, start, goal, limit)

    if result:
        print(f"DLS Traversal Path: {result}")
    else:
        print(f"No path found within depth limit.")