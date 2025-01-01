#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <tuple>

using namespace std;

class Graph {
private:
    vector<tuple<int, int>> edgeList;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        adjList.resize(vertices);
    }

    void AddEdge(int u, int v) {
        edgeList.emplace_back(u, v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFSRecursive(int startVertex) {
        unordered_set<int> visited;
        DFSRecursiveHelper(startVertex, visited);
    }

    void DFSRecursiveHelper(int vertex, unordered_set<int>& visited) {
        visited.insert(vertex);
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSRecursiveHelper(neighbor, visited);
            }
        }
    }

    void DFSIterative(int startVertex) {
        unordered_set<int> visited;
        stack<int> s;
        s.push(startVertex);
        visited.insert(startVertex);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            cout << vertex << " ";

            // Push neighbors in reverse order to simulate recursion
            for (int i = adjList[vertex].size() - 1; i >= 0; --i) {
                int neighbor = adjList[vertex][i];
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    s.push(neighbor);
                }
            }
        }
    }

    void BFS(int startVertex) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(startVertex);
        visited.insert(startVertex);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

    void Display() {
        cout << "Edge List:\n";
        for (const auto& edge : edgeList) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            cout << "(" << u << ", " << v << ")\n";
        }

        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\nAdjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);

    g.AddEdge(0, 1);
    g.AddEdge(0, 4);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(3, 4);

    cout << "Graph Structure:\n";
    g.Display();

    cout << "\nDFS (Recursive) starting from vertex 0:\n";
    g.DFSRecursive(0);

    cout << "\nDFS (Iterative) starting from vertex 0:\n";
    g.DFSIterative(0);

    cout << "\nBFS starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}
