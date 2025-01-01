#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class AdjacencyListGraph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    AdjacencyListGraph(int vertices) {
        adjList.resize(vertices);
    }

    void AddEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // Undirected graph
    }

    void RemoveEdge(int u, int v) {
    auto removeEdgeFromList = [](std::vector<std::pair<int, int>>& list, int target) {
        list.erase(std::remove_if(list.begin(), list.end(),
                                  [target](const std::pair<int, int>& edge) { return edge.first == target; }),
                   list.end());
        };
    removeEdgeFromList(adjList[u], v);
    removeEdgeFromList(adjList[v], u); // Ensure bidirectional removal
    }

    std::string ToString() {
    std::ostringstream os;
    for (size_t i = 0; i < adjList.size(); ++i) {
        os << i << ": ";
        for (const auto& edge : adjList[i]) {
            int neighbor = edge.first;
            int weight = edge.second;
            os << "(" << neighbor << ", " << weight << ") ";
        }
        os << "\n";
    }
    return os.str();
}

};