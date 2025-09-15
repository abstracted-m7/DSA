
import heapq
import math

class Graph:
    def __init__(self):
        self.edges = {}  # city -> list of (neighbor_city, travel_cost)
        self.coordinates = {}  # city -> (x, y)

    def add_city(self, city, x, y):
        self.coordinates[city] = (x, y)
        if city not in self.edges:
            self.edges[city] = []

    def add_road(self, city1, city2, cost):
        self.edges[city1].append((city2, cost))
        self.edges[city2].append((city1, cost))  # assuming undirected roads

    #heuristic calculation
    def heuristic(self, city1, city2, method='euclidean'):
        x1, y1 = self.coordinates[city1]
        x2, y2 = self.coordinates[city2]
        if method == 'manhattan':
            return abs(x1 - x2) + abs(y1 - y2)
        elif method == 'euclidean':
            return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
        else:
            return 0  # no heuristic

    #print the graph's details
    def __str__(self):
        result = "Cities and coordinates:\n"
        for city, (x, y) in self.coordinates.items():
            result += f"  {city}: ({x}, {y})\n"
        result += "Roads and costs:\n"
        for city, neighbors in self.edges.items():
            for neighbor, cost in neighbors:
                # To avoid duplicate edges in undirected graph, only print if city < neighbor alphabetically
                if city < neighbor:
                    result += f"  {city} <-> {neighbor} : cost {cost}\n"
        return result

#A-star search function
def a_star_search(graph, start, goal, heuristic_method):
    open_set = []
    heapq.heappush(open_set, (0, start))  # (f_score, city)
    
    came_from = {}  # to reconstruct path
    
    g_score = {city: float('inf') for city in graph.edges}
    g_score[start] = 0
    
    f_score = {city: float('inf') for city in graph.edges}
    f_score[start] = graph.heuristic(start, goal, heuristic_method)
    
    while open_set:
        current_f, current = heapq.heappop(open_set)
        
        if current == goal:
            # reconstruct path
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, g_score[goal]
        
        for neighbor, cost in graph.edges[current]:
            tentative_g = g_score[current] + cost
            
            if tentative_g < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score[neighbor] = tentative_g + graph.heuristic(neighbor, goal, heuristic_method)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))
    
    return None, float('inf')  # no path found


# main function
if __name__ == "__main__":
    g = Graph()
    # Add cities with coordinates
    g.add_city('A', 0, 0)
    g.add_city('B', 2, 2)
    g.add_city('C', 3, 1)
    g.add_city('D', 5, 2)
    g.add_city('E', 6, 0)

    # Add roads with travel costs
    g.add_road('A', 'B', 3)
    g.add_road('A', 'C', 4)
    g.add_road('B', 'C', 1)
    g.add_road('B', 'D', 6)
    g.add_road('C', 'D', 2)
    g.add_road('D', 'E', 1)

    heuristic_method = input("Choise method [manhattan, euclidean]: ")
    path, cost = a_star_search(g, 'A', 'E', heuristic_method)
    print(f"Graph Details:\n{g}")
    print(f"Path: {path}, Cost: {cost}")
