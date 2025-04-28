from collections import deque

def bfs(graph, source, visited):
    q = deque()
    visited[source] = True  
    q.append(source)

    while q:
        current = q.popleft()  
        print(current, end=" ")

        for neighbour in graph[current]:
            if not visited[neighbour]:
                visited[neighbour] = True 
                q.append(neighbour) 

def addEdge(graph, u, v):
    graph[u].append(v)
    graph[v].append(u)  

def bfs_disconnected(graph):
    visited = [False] * len(graph) 
    for i in range(len(graph)):
        if not visited[i]:  
            print(f"Connected component starting from node {i}: ", end="")
            bfs(graph, i, visited)  
            print() 

def main():
    V, E = map(int, input("Enter number of vertices and edges: ").split())
    graph = [[] for _ in range(V)] 

    print("Enter the edges (u, v):")
    for _ in range(E):
        u, v = map(int, input().split())  
        addEdge(graph, u, v)  
    
    print("\nBFS Traversal:")
    bfs_disconnected(graph) 

if __name__ == "__main__":
    main()
