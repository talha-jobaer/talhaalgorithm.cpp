#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Structure to represent an edge in the graph
struct Edge {
    int src;   // Source vertex
    int dest;  // Destination vertex
    int weight; // Weight of the edge
};

// Comparator function to sort edges by weight
bool compareEdge(const Edge& a, const Edge& b) {
    return a.weight < b.weight; // Sort edges in ascending order by weight
}

// Union-Find (Disjoint Set Union) data structure for Kruskal's algorithm
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        // Initialize each node as its own parent (root of its set)
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        // Path compression: make the parent point to the root of the set
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) {
            // They are in the same set, forming a cycle
            return false;
        }

        // Union by rank: attach smaller tree to larger tree
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }

        return true; // Union successful
    }

private:
    std::vector<int> parent; // Parent array for the disjoint set
    std::vector<int> rank;   // Rank array for balancing the trees
};

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
std::vector<Edge> kruskal(int numVertices, const std::vector<Edge>& edges) {
    // Step 1: Sort edges by weight
    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), compareEdge);

    // Step 2: Create a Union-Find data structure
    UnionFind uf(numVertices);

    // Step 3: Select edges for the MST
    std::vector<Edge> mst; // Vector to store the selected edges for the MST
    for (const auto& edge : sortedEdges) {
        if (uf.unionSets(edge.src, edge.dest)) {
            mst.push_back(edge); // Edge doesn't form a cycle, so add to MST
        }
    }

    return mst; // Return the resulting MST
}

// Main function to demonstrate Kruskal's algorithm
int main() {
    // Number of vertices and edges
    int numVertices = 5;
    int numEdges = 7;

    // Define the edges with source, destination, and weight
    std::vector<Edge> edges = {
        {0, 1, 2}, // Edge from vertex 0 to 1 with weight 2
        {0, 3, 6}, // Edge from vertex 0 to 3 with weight 6
        {1, 2, 3}, // Edge from vertex 1 to 2 with weight 3
        {1, 3, 8}, // Edge from vertex 1 to 3 with weight 8
        {1, 4, 5}, // Edge from vertex 1 to 4 with weight 5
        {2, 4, 7}, // Edge from vertex 2 to 4 with weight 7
        {3, 4, 9}  // Edge from vertex 3 to 4 with weight 9
    };

    // Run Kruskal's algorithm to get the MST
    std::vector<Edge> mst = kruskal(numVertices, edges);

    // Output the result
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        std::cout << "Edge (" << edge.src << " -> " << edge.dest << "), Weight: " << edge.weight << "\n";
    }

    return 0;
}