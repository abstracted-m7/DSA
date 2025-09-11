# Uniform Cost Search (UCS) Algorithm

A Python implementation of Uniform Cost Search (UCS) for finding the lowest-cost path between nodes in weighted graphs. UCS is essentially Dijkstra's algorithm for single source-destination pathfinding, guaranteed to find optimal solutions in graphs with non-negative edge weights.

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

This implementation provides a UCS-based shortest path finder for weighted graphs where:
- **Nodes** represent vertices (cities, locations, states, etc.)
- **Edges** represent weighted connections with non-negative costs
- **Priority Queue** ensures exploration of lowest-cost paths first
- **Optimality** guarantees finding the minimum-cost path from start to goal

UCS is particularly useful for pathfinding in weighted graphs where you need the optimal (lowest cost) solution, such as route planning with different road costs, network routing, or resource allocation problems.

## Algorithm Details

### Uniform Cost Search (UCS)

UCS explores nodes in order of their path cost from the start node:
1. **Priority Queue**: Maintains nodes ordered by cumulative path cost
2. **Greedy Selection**: Always expands the lowest-cost unexplored node
3. **Optimal Substructure**: Builds optimal paths incrementally
4. **Cycle Handling**: Uses visited set and cost comparison for efficiency

### Key Properties
- **Complete**: Will find a solution if one exists
- **Optimal**: Finds minimum-cost path for non-negative edge weights
- **Systematic**: Explores all paths in order of increasing cost
- **Informed**: Uses actual costs rather than heuristics

### Algorithm Steps
1. Initialize priority queue with (0, start_node)
2. Initialize distance dictionary with start_node cost = 0
3. While priority queue is not empty:
   - Pop lowest-cost node from queue
   - Skip if already visited (handles duplicates)
   - Mark node as visited
   - If node is goal, reconstruct and return path
   - For each neighbor:
     - Calculate new path cost
     - If better path found, update cost and parent
     - Add neighbor to priority queue

## Code Structure

### Function Signature
```python
def ucs(graph, start, goal):
```

**Parameters:**
- `graph`: Dictionary where keys are nodes and values are lists of (neighbor, cost) tuples
- `start`: Starting node identifier
- `goal`: Goal node identifier

**Returns/Prints:**
- **Success**: Prints shortest path and total cost
- **Failure**: Prints "No path found!"

### Data Structures Used

1. **Priority Queue (heapq)**:
   - Stores (cost, node) tuples
   - Automatically maintains min-heap property
   - O(log n) insertion and extraction

2. **Visited Set**:
   - Tracks fully processed nodes
   - Prevents reprocessing of optimal paths
   - O(1) lookup time

3. **Distance Dictionary**:
   - Maps node → minimum cost from start
   - Used for cost comparison and optimization
   - Enables efficient duplicate detection

4. **Parent Dictionary**:
   - Maps node → previous node in optimal path
   - Enables path reconstruction via backtracking
   - Maintains optimal path tree structure

## Features

### Robust Input Validation
- **Edge Count Validation**: Handles invalid integer input
- **Format Checking**: Ensures proper "u v cost" format
- **Cost Validation**: Prevents negative edge weights
- **Node Existence**: Verifies start/goal nodes exist in graph
- **Graceful Error Handling**: Clear error messages and safe exits

### Interactive Graph Construction
- **Dynamic Input**: Build weighted graph interactively
- **Bidirectional Edges**: Automatically creates undirected graph
- **Flexible Node Types**: Supports string-based identifiers
- **Cost Specification**: Allows custom edge weights

### Optimal Path Reconstruction
- **Parent Tracking**: Maintains optimal path tree
- **Backtracking**: Reconstructs path from goal to start
- **Formatted Output**: Clear path display with costs

## Usage

### Interactive Mode
```python
# Run the script
python ucs_script.py

# Example interaction:
# Enter number of edges: 4
# Enter edges in format: u v cost
# A B 2
# B C 3
# A C 7
# C D 1
# Enter start node: A
# Enter goal node: D
# 
# Shortest Path: A -> B -> C -> D
# Path Cost: 6
```

### Direct Function Usage
```python
import heapq

# Define weighted graph
graph = {
    'A': [('B', 2), ('C', 7)],
    'B': [('A', 2), ('C', 3)], 
    'C': [('A', 7), ('B', 3), ('D', 1)],
    'D': [('C', 1)]
}

ucs(graph, 'A', 'D')
```

### Code Fix Required
**Note**: There's a syntax error in the main section:

```python
# Current (incorrect):
if **name** == "__main__":

# Fixed:
if __name__ == "__main__":
```

## Example

### Graph Construction
```
Input:
Enter number of edges: 6
Enter edges in format: u v cost
A B 4
A C 2
B C 1
B D 5
C D 8
C E 10
B E 3
E D 2

Resulting Weighted Graph:
    A
   /|\ 
  4 2 \
 /  |  \
B---C   \
|\ /|    \
5|X |8    \
|/ \|     |
D   E-----/
 \ /
  2
```

### Graph Representation
```python
graph = {
    'A': [('B', 4), ('C', 2)],
    'B': [('A', 4), ('C', 1), ('D', 5), ('E', 3)],
    'C': [('A', 2), ('B', 1), ('D', 8), ('E', 10)], 
    'D': [('B', 5), ('C', 8), ('E', 2)],
    'E': [('B', 3), ('C', 10), ('D', 2)]
}
```

### UCS Execution Trace

**Finding lowest-cost path from A to D:**

```
Step 1: Initialize
├─ Priority Queue: [(0, 'A')]
├─ Distance: {'A': 0}
├─ Parent: {'A': None}
└─ Visited: {}

Step 2: Process A (cost=0)
├─ Pop (0, 'A'), mark A as visited
├─ Explore neighbors: B(cost=4), C(cost=2)
├─ Priority Queue: [(2, 'C'), (4, 'B')]
├─ Distance: {'A': 0, 'B': 4, 'C': 2}
└─ Parent: {'A': None, 'B': 'A', 'C': 'A'}

Step 3: Process C (cost=2)
├─ Pop (2, 'C'), mark C as visited  
├─ Explore neighbors: A(skip-visited), B(cost=3), D(cost=10), E(cost=12)
├─ Update B: 2+1=3 < 4, so update B's cost and parent
├─ Priority Queue: [(3, 'B'), (4, 'B'), (10, 'D'), (12, 'E')]
├─ Distance: {'A': 0, 'B': 3, 'C': 2, 'D': 10, 'E': 12}
└─ Parent: {'A': None, 'B': 'C', 'C': 'A', 'D': 'C', 'E': 'C'}

Step 4: Process B (cost=3)
├─ Pop (3, 'B'), mark B as visited
├─ Skip (4, 'B') - duplicate with higher cost
├─ Explore neighbors: A(skip-visited), C(skip-visited), D(cost=8), E(cost=6)
├─ Update D: 3+5=8 < 10, so update D's cost and parent  
├─ Update E: 3+3=6 < 12, so update E's cost and parent
├─ Priority Queue: [(6, 'E'), (8, 'D'), (10, 'D'), (12, 'E')]
├─ Distance: {'A': 0, 'B': 3, 'C': 2, 'D': 8, 'E': 6}
└─ Parent: {'A': None, 'B': 'C', 'C': 'A', 'D': 'B', 'E': 'B'}

Step 5: Process E (cost=6)
├─ Pop (6, 'E'), mark E as visited
├─ Explore neighbors: B(skip-visited), C(skip-visited), D(cost=8)
├─ Update D: 6+2=8 = 8, no improvement
├─ Priority Queue: [(8, 'D'), (10, 'D'), (12, 'E')]
└─ No changes to distance/parent

Step 6: Process D (cost=8) - GOAL FOUND!
├─ Pop (8, 'D'), D is goal node
├─ Reconstruct path: D←B←C←A
└─ Final path: A→C→B→D with cost 8
```

**Final Result:**
- **Path**: A → C → B → D  
- **Cost**: 8 (2 + 1 + 5)

## Time and Space Complexity

### Time Complexity
- **O((V + E) log V)** where V is vertices and E is edges
- **Heap Operations**: O(log V) for each of O(V + E) operations
- **Comparison**: Each edge may cause heap insertion
- **Worst Case**: Dense graph with many cost updates

### Space Complexity
- **O(V)** for storing node information
- **Priority Queue**: O(V) nodes in worst case
- **Auxiliary Structures**: O(V) for visited, distance, parent dictionaries

### Detailed Analysis

**Priority Queue Size:**
- Maximum size: O(V) when all nodes are queued
- Average size: Much smaller due to early goal termination
- Duplicate handling: May temporarily store multiple copies

**Memory Usage:**
```python
# Space breakdown:
# - Priority queue: O(V) node entries
# - Visited set: O(V) boolean flags  
# - Distance dict: O(V) cost values
# - Parent dict: O(V) node references
# Total: O(V) space complexity
```

## Comparison with Other Algorithms

### Pathfinding Algorithm Comparison

| Algorithm | Optimal | Complete | Time Complexity | Space | Best for |
|-----------|---------|----------|----------------|-------|----------|
| **UCS** | ✅ Yes | ✅ Yes | O((V+E) log V) | O(V) | Weighted graphs, guaranteed optimal |
| **Dijkstra** | ✅ Yes | ✅ Yes | O((V+E) log V) | O(V) | All shortest paths from source |
| **BFS** | ✅ Yes* | ✅ Yes | O(V + E) | O(V) | Unweighted graphs only |
| **DFS** | ❌ No | ✅ Yes | O(V + E) | O(V) | Any path acceptable |
| **A*** | ✅ Yes** | ✅ Yes | O(b^d) | O(b^d) | Large graphs with good heuristics |

*BFS optimal only for unweighted graphs
**A* optimal with admissible heuristics

### UCS vs Key Alternatives

**UCS vs Dijkstra:**
- **UCS**: Single source-destination, stops at goal
- **Dijkstra**: Single source to all destinations, explores entire reachable graph

**UCS vs BFS:**
- **UCS**: Handles weighted graphs optimally
- **BFS**: Only optimal for unweighted graphs, faster for uniform costs

**UCS vs A*:**
- **UCS**: No heuristic needed, simpler implementation
- **A***: Much faster with good heuristics, requires domain knowledge

## Advantages and Limitations

### ✅ Advantages

1. **Guaranteed Optimal**: Finds minimum-cost path for non-negative weights
2. **Complete**: Always finds solution if one exists  
3. **No Heuristics Required**: Works without domain knowledge
4. **Handles Weighted Graphs**: Unlike BFS, properly handles edge costs
5. **Early Termination**: Stops when goal is reached (vs Dijkstra)
6. **Space Efficient**: O(V) space vs exponential for some algorithms
7. **Robust Implementation**: Handles duplicates and cycles gracefully

### ❌ Limitations

1. **Non-Negative Weights Only**: Cannot handle negative edge costs
2. **No Heuristic Guidance**: Explores uniformly vs directed search
3. **Slower than A***: Without heuristics, may explore unnecessary nodes
4. **Memory for Large Graphs**: Priority queue can become large
5. **Single Goal**: Must restart for different destinations

### When to Use UCS

**✅ Ideal For:**
- Weighted graphs with non-negative edge costs
- When optimal path cost is required
- No available heuristic information
- Single source-destination queries
- Route planning with distance/cost constraints

**❌ Avoid For:**
- Unweighted graphs (use BFS instead)
- Graphs with negative weights (use Bellman-Ford)
- Large graphs with good heuristics (use A*)
- Multiple destination queries (use Dijkstra)

## Requirements

```python
import heapq  # For priority queue implementation
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies required
- Uses built-in heapq module for efficient priority queue

## Implementation Notes

### Design Choices

1. **Heapq Usage**: Python's built-in min-heap for priority queue
2. **Tuple Comparison**: (cost, node) tuples for natural heap ordering
3. **Duplicate Handling**: Visited set prevents reprocessing
4. **In-Place Updates**: Modifies distance/parent dictionaries directly

### Key Implementation Details

**Priority Queue Management:**
```python
# Heap stores (cost, node) tuples
heapq.heappush(priority_queue, (new_cost, neighbor))

# Pop returns lowest cost first
cost, node = heapq.heappop(priority_queue)
```

**Duplicate Prevention:**
```python
# Skip if already processed optimally
if node in visited:
    continue
    
# Only update if better path found
if neighbor not in dist or new_cost < dist[neighbor]:
    dist[neighbor] = new_cost
```

### Error Handling Features

1. **Input Validation**: Comprehensive error checking
2. **Negative Weight Detection**: Prevents invalid graphs
3. **Node Validation**: Ensures start/goal exist
4. **Safe Exits**: Graceful program termination on errors

### Potential Improvements

1. **Return Path Instead of Print**: More flexible usage
```python
def ucs_return_path(graph, start, goal):
    # ... UCS logic ...
    if node == goal:
        path = reconstruct_path(parent, start, goal)
        return path, cost
    return None, float('inf')
```

2. **Multiple Goals**: Find shortest path to any goal
```python
def ucs_multiple_goals(graph, start, goals):
    # ... modified UCS logic ...
    if node in goals:
        return reconstruct_path(parent, start, node), cost
```

3. **Path Length Limit**: Add maximum cost constraint
```python
def ucs_with_limit(graph, start, goal, max_cost):
    # Skip paths exceeding max_cost
    if cost > max_cost:
        continue
```

4. **Bidirectional UCS**: Search from both ends
```python
def bidirectional_ucs(graph, start, goal):
    # Run UCS from both start and goal
    # Meet in the middle for efficiency
```

## Extensions and Variations

### All Shortest Paths UCS
```python
def ucs_all_paths(graph, start, goal):
    """Find all optimal paths with same minimum cost"""
    optimal_cost = None
    all_optimal_paths = []
    
    # Modified UCS that continues after finding first optimal path
    # Collects all paths with same optimal cost
    return all_optimal_paths, optimal_cost
```

### UCS with Path Constraints  
```python
def constrained_ucs(graph, start, goal, forbidden_nodes=None):
    """UCS avoiding specified nodes"""
    if forbidden_nodes is None:
        forbidden_nodes = set()
    
    # Skip forbidden nodes during exploration
    for neighbor, edge_cost in graph[node]:
        if neighbor in forbidden_nodes:
            continue
        # ... rest of UCS logic
```

### Weighted UCS (Different Edge Types)
```python
def multi_criteria_ucs(graph, start, goal, criteria_weights):
    """UCS with multiple edge criteria (time, distance, cost)"""
    # Each edge has multiple costs: (neighbor, [time, distance, money])
    # Combine using weighted sum: w1*time + w2*distance + w3*money
```

### Memory-Optimized UCS
```python
def memory_efficient_ucs(graph, start, goal):
    """UCS with reduced memory footprint"""
    # Use more compact data structures
    # Implement custom priority queue with better memory usage
    # Periodically clean up unnecessary entries
```

## Conclusion

UCS provides a robust, optimal solution for shortest path problems in weighted graphs. It strikes a balance between the simplicity of uninformed search and the efficiency of informed search, making it particularly valuable when:

- Optimal solutions are required
- Edge weights vary significantly
- No domain-specific heuristics are available
- Single source-destination queries are needed

While UCS may not be the fastest algorithm for all scenarios, its guarantee of optimality and relatively simple implementation make it a reliable choice for many pathfinding applications in weighted graphs.