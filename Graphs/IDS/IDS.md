# Iterative Deepening Search (IDS) Algorithm

A Python implementation of Iterative Deepening Search (IDS) for finding paths between nodes in both weighted and unweighted graphs. IDS combines the space efficiency of Depth-First Search with the optimality guarantees of Breadth-First Search for unweighted graphs.

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

This implementation provides an IDS-based path finder where:
- **Nodes** represent vertices (cities, locations, states, etc.)
- **Edges** represent bidirectional connections 
- **Iterative Deepening** progressively increases depth limits from 0 to max_depth
- **Space Efficiency** maintains the memory benefits of DFS
- **Completeness** guarantees finding a solution if one exists within the depth limit

IDS is particularly useful when the depth of the optimal solution is unknown but you want to maintain the space efficiency of DFS while ensuring completeness.

## Algorithm Details

### Iterative Deepening Search (IDS)

IDS works by performing multiple depth-limited searches with increasing depth limits:
1. **Depth 0**: Search only the start node
2. **Depth 1**: Search start node and its immediate neighbors  
3. **Depth 2**: Search up to 2 levels deep
4. **Continue**: Until goal is found or maximum depth reached

### Key Properties
- **Complete**: Will find a solution if one exists within max_depth
- **Optimal**: Finds shortest path in unweighted graphs (minimum edge count)
- **Space Efficient**: O(d) space complexity like DFS
- **Systematic**: Explores all possibilities at each depth before going deeper

### Algorithm Components

**1. Depth-Limited Search (DLS)**
- Recursive function that searches up to a specified depth limit
- Uses visited set to avoid cycles within current search iteration
- Returns boolean indicating success/failure
- Modifies path list to track the successful route

**2. Iterative Deepening (IDS)**  
- Calls DLS with increasing depth limits (0, 1, 2, ..., max_depth)
- Returns the path from the first successful DLS call
- Guarantees shortest path for unweighted graphs

## Code Structure

### Function Signatures

```python
def dls(graph, start, goal, limit, path, visited):
def ids(graph, start, goal, max_depth):
```

### DLS Function
**Parameters:**
- `graph`: Dictionary/defaultdict representing adjacency list
- `start`: Current node being explored
- `goal`: Target node to find
- `limit`: Remaining depth limit for current iteration
- `path`: List to store the successful path (modified in-place)
- `visited`: Set to track visited nodes (prevents cycles)

**Returns:**
- `True`: If goal found within depth limit
- `False`: If goal not found within depth limit

### IDS Function  
**Parameters:**
- `graph`: Dictionary/defaultdict representing adjacency list
- `start`: Starting node identifier
- `goal`: Goal node identifier  
- `max_depth`: Maximum depth limit to try

**Returns:**
- `path`: List of nodes from start to goal (shortest path)
- `None`: If no path exists within max_depth

## Features

### Interactive Graph Construction
- **Dynamic Input**: Build graph by entering edges interactively
- **Bidirectional Edges**: Automatically creates undirected graph
- **Flexible Nodes**: Supports string-based node identifiers
- **DefaultDict Usage**: Automatically handles new nodes

### Space-Efficient Design
- **O(d) Space**: Uses only linear space relative to depth
- **Path Tracking**: Efficiently maintains path during search
- **Cycle Prevention**: Visited set prevents infinite loops

### Progressive Search
- **Incremental Depths**: Searches depth 0, 1, 2, ... systematically
- **Early Termination**: Stops as soon as goal is found
- **Guaranteed Optimality**: First solution found is shortest for unweighted graphs

## Usage

### Basic Function Usage
```python
from collections import defaultdict

# Create graph
graph = defaultdict(list)
graph['A'].extend(['B', 'C'])
graph['B'].extend(['A', 'D'])
graph['C'].extend(['A', 'D']) 
graph['D'].extend(['B', 'C'])

# Find path
path = ids(graph, 'A', 'D', max_depth=5)
print(path)  # ['A', 'B', 'D'] or ['A', 'C', 'D']
```

### Interactive Mode
```python
# Run the script for interactive input
python ids_script.py

# Example interaction:
# Enter number of edges: 4
# Enter edges (u v) for undirected graph:
# A B
# B D  
# A C
# C D
# Enter start node: A
# Enter goal node: D
# Enter maximum depth limit: 5
# Path found: A -> B -> D
```

### Different Graph Types
```python
# Tree structure
tree_graph = defaultdict(list)
edges = [('root', 'child1'), ('root', 'child2'), ('child1', 'grandchild1')]
for u, v in edges:
    tree_graph[u].append(v)
    tree_graph[v].append(u)

# Grid-like structure  
grid_graph = defaultdict(list)
# ... add grid connections
```

## Example

### Graph Construction
```
Input:
Enter number of edges: 5
Enter edges (u v) for undirected graph:
A B
B C
C D
A E
E D

Resulting Graph:
A ←→ B ←→ C
↓         ↓
E ←←←←←→ D
```

### Graph Representation
```python
graph = defaultdict(list)
# After input processing:
graph = {
    'A': ['B', 'E'],
    'B': ['A', 'C'], 
    'C': ['B', 'D'],
    'D': ['C', 'E'],
    'E': ['A', 'D']
}
```

### IDS Execution Trace

**Finding path from A to D with max_depth=5:**

```
IDS Iteration 1 (depth=0):
└─ DLS(A, D, 0): A ≠ D, limit=0 → False

IDS Iteration 2 (depth=1):  
└─ DLS(A, D, 1):
   ├─ A ≠ D, limit=1, neighbors=[B, E]
   ├─ Try B: DLS(B, D, 0): B ≠ D, limit=0 → False
   ├─ Try E: DLS(E, D, 0): E ≠ D, limit=0 → False
   └─ False

IDS Iteration 3 (depth=2):
└─ DLS(A, D, 2):
   ├─ A ≠ D, limit=2, neighbors=[B, E]
   ├─ Try B: DLS(B, D, 1):
   │  ├─ B ≠ D, limit=1, neighbors=[A, C] 
   │  ├─ Skip A (visited)
   │  ├─ Try C: DLS(C, D, 0): C ≠ D, limit=0 → False
   │  └─ False
   ├─ Try E: DLS(E, D, 1):
   │  ├─ E ≠ D, limit=1, neighbors=[A, D]
   │  ├─ Skip A (visited)
   │  ├─ Try D: DLS(D, D, 0): D == D ✓ → True
   │  └─ True
   └─ True

Final Path: ['A', 'E', 'D']
```

### Path Analysis
- **Depth 0**: Only checks start node A
- **Depth 1**: Checks A and its neighbors B, E
- **Depth 2**: Found path A→E→D (length 3, 2 edges)
- **Result**: Shortest path with 2 edges

## Time and Space Complexity

### Time Complexity
- **O(b^d)** where b is branching factor, d is depth of solution
- **Detailed**: (d)b^0 + (d-1)b^1 + (d-2)b^2 + ... + 1×b^(d-1)
- **Dominated by**: Last iteration O(b^d)
- **Overhead**: ~b times slower than single DFS to depth d

### Space Complexity  
- **O(d)** where d is depth of solution
- **Recursion Stack**: Maximum depth d
- **Path Storage**: O(d) for storing solution path
- **Visited Set**: O(d) nodes in current path exploration

### Detailed Analysis

**Time Complexity Breakdown:**
```
For solution at depth d:
- Depth 0: b^0 = 1 node explored
- Depth 1: b^1 = b nodes explored  
- Depth 2: b^2 nodes explored
- ...
- Depth d: b^d nodes explored

Total: Σ(i=0 to d) b^i ≈ O(b^d)
```

**Space vs Other Algorithms:**
```python
# Space comparison for same graph:
# IDS: O(d) - only current path + recursion stack
# BFS: O(b^d) - stores all nodes at current level  
# A*: O(b^d) - stores open set of candidate paths
```

## Comparison with Other Algorithms

### Search Algorithm Comparison

| Algorithm | Complete | Optimal* | Time | Space | Best Use Case |
|-----------|----------|----------|------|-------|---------------|
| **IDS** | ✅ Yes | ✅ Yes | O(b^d) | O(d) | Unknown solution depth |
| **BFS** | ✅ Yes | ✅ Yes | O(b^d) | O(b^d) | Shallow solutions |
| **DFS** | ✅ Yes** | ❌ No | O(b^m) | O(m) | Deep solutions, memory limited |
| **DLS** | ⚠️ Limited | ❌ No | O(b^l) | O(l) | Known depth bounds |
| **A*** | ✅ Yes | ✅ Yes*** | O(b^d) | O(b^d) | Large graphs with heuristics |

*Optimal for unweighted graphs
**Complete for finite graphs  
***With admissible heuristic

### IDS vs Key Alternatives

**IDS vs BFS:**
- **IDS**: Same time complexity, much better space O(d) vs O(b^d)
- **BFS**: Explores each node only once vs multiple times in IDS

**IDS vs DFS:**
- **IDS**: Guaranteed shortest path vs no optimality guarantee
- **DFS**: Potentially much faster if solution is deep

**IDS vs A*:**
- **IDS**: No heuristic needed, better space complexity
- **A***: Much faster with good heuristics, but needs heuristic function

## Advantages and Limitations

### ✅ Advantages

1. **Space Efficient**: O(d) space like DFS
2. **Complete**: Guaranteed to find solution if exists
3. **Optimal**: Finds shortest path in unweighted graphs
4. **No Heuristic Needed**: Works without domain knowledge
5. **Memory Bounded**: Predictable memory usage
6. **Simple Implementation**: Easy to understand and code
7. **Flexible**: Works on any graph structure

### ❌ Limitations

1. **Time Overhead**: Repeats work, ~b times slower than single DFS
2. **Not for Weighted Graphs**: Doesn't handle edge weights optimally
3. **Exponential Time**: Still O(b^d) time complexity  
4. **Deep Solutions**: Inefficient when solutions are very deep
5. **Redundant Exploration**: Re-explores nodes at each iteration

### When to Use IDS

**✅ Ideal For:**
- Unweighted graphs where solution depth is unknown
- Memory-constrained environments  
- When BFS would exceed memory limits
- Tree-like structures with unknown depth
- Scenarios requiring shortest path guarantees

**❌ Avoid For:**
- Weighted graphs (use Dijkstra or A*)
- Very deep solutions (use DFS)  
- Shallow solutions with abundant memory (use BFS)
- Time-critical applications with known depths

## Requirements

```python
from collections import defaultdict  # For automatic list initialization
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies required
- Uses built-in collections and recursive functions

## Implementation Notes

### Design Choices

1. **Boolean Return from DLS**: Indicates success/failure
2. **In-Place Path Modification**: Efficient path building
3. **Visited Set per Iteration**: Fresh start for each depth limit
4. **DefaultDict Usage**: Simplifies graph construction

### Key Implementation Details

**Path Management:**
```python
# Path is built during successful DLS traversal
path.append(start)        # Add node
if success:
    return True           # Keep node in path
path.pop()               # Remove node if backtracking
```

**Visited Set Scope:**
```python  
# New visited set for each depth iteration
for depth in range(max_depth + 1):
    visited = set()       # Fresh start
    if dls(..., visited): # Prevents cycles within this iteration
        return path
```

### Potential Improvements

1. **Memoization**: Cache results to avoid redundant work
```python
def ids_with_memo(graph, start, goal, max_depth):
    memo = {}  # (node, remaining_depth) -> result
    
    def dls_memo(node, goal, limit, path, visited):
        if (node, limit) in memo:
            return memo[(node, limit)]
        # ... DLS logic with memoization
```

2. **Bidirectional IDS**: Search from both ends
```python
def bidirectional_ids(graph, start, goal, max_depth):
    for depth in range(max_depth + 1):
        # Alternate between forward and backward search
        # Meet in the middle for efficiency
        pass
```

3. **Parallel IDS**: Multiple depth limits simultaneously
```python
import threading

def parallel_ids(graph, start, goal, max_depth):
    # Run different depth limits in parallel threads
    # Return first successful result
    pass
```

### Error Handling and Robustness

```python
def robust_ids(graph, start, goal, max_depth):
    # Input validation
    if not graph or start not in graph:
        return None
        
    if start == goal:
        return [start]
        
    if max_depth < 0:
        return None
    
    # Check if goal exists in graph
    all_nodes = set(graph.keys()) | set(node for neighbors in graph.values() for node in neighbors)
    if goal not in all_nodes:
        return None
    
    return ids(graph, start, goal, max_depth)
```

### Performance Optimizations

1. **Early Goal Check**: Check if neighbor is goal before recursion
2. **Smarter Neighbor Ordering**: Explore promising neighbors first
3. **Iterative Implementation**: Avoid recursion overhead for very deep searches
4. **Memory Pool**: Reuse path and visited objects

## Extensions and Variations

### Weighted Graph IDS (WIDS)
```python
def weighted_ids(graph, start, goal, max_cost):
    """IDS variant for weighted graphs using cost limits instead of depth"""
    for cost_limit in range(1, max_cost + 1):
        result = dls_with_cost(graph, start, goal, cost_limit)
        if result:
            return result
    return None
```

### Multi-Goal IDS  
```python
def multi_goal_ids(graph, start, goals, max_depth):
    """Find shortest path to any of multiple goals"""
    for depth in range(max_depth + 1):
        for goal in goals:
            path = []
            visited = set()
            if dls(graph, start, goal, depth, path, visited):
                return path, goal
    return None, None
```

### All Shortest Paths IDS
```python
def all_shortest_paths_ids(graph, start, goal, max_depth):
    """Find all shortest paths of the same length"""
    for depth in range(max_depth + 1):
        all_paths = []
        find_all_paths_at_depth(graph, start, goal, depth, all_paths)
        if all_paths:
            return all_paths  # All paths at this depth are shortest
    return []
```

## Conclusion

IDS provides an elegant solution to the space-time tradeoff in graph search algorithms. It combines the space efficiency of DFS with the optimality guarantees of BFS, making it particularly valuable when:

- Solution depth is unknown
- Memory is limited  
- Shortest paths are required
- No domain-specific heuristics are available

While it does repeat work and has time overhead, IDS remains one of the most practical search algorithms for scenarios where BFS would exceed memory constraints but optimality is still required.