#from collections import deque
from collections import defaultdict

def dfs(graph, node, visited):
    visited[node] = True  
    print(node, end=" ")

    for neighbour in graph[node]:
        if not visited[neighbour]:
            dfs(graph, neighbour, visited)

def addEdge(graph, u, v):
    graph[u].append(v)
    graph[v].append(u)  

def dfs_disconnected(graph):
    visited = [False] * len(graph) 
    for i in range(len(graph)):
        if not visited[i]:  
            print(f"Connected component starting from node {i}: ", end="")
            dfs(graph, i, visited)  
            print() 

def main():
    V, E = map(int, input("Enter number of vertices and edges: ").split())
    graph = defaultdict(list) 

    print("Enter the edges (u, v):")
    for _ in range(E):
        u, v = map(int, input().split())  
        addEdge(graph, u, v)  
    
    print("\nDFS Traversal:")
    dfs_disconnected(graph) 

if __name__ == "__main__":
    main()

