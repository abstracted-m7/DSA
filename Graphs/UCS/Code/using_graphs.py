import heapq
from collections import defaultdict

class Graph:
    
    def __init__(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v, weight):
        # Add weighted edge to the graph
        self.graph[u].append((v, weight))
    
    def get_neighbors(self, node):
        return self.graph[node]

class UCS:
    
    def __init__(self, graph):
        self.graph = graph
    
    def search(self, start, goal):

        # Priority queue: (cost, node, path)
        priority_queue = [(0, start, [start])]
        
        # Set to keep track of visited nodes with their minimum cost
        visited = {}
        
        while priority_queue:
            current_cost, current_node, path = heapq.heappop(priority_queue)
            
            # Skip if we've already found a better path to this node
            if current_node in visited and visited[current_node] <= current_cost:
                continue
            
            # Mark node as visited with current cost
            visited[current_node] = current_cost
            
            # Check if goal is reached
            if current_node == goal:
                return path, current_cost
            
            # Explore neighbors
            for neighbor, edge_cost in self.graph.get_neighbors(current_node):
                new_cost = current_cost + edge_cost
                
                # Only add to queue if we haven't visited or found a better path
                if neighbor not in visited or visited[neighbor] > new_cost:
                    new_path = path + [neighbor]
                    heapq.heappush(priority_queue, (new_cost, neighbor, new_path))
        
        # Goal not found
        return None, float('inf')
    
    def search_with_details(self, start, goal):

        priority_queue = [(0, start, [start])]
        visited = {}
        nodes_explored = 0
        step_details = []
        
        while priority_queue:
            current_cost, current_node, path = heapq.heappop(priority_queue)
            nodes_explored += 1
            
            step_info = {
                'step': nodes_explored,
                'current_node': current_node,
                'current_cost': current_cost,
                'current_path': path.copy(),
                'queue_size': len(priority_queue)
            }
            step_details.append(step_info)
            
            if current_node in visited and visited[current_node] <= current_cost:
                continue
            
            visited[current_node] = current_cost
            
            if current_node == goal:
                return {
                    'path': path,
                    'cost': current_cost,
                    'nodes_explored': nodes_explored,
                    'step_details': step_details,
                    'success': True
                }
            
            for neighbor, edge_cost in self.graph.get_neighbors(current_node):
                new_cost = current_cost + edge_cost
                
                if neighbor not in visited or visited[neighbor] > new_cost:
                    new_path = path + [neighbor]
                    heapq.heappush(priority_queue, (new_cost, neighbor, new_path))
        
        return {
            'path': None,
            'cost': float('inf'),
            'nodes_explored': nodes_explored,
            'step_details': step_details,
            'success': False
        }

# Example usage and testing
def create_sample_graph():

    g = Graph()
    
    # Add edges (node1, node2, weight)
    g.add_edge('A', 'B', 2)
    g.add_edge('A', 'C', 3)
    g.add_edge('B', 'D', 4)
    g.add_edge('B', 'E', 5)
    g.add_edge('C', 'F', 6)
    g.add_edge('C', 'G', 7)
    g.add_edge('D', 'H', 8)
    g.add_edge('D', 'I', 9)
    
    return g


if __name__ == "__main__":

    def demonstrate_ucs():
        # Create sample graph
        graph = create_sample_graph()
        ucs = UCS(graph)
        
        #Test Cases
        test_cases = [
            ('A', 'I')
        ]

        #print section
        print()
        print(20*"==")
        
        # Detailed search example
        print("Detailed search from A to F with step details:")
        result = ucs.search_with_details('A', 'F')
        
        if result['success']:
            print(f"Path: {' -> '.join(result['path'])}")
            print(f"Cost: {result['cost']}")
            print(f"Nodes explored: {result['nodes_explored']}")
            print("\nStep-by-step details:")
            for step in result['step_details']:
                print(f" Step {step['step']}: Node={step['current_node']}, "
                      f"Cost={step['current_cost']}, Path={'->'.join(step['current_path'])}, "
                      f"Queue size={step['queue_size']}")
        else:
            print("No path found from A to F.")
        
        print("\nRunning basic UCS search on other test cases:")
        for start, goal in test_cases:
            if start == 'A' and goal == 'F':
                # Already done detailed search for this case
                continue
            path, cost = ucs.search(start, goal)
            if path is None:
                print(f"No path found from {start} to {goal}.")
            else:
                print(f"Path from {start} to {goal}: {' -> '.join(path)} with cost {cost}")

    demonstrate_ucs()
