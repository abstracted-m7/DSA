# A* Search Algorithm on Weighted Graph of Cities

This repository contains a Python implementation of the A* search algorithm to find the lowest-cost path between cities connected by roads with travel costs. The graph nodes represent cities with `(x, y)` coordinates, and edges represent roads with weighted travel costs.

## Features

- **Weighted graph** representation with cities as nodes.
- Roads between cities with travel costs as edge weights.
- Heuristic options:
  - **Manhattan (L1) distance**
  - **Euclidean (L2) distance**
- Finds the lowest-cost path between a start city and a goal city using A* search.

---

## Usage

### Graph Construction

- Add cities with their coordinates (used for heuristic calculations).
- Add roads between cities with travel costs.

### Running the Search

Call the `a_star_search` function with the graph, start city, goal city, and the heuristic method (`'manhattan'` or `'euclidean'`).

### Example

```python
# Create graph instance
g = Graph()

# Add cities (city_name, x_coord, y_coord)
g.add_city('A', 0, 0)
g.add_city('B', 2, 2)
g.add_city('C', 3, 1)
g.add_city('D', 5, 2)
g.add_city('E', 6, 0)

# Add roads (city1, city2, cost)
g.add_road('A', 'B', 3)
g.add_road('A', 'C', 4)
g.add_road('B', 'C', 1)
g.add_road('B', 'D', 6)
g.add_road('C', 'D', 2)
g.add_road('D', 'E', 1)

# Perform A* search
path, cost = a_star_search(g, 'A', 'E', heuristic_method='manhattan')

print(f"Path: {path}, Cost: {cost}")


### Output - 
Path: ['A', 'B', 'C', 'D', 'E'], Cost: 7
