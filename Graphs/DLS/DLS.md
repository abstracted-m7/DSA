# Depth-Limited Search (DLS) Algorithm

A Python implementation of Depth-Limited Search (DLS) for finding paths between nodes in an unweighted graph with a specified maximum depth limit using recursive approach.

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

This implementation provides a DLS-based path finder for unweighted graphs where:
- **Nodes** represent vertices (e.g., cities, locations, states)
- **Edges** represent bidirectional connections with uniform cost
- **Depth Limit** constrains the maximum search depth to prevent infinite exploration
- **Recursive Approach** uses function call stack for traversal

DLS is essentially DFS with a depth constraint, making it useful for scenarios where you want to limit the search scope or prevent infinite loops in cyclic graphs.

## Algorithm Details

### Depth-Limited Search (DLS)

DLS explores the graph depth-first but stops when a specified depth limit is reached:
1. Explores paths recursively up to the specified depth limit
2. Backtracks when depth limit is reached or dead end is encountered
3. Returns the first path found within the depth limit
4. May miss solutions that exist beyond the depth limit

### Key Properties
- **Complete**: Will find a solution if one exists within the depth limit
- **Not Optimal**: Does NOT guarantee shortest path (like DFS)
- **Space Bounded**: Limited by the depth limit parameter
- **Systematic**: Explores all paths systematically within depth constraint

### Algorithm Steps
1. Start with current node and remaining depth limit
2. Add current node to path
3. If current node is goal, return path (success)
4. If depth limit reached (≤ 0), return None (failure)
5. For each unvisited neighbor:
   - Recursively call DLS with decremented depth limit
   - If recursive call succeeds, return the path
6. Return None if no path found within limit

## Code Structure

### Function Signature
```python
def dls(graph, start, goal, limit, path=None):
```

**Parameters:**
- `graph`: Dictionary representing adjacency list of the graph
- `start`: Starting node identifier
- `goal`: Goal/target node identifier  
- `limit`: Maximum depth limit for search
- `path`: Current path (used internally for recursion)

**Returns:**
- `path`: List of nodes from start to goal (if found within limit)
- `None`: If no path exists within the specified depth limit

### Data Structures Used

1. **Graph Dictionary**:
   - Adjacency list representation
   - Key: node identifier
   - Value: list of neighboring nodes

2. **Path List**:
   - Maintains current exploration path
   - Used for cycle detection (prevents revisiting nodes in current path)
   - Copied at each recursive call to maintain separate paths

3. **Recursion Stack**:
   - Implicit stack through recursive function calls
   - Depth naturally limited by the `limit` parameter

## Features

### Interactive Input System
- **Dynamic Graph Construction**: Build graph by inputting edges
- **Flexible Node Types**: Supports string-based node identifiers
- **User-Friendly Interface**: Clear prompts and formatted output
- **Bidirectional Edges**: Automatically creates undirected graph

### Path Tracking
- **Cycle Prevention**: Avoids revisiting nodes within current path
- **Path Reconstruction**: Maintains complete path during traversal
- **Immediate Return**: Returns first valid path found

### Depth Control
- **Bounded Search**: Prevents infinite exploration
- **Resource Management**: Controls memory and time usage
- **Flexible Limits**: User-defined depth constraints

## Usage

### Basic Function Call
```python
# Direct function usage
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}

result = dls(graph, 'A', 'D', limit=2)
print(result)  # ['A', 'B', 'D'] or ['A', 'C', 'D']
```

### Interactive Mode
```python
# Run the script for interactive input
python dls_script.py

# Example interaction:
# Enter the number of edges: 4
# Enter edges (format: u v):
# A B
# B C
# C D
# A D
# Enter the start Node: A
# Enter the Goal Node: D
# Enter the Depth limit: 2
```

### Code Fix Required
**Note**: There's a syntax error in the main section. The correct code should be:

```python
if __name__ == "__main__":  # Fix: double underscores
    # ... rest of the code
    limit = int(input("Enter the Depth limit: "))  # Fix: convert to int
```

## Example

### Graph Construction
```
Input edges:
A B
B C  
B D
C E
D E
A C

Resulting graph:
A ←→ B ←→ C
↓    ↓    ↓
C ←→ D ←→ E
```

### Graph Representation
```python
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'C', 'D'], 
    'C': ['A', 'B', 'E'],
    'D': ['B', 'E'],
    'E': ['C', 'D']
}
```

### Execution Examples

**Example 1: Path exists within limit**
```python
result = dls(graph, 'A', 'E', limit=3)
# Possible results: ['A', 'B', 'D', 'E'] or ['A', 'C', 'E']
# Length: 4 or 3 respectively
```

**Example 2: Path exists but exceeds limit**
```python
result = dls(graph, 'A', 'E', limit=1)
# Result: None (no path within 1 step)
```

**Example 3: Direct connection**
```python
result = dls(graph, 'A', 'C', limit=1) 
# Result: ['A', 'C'] (found in 1 step)
```

### Detailed Execution Trace

**Finding path from A to E with limit=3:**

```
Call: dls(graph, 'A', 'E', 3, [])
├─ path = ['A'], limit = 3
├─ A ≠ E, limit > 0, explore neighbors [B, C]
├─ 
├─ Try neighbor B:
│  Call: dls(graph, 'B', 'E', 2, ['A'])
│  ├─ path = ['A', 'B'], limit = 2  
│  ├─ B ≠ E, limit > 0, explore neighbors [A, C, D]
│  ├─ Skip A (already in path)
│  ├─ 
│  ├─ Try neighbor C:
│  │  Call: dls(graph, 'C', 'E', 1, ['A', 'B'])
│  │  ├─ path = ['A', 'B', 'C'], limit = 1
│  │  ├─ C ≠ E, limit > 0, explore neighbors [A, B, E]
│  │  ├─ Skip A, B (already in path)
│  │  ├─ Try neighbor E:
│  │  │  Call: dls(graph, 'E', 'E', 0, ['A', 'B', 'C'])
│  │  │  └─ path = ['A', 'B', 'C', 'E'], E == E ✓
│  │  │     Return: ['A', 'B', 'C', 'E']
│  │  └─ Return: ['A', 'B', 'C', 'E']
│  └─ Return: ['A', 'B', 'C', 'E']
└─ Return: ['A', 'B', 'C', 'E']

Final Result: ['A', 'B', 'C', 'E']
```

## Time and Space Complexity

### Time Complexity
- **O(b^l)** where b is branching factor and l is depth limit
- **Best Case**: O(l) when goal is on direct path
- **Worst Case**: O(b^l) when exploring all paths up to limit
- Much better than unlimited DFS for deep graphs

### Space Complexity
- **O(l)** for recursion stack depth
- **O(l)** for path storage
- **Total**: O(l) - significantly better than BFS
- Memory usage is bounded by depth limit

### Detailed Analysis

**Recursion Depth:**
- Maximum recursion depth: `limit + 1`
- Each recursive call uses O(1) additional space
- Path copying at each level adds O(l) per call

**Memory Efficiency:**
```python
# DLS memory usage is predictable:
# - Recursion stack: O(limit)  
# - Path storage: O(limit)
# - No exponential memory growth like BFS
```

## Comparison with Other Algorithms

### Search Algorithm Comparison

| Algorithm | Completeness | Optimality | Time Complexity | Space Complexity |
|-----------|--------------|------------|-----------------|------------------|
| **DLS** | Limited* | No | O(b^l) | O(l) |
| **DFS** | Yes** | No | O(V + E) | O(V) |
| **BFS** | Yes | Yes*** | O(V + E) | O(V²) |
| **IDDFS** | Yes | Yes*** | O(b^d) | O(d) |

*Complete only if solution exists within depth limit
**Complete for finite graphs  
***Optimal for unweighted graphs

### DLS vs Related Algorithms

**DLS vs DFS:**
- DLS: Bounded depth, prevents infinite loops
- DFS: Unbounded, may get stuck in deep branches

**DLS vs BFS:**
- DLS: Memory efficient O(l), not optimal
- BFS: Memory intensive O(V²), guaranteed optimal

**DLS vs IDDFS:**
- DLS: Single depth limit, may miss solutions
- IDDFS: Iteratively increases limit, combines DLS benefits with completeness

## Advantages and Limitations

### ✅ Advantages

1. **Memory Efficient**: O(l) space complexity
2. **Bounded Search**: Prevents infinite exploration  
3. **Simple Implementation**: Easy to understand and code
4. **Flexible Depth Control**: User-defined search limits
5. **Cycle Prevention**: Avoids infinite loops in cyclic graphs
6. **Resource Predictable**: Known maximum time/space requirements

### ❌ Limitations  

1. **Incomplete**: May miss solutions beyond depth limit
2. **Not Optimal**: Doesn't guarantee shortest path
3. **Arbitrary Limit**: Choosing appropriate limit can be challenging
4. **Depth-First Bias**: May explore long paths before short ones
5. **Parameter Sensitivity**: Performance heavily depends on limit choice

### When to Use DLS

**✅ Good For:**
- Scenarios with known maximum solution depth
- Memory-constrained environments
- Preventing runaway searches in deep graphs
- Tree-like structures with reasonable depth bounds

**❌ Avoid For:**
- Finding optimal paths (use BFS or Dijkstra)
- Unknown solution depths (use IDDFS)
- Shallow solutions in deep graphs
- Guaranteed completeness requirements

## Requirements

```python
# No external libraries required
# Uses only built-in Python features
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies
- Uses recursive function calls and basic data structures

## Implementation Notes

### Code Fixes Needed

1. **Main Guard Syntax**:
```python
# Current (incorrect):
if **name** == "__main__":

# Fixed:
if __name__ == "__main__":
```

2. **Input Type Conversion**:
```python
# Current (potential issue):
limit = input("Enter the Depth limit: ")

# Fixed:  
limit = int(input("Enter the Depth limit: "))
```

### Design Choices

1. **Recursive Implementation**: Simple and intuitive
2. **Path Copying**: `path.copy()` creates independent paths
3. **In-Path Cycle Detection**: Prevents loops within current path
4. **Early Termination**: Returns first solution found

### Potential Improvements

1. **Iterative Version**: Avoid recursion stack limitations
```python
def dls_iterative(graph, start, goal, limit):
    stack = [(start, [start], 0)]  # (node, path, depth)
    
    while stack:
        node, path, depth = stack.pop()
        
        if node == goal:
            return path
            
        if depth < limit:
            for neighbor in graph.get(node, []):
                if neighbor not in path:
                    stack.append((neighbor, path + [neighbor], depth + 1))
    
    return None
```

2. **Multiple Solutions**: Find all paths within limit
```python
def dls_all_paths(graph, start, goal, limit, path=None, all_paths=None):
    if path is None:
        path = []
    if all_paths is None:
        all_paths = []
    
    path.append(start)
    
    if start == goal:
        all_paths.append(path.copy())
        path.pop()  # backtrack
        return
    
    if limit <= 0:
        path.pop()  # backtrack
        return
    
    for neighbor in graph.get(start, []):
        if neighbor not in path:
            dls_all_paths(graph, neighbor, goal, limit-1, path, all_paths)
    
    path.pop()  # backtrack
    return all_paths
```

3. **Path Cost Tracking**: Add cost accumulation
```python
def dls_with_cost(graph, start, goal, limit, path=None, cost=0):
    # Similar structure but track path costs
    # Useful for weighted graphs within depth limit
    pass
```

### Error Handling

```python
def robust_dls(graph, start, goal, limit, path=None):
    # Input validation
    if not graph or start not in graph or goal not in graph:
        return None
        
    if limit < 0:
        return None
        
    if start == goal:
        return [start]
    
    # Main DLS logic...
    return dls(graph, start, goal, limit, path)
```

## Extensions and Variations

### Iterative Deepening DFS (IDDFS)
```python
def iddfs(graph, start, goal, max_limit=10):
    """Combines DLS with iterative deepening for completeness"""
    for limit in range(max_limit + 1):
        result = dls(graph, start, goal, limit)
        if result:
            return result, limit  # Return path and depth found
    return None, -1
```

### Bidirectional DLS
```python
def bidirectional_dls(graph, start, goal, limit):
    """Search from both start and goal simultaneously"""
    def dls_forward(node, remaining_limit, path):
        # Forward search from start
        pass
    
    def dls_backward(node, remaining_limit, path):  
        # Backward search from goal
        pass
    
    # Coordinate both searches...
```

### DLS with Heuristic Ordering
```python
def dls_heuristic(graph, start, goal, limit, heuristic_func):
    """Order neighbor exploration by heuristic values"""
    # Sort neighbors by heuristic before exploring
    # Can significantly improve performance
    pass
```

This implementation provides a solid foundation for understanding depth-limited search, with the key insight that it trades completeness for memory efficiency and bounded execution time.