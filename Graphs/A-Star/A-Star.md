# A* Search Algorithm for Weighted Graphs

A Python implementation of the A* (A-star) pathfinding algorithm for finding the optimal path between cities in a weighted graph, using Manhattan or Euclidean distance heuristics.

## Table of Contents
- [Overview](#overview)
- [Algorithm Details](#algorithm-details)
- [Code Structure](#code-structure)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Heuristic Functions](#heuristic-functions)
- [Time and Space Complexity](#time-and-space-complexity)
- [Requirements](#requirements)

## Overview

This implementation provides a complete A* search algorithm for pathfinding in weighted graphs where:
- **Nodes** represent cities with (x, y) coordinates
- **Edges** represent roads with associated travel costs
- **Heuristics** guide the search using either Manhattan (L1) or Euclidean (L2) distance

The algorithm guarantees finding the optimal (lowest-cost) path from a start city to a destination city.

## Algorithm Details

### A* Search Algorithm

A* is an informed search algorithm that uses both:
1. **g(n)**: Actual cost from start to current node
2. **h(n)**: Heuristic estimate from current node to goal
3. **f(n) = g(n) + h(n)**: Total estimated cost

The algorithm maintains:
- **Open set**: Nodes to be evaluated (priority queue)
- **Closed set**: Nodes already evaluated (implicitly handled)
- **came_from**: Parent tracking for path reconstruction
- **g_score**: Actual cost from start to each node
- **f_score**: Estimated total cost through each node

### Key Properties
- **Optimal**: Finds the lowest-cost path when heuristic is admissible
- **Complete**: Will find a solution if one exists
- **Efficient**: Uses heuristic to guide search toward goal

## Code Structure

### Graph Class

```python
class Graph:
    def __init__(self):
        self.edges = {}      # city -> list of (neighbor_city, travel_cost)
        self.coordinates = {} # city -> (x, y)
```

**Methods:**
- `add_city(city, x, y)`: Adds a city with coordinates
- `add_road(city1, city2, cost)`: Adds bidirectional road with travel cost
- `heuristic(city1, city2, method)`: Calculates heuristic distance

### A* Search Function

```python
def a_star_search(graph, start, goal, heuristic_method='euclidean')
```

**Parameters:**
- `graph`: Graph instance containing cities and roads
- `start`: Starting city name
- `goal`: Destination city name
- `heuristic_method`: 'manhattan', 'euclidean', or other

**Returns:**
- `path`: List of cities from start to goal
- `cost`: Total travel cost of optimal path

## Features

### Supported Heuristics

1. **Manhattan Distance (L1 norm)**
   - Formula: `|x₁ - x₂| + |y₁ - y₂|`
   - Best for grid-like movement (4-directional)
   - Always admissible for grid graphs

2. **Euclidean Distance (L2 norm)**
   - Formula: `√[(x₁ - x₂)² + (y₁ - y₂)²]`
   - Best for straight-line movement
   - Always admissible (never overestimates)

3. **No Heuristic**
   - Falls back to Dijkstra's algorithm
   - Guaranteed optimal but slower

### Graph Properties

- **Undirected**: Roads are bidirectional by default
- **Weighted**: Each road has an associated travel cost
- **Coordinate-based**: Cities have (x, y) positions for heuristic calculation

## Usage

### Basic Setup

```python
# Create graph
g = Graph()

# Add cities with coordinates
g.add_city('CityA', x_coordinate, y_coordinate)
g.add_city('CityB', x_coordinate, y_coordinate)

# Add roads with costs
g.add_road('CityA', 'CityB', travel_cost)

# Find optimal path
path, cost = a_star_search(g, 'CityA', 'CityB', heuristic_method='euclidean')
```

### Advanced Usage

```python
# Using Manhattan heuristic
path, cost = a_star_search(g, start='A', goal='E', heuristic_method='manhattan')

# Using no heuristic (Dijkstra's algorithm)
path, cost = a_star_search(g, start='A', goal='E', heuristic_method='none')
```

## Example

The provided example creates a small graph with 5 cities:

```
Cities and Coordinates:
A (0,0) → B (2,2) → D (5,2) → E (6,0)
    ↓         ↓         ↑
    C (3,1) ←→→→→→→→→→→→→

Road Costs:
A-B: 3, A-C: 4, B-C: 1, B-D: 6, C-D: 2, D-E: 1
```

**Expected Output:**
```
Path: ['A', 'B', 'C', 'D', 'E']
Cost: 7
```

**Path Explanation:**
- A → B (cost: 3)
- B → C (cost: 1) 
- C → D (cost: 2)
- D → E (cost: 1)
- **Total: 7**

Alternative paths like A→C→D→E (cost: 7) or A→B→D→E (cost: 10) are either equally optimal or suboptimal.

## Heuristic Functions

### Admissibility

Both Manhattan and Euclidean distances are **admissible heuristics** because they never overestimate the actual cost to reach the goal. This ensures A* finds the optimal path.

### Consistency

For most practical graphs with reasonable edge costs, both heuristics are also **consistent** (monotonic), meaning:
`h(n) ≤ cost(n, n') + h(n')`

This property ensures efficient search without revisiting nodes.

### Choosing the Right Heuristic

- **Manhattan**: Better for grid-based maps, city blocks, or when movement is restricted to cardinal directions
- **Euclidean**: Better for open terrain, flight paths, or when diagonal movement is allowed
- **Performance**: Euclidean typically provides better guidance and faster search

## Time and Space Complexity

### Time Complexity
- **Worst case**: O(b^d) where b is branching factor, d is depth
- **Average case**: Much better than worst case due to heuristic guidance
- **Best case**: O(d) when heuristic perfectly guides to goal

### Space Complexity
- **O(b^d)** for storing open set and node information
- Dominated by open set size in practice

### Comparison with Other Algorithms
- **Dijkstra**: Guaranteed optimal, but explores more nodes (no heuristic)
- **Greedy Best-First**: Faster but not guaranteed optimal
- **BFS**: Optimal for unweighted graphs, but slower for weighted graphs

## Requirements

```python
import heapq  # For priority queue implementation
import math   # For square root in Euclidean distance
```

### Python Version
- Compatible with Python 3.6+
- No external dependencies required

## Implementation Notes

### Priority Queue
Uses Python's `heapq` module for efficient priority queue operations with O(log n) insert/extract.

### Path Reconstruction
Maintains `came_from` dictionary to rebuild the optimal path by backtracking from goal to start.

### Duplicate Handling
The algorithm naturally handles duplicate nodes in the priority queue by always processing the lowest f-score first.

### Memory Optimization
Initializes scores to infinity for all known nodes, allowing efficient comparison and updates.

## Potential Enhancements

1. **Bidirectional A***: Search from both start and goal simultaneously
2. **Jump Point Search**: Optimize for grid-based graphs
3. **Hierarchical Pathfinding**: Handle very large graphs efficiently
4. **Dynamic Re-planning**: Handle changing edge costs
5. **Multiple Goals**: Find paths to multiple destinations efficiently