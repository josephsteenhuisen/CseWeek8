#include "adjacency_list.h"
#include <iostream>

void readGraph(const std::string& filename, std::vector<std::vector<int>>& adjList, int& numEdges) {
    std::ifstream inputFile(filename); 
    if (!inputFile) {
        throw std::runtime_error("Failed to open file " + filename);
    }
    int a, b;
    inputFile >> a >> b;
    adjList.resize(a);
    for (int i = 0; i < b; i++) {
        int u, v;
        inputFile >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    numEdges = b;
}
const std::vector<int>& adj(const std::vector<std::vector<int>>& adjList, int node) {
    if (node < 0 || node >= adjList.size()) {
        throw std::out_of_range("Invalid index " + std::to_string(node));
    }
    return adjList[node];
}
