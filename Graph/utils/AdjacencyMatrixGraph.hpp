#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

class AdjacencyMatrixGraph {
private:
    std::vector<std::vector<int>> matrix;
    int numVertices;

public:
    AdjacencyMatrixGraph(int vertices) : numVertices(vertices) {
        matrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void AddEdge(int u, int v, int weight) {
        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }

    void RemoveEdge(int u, int v) {
        matrix[u][v] = 0;
        matrix[v][u] = 0; 
    }

    std::string ToString() {
        std::ostringstream os;
        for (const auto& row : matrix) {
            for (int val : row) {
                os << std::setw(3) << val;
            }
            os << "\n";
        }
        return os.str();
    }
};