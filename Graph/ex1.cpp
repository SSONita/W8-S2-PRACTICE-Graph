#include <iostream>
#include "utils/AdjacencyListGraph.hpp"
#include "utils/AdjacencyMatrixGraph.hpp"
#include "utils/EdgeListGraph.hpp"

int main() {
    int vertices = 12; 
    AdjacencyMatrixGraph matrixGraph(vertices);
    AdjacencyListGraph listGraph(vertices);
    EdgeListGraph edgeGraph;

    matrixGraph.AddEdge(0, 1, 12);
    matrixGraph.AddEdge(0, 2, 2);
    listGraph.AddEdge(0, 1, 12);
    listGraph.AddEdge(0, 2, 2);
    edgeGraph.AddEdge(0, 1, 12);
    edgeGraph.AddEdge(0, 2, 2);

    std::cout << "Adjacency Matrix:\n" << matrixGraph.ToString() << "\n";
    std::cout << "Adjacency List:\n" << listGraph.ToString() << "\n";
    std::cout << "Edge List:\n" << edgeGraph.ToString() << "\n";

    return 0;
}