# For both weighted and unweighted graphs

from collections import defaultdict

# Depth-Limited Search (DLS)
def dls(graph, start, goal, limit, path, visited):
    path.append(start)
    visited.add(start)

    if start == goal:
        return True

    if limit <= 0:
        path.pop()
        return False

    for neighbor in graph[start]:
        if neighbor not in visited: # avoid cycles
            if dls(graph, neighbor, goal, limit - 1, path, visited):
                return True

    path.pop()
    return False

def ids(graph, start, goal, max_depth):
    for depth in range(max_depth + 1):
        path = []
        visited = set()
        if dls(graph, start, goal, depth, path, visited):
            return path
    return None


# ---------------- MAIN PROGRAM ----------------
graph = defaultdict(list)

edges = int(input("Enter number of edges: "))
print("Enter edges (u v) for undirected graph:")

for _ in range(edges):
    u, v = input().split()
    graph[u].append(v)
    graph[v].append(u) 

start = input("Enter start node: ")
goal = input("Enter goal node: ")
max_depth = int(input("Enter maximum depth limit: "))

path = ids(graph, start, goal, max_depth)

if path:
    print(f"Path found: {' -> '.join(path)}")
else:
    print("No path found within the given depth limit.")
