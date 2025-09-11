# BFS Shortest Path Algorithm

A Python implementation of Breadth-First Search (BFS) for finding the shortest path between nodes in an unweighted graph using path tracking approach.

## Table of Contents
- [Overview](#overview)
- [Algorithm Details](#algorithm-details)
- [Code Structure](#code-structure)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Time and Space Complexity](#time-and-space-complexity)
- [Comparison with Other Algorithms](#comparison-with-other-algorithms)
- [Requirements](#requirements)

## Overview

This implementation provides a BFS-based shortest path finder for unweighted graphs where:
- **Nodes** represent vertices (e.g., cities, locations, states)
- **Edges** represent connections with uniform cost (unweighted)
- **Path tracking** maintains complete paths during traversal for easy reconstruction

The algorithm guarantees finding the shortest path (minimum number of edges) from a start node to a destination node.

## Algorithm Details

### Breadth-First Search (BFS)

BFS explores the graph level by level, ensuring that:
1. All nodes at distance 1 are visited before nodes at distance 2
2. All nodes at distance k are visited before nodes at distance k+1
3. The first time we reach the goal, we've found the shortest path

### Key Properties
- **Optimal**: Finds shortest path in unweighted graphs (minimum edge count)
- **Complete**: Will find a solution if one exists
- **Systematic**: Explores all possibilities at each level before moving deeper

### Algorithm Steps
1. Initialize queue with starting path `[start]`
2. Initialize visited set to track explored nodes
3. While queue is not empty:
   - Dequeue the first path
   - Get the last vertex in the path
   - If vertex is the goal, return the path
   - If vertex hasn't been visited:
     - Mark vertex as visited
     - For each neighbor, create new path and enqueue it
4. Return None if no path exists

## Code Structure

### Function Signature
```python
def bfs_shortest_path(graph, start, goal):
```

**Parameters:**
- `graph`: Dictionary representation where keys are nodes and values are lists of neighbors
- `start`: Starting node identifier
- `goal`: Destination node identifier

**Returns:**
- `path`: List of nodes from start to goal (shortest path)
- `None`: If no path exists between start and goal

### Data Structures Used

1. **Queue (deque)**: 
   - Stores complete paths as lists
   - FIFO (First In, First Out) ensures level-by-level exploration
   - `deque` provides O(1) append and popleft operations

2. **Visited Set**:
   - Tracks explored nodes to prevent cycles
   - Ensures each node is processed only once
   - O(1) lookup and insertion

3. **Graph Dictionary**:
   - Adjacency list representation
   - Key: node identifier
   - Value: list of neighboring nodes

## Features

### Path Tracking Approach
- **Direct Path Storage**: Each queue element contains the complete path
- **Easy Reconstruction**: No need for separate parent tracking
- **Immediate Result**: Path is ready when goal is reached

### Graph Properties
- **Unweighted**: All edges have equal cost (1 hop)
- **Undirected**: Can handle both directed and undirected graphs
- **Flexible**: Works with any node identifier type (strings, numbers, etc.)

## Usage

### Basic Setup

```python
from collections import deque

# Define graph as adjacency list
graph = {
    'NodeA': ['NodeB', 'NodeC'],
    'NodeB': ['NodeA', 'NodeD'],
    'NodeC': ['NodeA'],
    'NodeD': ['NodeB']
}

# Find shortest path
path = bfs_shortest_path(graph, 'NodeA', 'NodeD')
```

### Different Graph Types

```python
# Directed graph
directed_graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['D'],
    'D': []
}

# Undirected graph (symmetric connections)
undirected_graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'], 
    'D': ['B', 'C']
}

# Numeric nodes
numeric_graph = {
    1: [2, 3],
    2: [1, 4],
    3: [1, 4],
    4: [2, 3]
}
```

### Error Handling

```python
def safe_bfs_shortest_path(graph, start, goal):
    # Check if start and goal exist in graph
    if start not in graph or goal not in graph:
        return None
    
    # Handle same start and goal
    if start == goal:
        return [start]
    
    return bfs_shortest_path(graph, start, goal)
```

## Example

### Graph Visualization
```
    A ←→ B ←→ D
    ↓    ↓
    C ←→ E ←→ F
    ↓         ↑
    F ←←←←←←←←←
```

### Graph Definition
```python
graph = {
    'A': ['B', 'C'],      # A connects to B and C
    'B': ['A', 'D', 'E'], # B connects to A, D, and E  
    'C': ['A', 'F'],      # C connects to A and F
    'D': ['B'],           # D connects to B only
    'E': ['B', 'F'],      # E connects to B and F
    'F': ['C', 'E']       # F connects to C and E
}
```

### Execution Trace

**Finding path from A to F:**

1. **Level 0**: Start with path `['A']`
   - Queue: `[['A']]`
   - Visited: `{}`

2. **Level 1**: Process A, add neighbors B and C
   - Queue: `[['A', 'B'], ['A', 'C']]`
   - Visited: `{'A'}`

3. **Level 2**: Process B, add neighbors D and E
   - Queue: `[['A', 'C'], ['A', 'B', 'D'], ['A', 'B', 'E']]`
   - Visited: `{'A', 'B'}`

4. **Level 2**: Process C, add neighbor F
   - Queue: `[['A', 'B', 'D'], ['A', 'B', 'E'], ['A', 'C', 'F']]`
   - Visited: `{'A', 'B', 'C'}`

5. **Found**: Next path `['A', 'B', 'D']` - D is not goal
6. **Found**: Next path `['A', 'B', 'E']` - E is not goal  
7. **Found**: Next path `['A', 'C', 'F']` - F is goal!

**Result**: `['A', 'C', 'F']` with length 3 (2 edges)

### Alternative Paths Analysis
- **A → C → F**: Length 3 (2 edges) ✓ **OPTIMAL**
- **A → B → E → F**: Length 4 (3 edges)
- BFS finds the optimal path first due to level-by-level exploration

## Time and Space Complexity

### Time Complexity
- **O(V + E)** where V is vertices and E is edges
- Each vertex is visited exactly once
- Each edge is examined exactly once (or twice for undirected graphs)
- Path copying adds factor proportional to path length

### Space Complexity
- **O(V × L)** where V is vertices and L is average path length
- Queue stores multiple paths simultaneously
- Visited set stores at most V vertices
- In worst case, queue might contain O(V) paths of length O(V)

### Detailed Analysis

**Queue Storage:**
- Maximum paths in queue: O(V)
- Average path length: O(V) in worst case
- Total space for paths: O(V²)

**Memory Usage:**
```python
# Worst case scenario - complete graph
# Queue might contain V paths, each of length up to V
# Space complexity: O(V²)
```

## Comparison with Other Algorithms

### BFS vs Other Pathfinding Algorithms

| Algorithm | Time Complexity | Space Complexity | Optimal for Unweighted | Optimal for Weighted |
|-----------|----------------|------------------|----------------------|---------------------|
| **BFS** | O(V + E) | O(V²) | ✅ Yes | ❌ No |
| **DFS** | O(V + E) | O(V) | ❌ No | ❌ No |
| **Dijkstra** | O((V + E) log V) | O(V) | ✅ Yes | ✅ Yes |
| **A*** | O(b^d) | O(b^d) | ✅ Yes | ✅ Yes (with admissible heuristic) |

### When to Use BFS
- **✅ Best for**: Unweighted graphs, shortest hop count
- **✅ Good for**: Small to medium graphs, simple connectivity
- **❌ Not ideal for**: Weighted graphs, very large graphs, memory-constrained environments

### BFS Variants

1. **Standard BFS (this implementation)**
   - Stores complete paths
   - Easy path reconstruction
   - Higher memory usage

2. **Parent-Tracking BFS**
   ```python
   def bfs_with_parents(graph, start, goal):
       queue = deque([start])
       visited = {start}
       parent = {start: None}
       
       while queue:
           vertex = queue.popleft()
           if vertex == goal:
               # Reconstruct path using parent pointers
               path = []
               current = goal
               while current is not None:
                   path.append(current)
                   current = parent[current]
               return path[::-1]
           
           for neighbor in graph[vertex]:
               if neighbor not in visited:
                   visited.add(neighbor)
                   parent[neighbor] = vertex
                   queue.append(neighbor)
       return None
   ```
   - Lower memory usage: O(V)
   - Requires path reconstruction step

## Requirements

```python
from collections import deque  # For efficient queue operations
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies required
- Uses built-in `collections.deque` for optimal queue performance

## Implementation Notes

### Design Choices

1. **Path Storage**: Complete paths stored in queue for simplicity
2. **Visited Check**: Performed after dequeuing to handle duplicates
3. **Queue Type**: `deque` for O(1) append/popleft operations
4. **Return Value**: Returns complete path list or None

### Edge Cases Handled

```python
# Empty graph
graph = {}
# Result: None (start not in graph)

# Single node
graph = {'A': []}
path = bfs_shortest_path(graph, 'A', 'A')
# Result: ['A']

# Disconnected graph
graph = {'A': ['B'], 'B': ['A'], 'C': ['D'], 'D': ['C']}
path = bfs_shortest_path(graph, 'A', 'C')
# Result: None (no path exists)
```

### Potential Optimizations

1. **Early Termination**: Check goal immediately when adding to queue
2. **Bidirectional BFS**: Search from both ends simultaneously
3. **Memory Optimization**: Use parent tracking instead of path storage
4. **Path Length Limit**: Add maximum depth parameter to prevent infinite search

### Common Pitfalls

1. **Memory Usage**: Path storage can consume significant memory for large graphs
2. **Duplicate Paths**: Multiple paths to same node are stored until processed
3. **Graph Modification**: Algorithm assumes static graph during execution
4. **Node Validation**: No built-in check for start/goal node existence

## Extensions and Variations

### Multi-Goal BFS
```python
def bfs_multiple_goals(graph, start, goals):
    queue = deque([[start]])
    visited = set()
    results = {}
    
    while queue and len(results) < len(goals):
        path = queue.popleft()
        vertex = path[-1]
        
        if vertex in goals and vertex not in results:
            results[vertex] = path
            
        if vertex not in visited:
            visited.add(vertex)
            for neighbor in graph[vertex]:
                queue.append(path + [neighbor])
    
    return results
```

### All Shortest Paths BFS
```python
def bfs_all_shortest_paths(graph, start, goal):
    queue = deque([[start]])
    visited = set()
    all_paths = []
    target_length = None
    
    while queue:
        path = queue.popleft()
        vertex = path[-1]
        
        # If we found longer paths, stop
        if target_length and len(path) > target_length:
            break
            
        if vertex == goal:
            if target_length is None:
                target_length = len(path)
            all_paths.append(path)
            continue
            
        if vertex not in visited:
            visited.add(vertex)
            for neighbor in graph[vertex]:
                queue.append(path + [neighbor])
    
    return all_paths
```