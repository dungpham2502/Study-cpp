#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>

class Graph {
private:
    bool directed;
    int numVertices;
    // Adjacency Matrix representation
    std::vector<std::vector<bool> > adjMatrix;
    std::vector<std::list<int> > adjList;

public:
    // Constructor
    Graph(int vertices, bool isDirected = false) {
        numVertices = vertices;
        directed = isDirected;
        
        // Initialize adjacency matrix with false values
        adjMatrix.resize(vertices);
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i].resize(vertices, false);
        }
        
        // Initialize adjacency list
        adjList.resize(vertices);
    }
    
    // Add edge to the graph
    void addEdge(int src, int dest) {
        // Validate vertices
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            std::cout << "Invalid vertices" << std::endl;
            return;
        }
        
        // Update adjacency matrix
        adjMatrix[src][dest] = true;
        
        // Update adjacency list
        adjList[src].push_back(dest);
        
        // If graph is undirected, add reverse edge
        if (!directed) {
            adjMatrix[dest][src] = true;
            adjList[dest].push_back(src);
        }
    }
    
    // Remove edge from the graph
    void removeEdge(int src, int dest) {
        // Validate vertices
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            std::cout << "Invalid vertices" << std::endl;
            return;
        }
        
        // Update adjacency matrix
        adjMatrix[src][dest] = false;
        
        // Update adjacency list
        adjList[src].remove(dest);
        
        // If graph is undirected, remove reverse edge
        if (!directed) {
            adjMatrix[dest][src] = false;
            adjList[dest].remove(src);
        }
    }
    
    // Check if edge exists
    bool hasEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            return false;
        }
        return adjMatrix[src][dest];
    }
    
    // Print adjacency matrix
    void printMatrix() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << (adjMatrix[i][j] ? "1 " : "0 ");
            }
            std::cout << std::endl;
        }
    }
    
    // Print adjacency list
    void printList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << " -> ";
            for (std::list<int>::const_iterator it = adjList[i].begin(); it != adjList[i].end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }
    
    // Get all neighbors of a vertex
    std::list<int> getNeighbors(int vertex) {
        if (vertex < 0 || vertex >= numVertices) {
            return std::list<int>();
        }
        return adjList[vertex];
    }

    void DFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) {
            std::cout << "Invalid starting vertex" << std::endl;
            return;
        }
        std::vector<bool> visited(numVertices, false);
        std::cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
        std::cout << std::endl;
    }

    void DFSUtil(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        for (std::list<int>::const_iterator it = adjList[vertex].begin(); it != adjList[vertex].end(); ++it) {
            if (!visited[*it]) {
            DFSUtil(*it, visited);
            }
        }
    }

    void BFS(int startVertex) {
        if (startVertex < 0 || startVertex >= numVertices) {
            std::cout << "Invalid starting vertex" << std::endl;
            return;
        }
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;
        
        // Mark the starting vertex as visited and add it to the queue
        visited[startVertex] = true;
        queue.push(startVertex);

        std::cout << "BFS starting from vertex " << startVertex << ": ";

        while (!queue.empty()) {
            int vertex = queue.front();
            queue.pop();
            std::cout << vertex << " ";

            // Store the neighbors in a variable to avoid dangling iterator
            std::list<int> neighbors = getNeighbors(vertex);
            for (std::list<int>::const_iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    // Create an undirected graph with 5 vertices
    Graph g(5);
    
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    // Print the graph representations
    g.printMatrix();
    std::cout << std::endl;
    g.printList();
    
    // Test edge existence
    std::cout << "\nEdge from 0 to 1 exists: " 
              << (g.hasEdge(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge from 0 to 2 exists: " 
              << (g.hasEdge(0, 2) ? "Yes" : "No") << std::endl;
    
    // Remove an edge and verify
    std::cout << "\nRemoving edge 1-4" << std::endl;
    g.removeEdge(1, 4);
    g.printList();

    g.DFS(0);    

    g.BFS(0);
    
    
    return 0;
}