#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>


using namespace std;

class EdgeListGraph {
private:
    std::vector<std::tuple<int, int, int>> edgeList;

public:
    void AddEdge(int u, int v, int weight) {
        edgeList.emplace_back(u, v, weight);
        edgeList.emplace_back(v, u, weight); // Undirected graph
    }

    void RemoveEdge(int u, int v) {
        edgeList.erase(std::remove_if(edgeList.begin(), edgeList.end(),
                                      [u, v](const std::tuple<int, int, int>& edge) {
                                          return (std::get<0>(edge) == u && std::get<1>(edge) == v) ||
                                                 (std::get<0>(edge) == v && std::get<1>(edge) == u);
                                      }),
                       edgeList.end());
    }

    std::string ToString() {
    std::ostringstream os;
    for (const auto& edge : edgeList) {
        int u = std::get<0>(edge);  
        int v = std::get<1>(edge);  
        int weight = std::get<2>(edge);  
        os << "(" << u << ", " << v << ", " << weight << ")\n";
    }
    return os.str();
}

};