# Bidirectional Search Algorithm

A Python implementation of Bidirectional Search for finding the shortest path between nodes in unweighted graphs. This algorithm simultaneously searches from both the start and goal nodes, significantly reducing the search space and time complexity compared to standard BFS.

## Table of Contents
- [Overview](#overview)
- [Algorithm Details](#algorithm-details)
- [Code Structure](#code-structure)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Time and Space Complexity](#time-and-space-complexity)
- [Comparison with Other Algorithms](#comparison-with-other-algorithms)
- [Advantages and Limitations](#advantages-and-limitations)
- [Requirements](#requirements)

## Overview

This implementation provides a bidirectional search algorithm where:
- **Nodes** represent vertices (cities, locations, states, etc.)
- **Edges** represent bidirectional connections with uniform cost
- **Dual BFS** runs breadth-first search from both start and goal simultaneously
- **Meeting Point** is where the two searches intersect, forming the complete path

Bidirectional search is particularly effective for finding shortest paths in large graphs where the branching factor is high, as it can dramatically reduce the number of nodes explored.

## Algorithm Details

### Bidirectional Search

The algorithm maintains two separate BFS explorations:
1. **Forward Search**: BFS from start node toward goal
2. **Backward Search**: BFS from goal node toward start  
3. **Intersection Detection**: Check if nodes from one search have been visited by the other
4. **Path Construction**: Combine paths from both directions when they meet

### Key Properties
- **Complete**: Will find a solution if one exists (like BFS)
- **Optimal**: Finds shortest path in unweighted graphs (minimum edge count)
- **Efficient**: Explores significantly fewer nodes than standard BFS
- **Space-Time Tradeoff**: Uses more memory but dramatically reduces time

### Algorithm Steps
1. Initialize two queues: one for forward search, one for backward search
2. Initialize two visited dictionaries to track parent relationships
3. While either queue has nodes to explore:
   - **Forward Step**: Expand one node from start queue
     - Check if node was visited by backward search (intersection found)
     - Add unvisited neighbors to forward queue and visited set
   - **Backward Step**: Expand one node from goal queue  
     - Check if node was visited by forward search (intersection found)
     - Add unvisited neighbors to backward queue and visited set
4. When intersection found, reconstruct complete path

## Code Structure

### Function Signatures
```python
def simple_bidirectional_search(graph, start, goal):
def build_path(start_visited, goal_visited, meeting_point):
```

### Main Function
**Parameters:**
- `graph`: Dictionary representing adjacency list of the graph
- `start`: Starting node identifier
- `goal`: Goal node identifier

**Returns:**
- `path`: List of nodes from start to goal (shortest path)
- `[]`: Empty list if no path exists

### Path Building Function
**Parameters:**
- `start_visited`: Dictionary mapping nodes to parents in forward search
- `goal_visited`: Dictionary mapping nodes to parents in backward search  
- `meeting_point`: Node where the two searches intersected

**Returns:**
- `path`: Complete path from start to goal through meeting point

## Features

### Dual Queue Management
- **Forward Queue**: BFS expansion from start node
- **Backward Queue**: BFS expansion from goal node
- **Alternating Exploration**: Processes one node from each direction per iteration
- **Early Termination**: Stops immediately when searches meet

### Efficient Path Reconstruction
- **Parent Tracking**: Maintains parent pointers for both directions
- **Path Merging**: Combines forward and backward paths at meeting point
- **Automatic Reversal**: Handles path direction correction

### Intersection Detection
- **Cross-Checking**: Each expansion checks the other search's visited set
- **Immediate Recognition**: Detects meeting point as soon as intersection occurs
- **Optimal Meeting**: Finds intersection at the optimal midpoint

## Usage

### Direct Function Call
```python
# Define graph as adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}

# Find shortest path
path = simple_bidirectional_search(graph, 'A', 'D')
print(' -> '.join(path) if path else 'No path')
```

### Example with Provided Graph
```python
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B', 'G'],
    'E': ['B', 'F', 'H'],
    'F': ['C', 'E', 'I'],
    'G': ['D'],
    'H': ['E', 'I'],
    'I': ['F', 'H']
}

result = simple_bidirectional_search(graph, 'A', 'I')
print(f"A to I: {' -> '.join(result) if result else 'No path'}")
```

### Interactive Usage
```python
def interactive_bidirectional_search():
    # Build graph from user input
    graph = {}
    edges = int(input("Enter number of edges: "))
    
    for _ in range(edges):
        u, v = input("Enter edge (u v): ").split()
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append(v)
        graph[v].append(u)
    
    start = input("Enter start node: ")
    goal = input("Enter goal node: ")
    
    path = simple_bidirectional_search(graph, start, goal)
    if path:
        print(f"Shortest path: {' -> '.join(path)}")
        print(f"Path length: {len(path)}")
    else:
        print("No path found!")
```

## Example

### Graph Visualization
```
    A ←→ B ←→ D ←→ G
    ↓    ↓    
    C    E ←→ H
    ↓    ↓    ↓
    F ←→ I ←→ (H)
```

### Graph Representation
```python
graph = {
    'A': ['B', 'C'],      # A connects to B and C
    'B': ['A', 'D', 'E'], # B connects to A, D, and E
    'C': ['A', 'F'],      # C connects to A and F
    'D': ['B', 'G'],      # D connects to B and G
    'E': ['B', 'F', 'H'], # E connects to B, F, and H
    'F': ['C', 'E', 'I'], # F connects to C, E, and I
    'G': ['D'],           # G connects to D only
    'H': ['E', 'I'],      # H connects to E and I
    'I': ['F', 'H']       # I connects to F and H
}
```

### Bidirectional Search Execution Trace

**Finding path from A to I:**

```
Initialization:
├─ Forward queue: [A], visited: {A: None}
├─ Backward queue: [I], visited: {I: None}
└─ Meeting point: Not found

Step 1: Process A (forward) and I (backward)
├─ Forward: A → neighbors [B, C]
│  ├─ Add B to forward queue, B not in backward visited
│  └─ Add C to forward queue, C not in backward visited
├─ Backward: I → neighbors [F, H] 
│  ├─ Add F to backward queue, F not in forward visited
│  └─ Add H to backward queue, H not in forward visited
├─ Forward queue: [B, C], visited: {A: None, B: A, C: A}
└─ Backward queue: [F, H], visited: {I: None, F: I, H: I}

Step 2: Process B (forward) and F (backward)
├─ Forward: B → neighbors [A, D, E]
│  ├─ Skip A (already visited)
│  ├─ Add D to forward queue, D not in backward visited
│  └─ Add E to forward queue, E not in backward visited  
├─ Backward: F → neighbors [C, E, I]
│  ├─ Add C to backward queue... but C in forward visited!
│  ├─ INTERSECTION FOUND at C!
│  └─ Meeting point: C

Path Reconstruction:
├─ Forward path (A to C): A ← C, so [A, C]
├─ Backward path (C to I): C → F → I, so [F, I]
└─ Complete path: [A, C] + [F, I] = [A, C, F, I]
```

**Final Result**: A → C → F → I (length 4, 3 edges)

### Comparison with Standard BFS

**Standard BFS from A to I:**
```
Level 0: [A]
Level 1: [B, C]  
Level 2: [D, E, F]
Level 3: [G, H, I] ← Found I here
Total nodes explored: 1 + 2 + 3 + 3 = 9 nodes
```

**Bidirectional Search A to I:**
```
Forward: A → B,C → D,E + Backward: I → F,H → (meets at C)
Total nodes explored: 1 + 2 + 1 + 2 = 6 nodes
Efficiency gain: ~33% fewer nodes explored
```

## Time and Space Complexity

### Time Complexity
- **O(b^(d/2))** where b is branching factor, d is depth of solution
- **Standard BFS**: O(b^d)  
- **Improvement Factor**: Roughly √(b^d) = b^(d/2) speedup
- **Best Case**: When path length is even and meeting point is exactly halfway

### Space Complexity
- **O(b^(d/2))** for storing visited nodes from both directions
- **Two Queues**: Each stores nodes at current exploration level
- **Two Visited Sets**: Track parents for path reconstruction
- **Memory Usage**: About 2× that of standard BFS but explores far fewer nodes

### Detailed Analysis

**Search Space Reduction:**
```python
# Standard BFS explores all nodes within radius d
# Nodes explored ≈ b^0 + b^1 + ... + b^d ≈ b^d

# Bidirectional explores nodes within radius d/2 from each end  
# Nodes explored ≈ 2 × (b^0 + b^1 + ... + b^(d/2)) ≈ 2×b^(d/2)

# Speedup ratio: b^d / (2×b^(d/2)) = b^(d/2) / 2
# For b=10, d=6: 10^6 / (2×10^3) = 1,000,000 / 2,000 = 500x speedup!
```

## Comparison with Other Algorithms

### Pathfinding Algorithm Comparison

| Algorithm | Time | Space | Optimal | Complete | Best Use Case |
|-----------|------|-------|---------|----------|---------------|
| **Bidirectional BFS** | O(b^(d/2)) | O(b^(d/2)) | ✅ Yes | ✅ Yes | Large unweighted graphs |
| **Standard BFS** | O(b^d) | O(b^d) | ✅ Yes | ✅ Yes | Small-medium graphs |
| **DFS** | O(b^m) | O(m) | ❌ No | ✅ Yes | Memory-limited, any path OK |
| **A*** | O(b^d) | O(b^d) | ✅ Yes* | ✅ Yes | Large graphs with heuristics |
| **Dijkstra** | O((V+E)log V) | O(V) | ✅ Yes | ✅ Yes | Weighted graphs |

*A* optimal with admissible heuristics

### Bidirectional vs Standard BFS

**Advantages of Bidirectional:**
- **Exponential Speedup**: Roughly b^(d/2) times faster
- **Same Optimality**: Guarantees shortest path like standard BFS
- **Early Termination**: Stops as soon as paths meet
- **Scalability**: Performance advantage increases with graph size

**When Standard BFS is Better:**
- **Very Short Paths**: Overhead not worth it for d ≤ 2
- **Small Graphs**: Setup overhead dominates for tiny graphs
- **Memory Constraints**: Bidirectional uses ~2× memory for tracking

## Advantages and Limitations

### ✅ Advantages

1. **Dramatic Speedup**: Exponential reduction in time complexity
2. **Optimal Results**: Finds shortest path in unweighted graphs
3. **Complete**: Guaranteed to find solution if one exists  
4. **Scalable**: Performance advantage grows with graph size
5. **Early Termination**: Stops immediately when paths meet
6. **Predictable**: Same worst-case guarantees as BFS

### ❌ Limitations

1. **Unweighted Graphs Only**: Doesn't handle edge weights properly
2. **Memory Overhead**: Requires 2× the data structures
3. **Implementation Complexity**: More complex than standard BFS
4. **Path Reconstruction**: Requires careful merging of two paths
5. **Graph Requirements**: Needs bidirectional edges for backward search

### When to Use Bidirectional Search

**✅ Ideal For:**
- Large unweighted graphs with high branching factor
- Long shortest paths (d > 4)
- When shortest path optimality is required
- Social networks, web graphs, transportation networks
- When standard BFS is too slow

**❌ Avoid For:**
- Weighted graphs (use Dijkstra or A*)
- Very small graphs or short paths
- Directed graphs without reverse edges
- When memory is severely constrained
- When any path is acceptable (use DFS)

## Requirements

```python
# No external libraries required
# Uses only built-in Python data structures
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies
- Uses lists, dictionaries, and basic control structures

## Implementation Notes

### Design Choices

1. **List as Queue**: Uses `list.pop(0)` for simplicity (O(n) but acceptable for small graphs)
2. **Alternating Search**: Processes one node from each direction per iteration
3. **Parent Tracking**: Stores parent pointers for path reconstruction
4. **Immediate Intersection Check**: Tests for meeting after each node expansion

### Potential Improvements

1. **Efficient Queue**: Use `collections.deque` for O(1) operations
```python
from collections import deque

def improved_bidirectional_search(graph, start, goal):
    start_queue = deque([start])
    goal_queue = deque([goal])
    
    while start_queue or goal_queue:
        if start_queue:
            node = start_queue.popleft()  # O(1) instead of O(n)
            # ... rest of logic
```

2. **Balanced Search**: Ensure both searches proceed at similar rates
```python
def balanced_bidirectional_search(graph, start, goal):
    # Alternate between searches more intelligently
    # Balance queue sizes to optimize meeting point
```

3. **Weighted Graph Support**: Extend to handle edge weights
```python
def weighted_bidirectional_search(graph, start, goal):
    # Use priority queues instead of simple queues
    # Implement bidirectional Dijkstra's algorithm
```

4. **Multiple Goals**: Find shortest path to any of several goals
```python
def multi_goal_bidirectional_search(graph, start, goals):
    # Expand backward search from all goals simultaneously
    # Return first intersection found
```

### Error Handling

```python
def robust_bidirectional_search(graph, start, goal):
    # Input validation
    if start not in graph or goal not in graph:
        return []
    
    if start == goal:
        return [start]
    
    # Check graph connectivity
    all_nodes = set(graph.keys())
    start_reachable = set()
    goal_reachable = set()
    
    # BFS to find reachable nodes from each direction
    # Return empty list if no connection possible
    
    return simple_bidirectional_search(graph, start, goal)
```

## Extensions and Variations

### Bidirectional A* Search
```python
def bidirectional_a_star(graph, start, goal, heuristic):
    """Combines bidirectional search with A* heuristics"""
    # Use priority queues with f(n) = g(n) + h(n)
    # More complex but very powerful for large weighted graphs
```

### Bidirectional Dijkstra
```python
def bidirectional_dijkstra(graph, start, goal):
    """Bidirectional search for weighted graphs"""
    # Use priority queues with actual path costs
    # Optimal for weighted graphs, significant speedup over standard Dijkstra
```

### K-Shortest Paths Bidirectional
```python
def k_shortest_bidirectional(graph, start, goal, k):
    """Find k shortest paths using bidirectional approach"""
    # Continue search after first path found
    # Collect multiple meeting points for diverse paths
```

### Bidirectional Search with Constraints
```python
def constrained_bidirectional_search(graph, start, goal, forbidden_nodes):
    """Bidirectional search avoiding specified nodes"""
    # Skip forbidden nodes during expansion
    # Useful for dynamic routing around obstacles
```

## Conclusion

Bidirectional search represents one of the most elegant optimizations in graph algorithms. By the simple insight of searching from both ends simultaneously, it achieves exponential speedup over standard BFS while maintaining the same optimality guarantees.

The algorithm is particularly valuable for:
- **Large-scale pathfinding** where standard BFS becomes impractical
- **Social network analysis** for finding connections between users  
- **Transportation networks** for route planning
- **Web crawling** for finding paths between pages

While bidirectional search requires more careful implementation than standard BFS, the dramatic performance improvements make it worthwhile for any application dealing with substantial unweighted graphs where shortest paths are required.