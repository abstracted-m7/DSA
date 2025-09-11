# import heapq

# def ucs(graph, start, goal):
#     priorty_queue = [(0, start)] 
#     visited = set()
#     dist = {start: 0}
#     parent = {start: None}

#     while priorty_queue:
#         cost, node = heapq.heappop(priorty_queue)

#         if node in visited:
#             continue
#         visited.add(node)

#         if node == goal:
#             path = []
#             while node is not None:
#                 path.append(node)
#                 node = parent[node]
#             path.reverse()
#             print("\nShortest Path:", " -> ".join(path))
#             print("Path Cost:", cost)
#             return

#         for neighbor, edge_cost in graph[node]:
#             new_cost = cost + edge_cost
#             if neighbor not in dist or new_cost < dist[neighbor]:
#                 dist[neighbor] = new_cost
#                 parent[neighbor] = node
#                 heapq.heappush(priorty_queue, (new_cost, neighbor))

#     print("No path found!")

# # -------- Main Program --------


# if __name__ == "__main__":
#     graph = {}

#     edges = int(input("Enter number of edges: "))
#     print("Enter edges in format: u v cost")

#     for _ in range(edges):
#         u, v, c = input().split()
#         c = int(c)

#         if u not in graph:
#             graph[u] = []
#         if v not in graph:
#             graph[v] = []

#         graph[u].append((v, c))
#         graph[v].append((u, c))

#     start = input("Enter start node: ")
#     goal = input("Enter goal node: ")

#     ucs(graph, start, goal)


'''
The above code gives error in few edge casses, like - 
    [
        Enter number of edges: 2
        Enter edges in format: u v cost
        A B 1
        B C 2
        Enter start node: X
        Enter goal node: C
        Error: System by-defult error 
    ]

    [
        Enter number of edges: 0
        Enter edges in format: u v cost
        Enter start node: A
        Enter goal node: B
        Error - It gives: TrackBack or Key error
    ]

    [
        Enter number of edges: 1
        Enter edges in format: u v cost
        A B -5
        Enter start node: A
        Enter goal node: B

        Shortest Path: A -> B
        Path Cost: -5
    ]
'''





'''
    So here is the updated version where i use error handeling using try-except to handel the customes error.
'''


#Updated code:
import heapq

def ucs(graph, start, goal):
    priority_queue = [(0, start)] 
    visited = set()
    dist = {start: 0}
    parent = {start: None}

    while priority_queue:
        cost, node = heapq.heappop(priority_queue)

        if node in visited:
            continue
        visited.add(node)

        if node == goal:
            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            path.reverse()
            print("\nShortest Path:", " -> ".join(path))
            print("Path Cost:", cost)
            return

        for neighbor, edge_cost in graph[node]:
            new_cost = cost + edge_cost
            if neighbor not in dist or new_cost < dist[neighbor]:
                dist[neighbor] = new_cost
                parent[neighbor] = node
                heapq.heappush(priority_queue, (new_cost, neighbor))

    print("No path found!")

if __name__ == "__main__":
    graph = {}

    try:
        edges = int(input("Enter number of edges: "))
    except:
        print("Invalid number of edges.")
        exit()

    print("Enter edges in format: u v cost")

    for _ in range(edges):
        line = input().strip().split()
        if len(line) != 3:
            print("Invalid edge input format.")
            exit()
        u, v, c = line
        try:
            c = int(c)
            if c < 0:
                print("Edge cost cannot be negative.")
                exit()
        except:
            print("Invalid cost input.")
            exit()

        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []

        graph[u].append((v, c))
        graph[v].append((u, c))

    start = input("Enter start node: ")
    goal = input("Enter goal node: ")

    if start not in graph or goal not in graph:
        print("Start or goal node not present in the graph.")
        exit()

    ucs(graph, start, goal)
