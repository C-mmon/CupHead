#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits> // For numeric_limits

// Function to perform BFS from a given source node
// Returns a map where keys are nodes and values are their shortest distances from the source.
std::map<int, int> bfs(int num_nodes, const std::map<int, std::vector<int>>& adj, int start_node) {
    std::map<int, int> distances;

    // Initialize all distances to infinity
    for (int i = 0; i < num_nodes; ++i) {
        distances[i] = std::numeric_limits<int>::max();
    }

    std::queue<int> q;

    // Set distance of start_node to 0 and add to queue
    distances[start_node] = 0;
    q.push(start_node);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Check if the node exists in the adjacency list
        if (adj.count(u)) {
            for (int v : adj.at(u)) {
                // If neighbor 'v' is not visited (distance is still infinity)
                if (distances[v] == std::numeric_limits<int>::max()) {
                    distances[v] = distances[u] + 1; // Distance is 1 more than current node
                    q.push(v);
                }
            }
        }
    }
    return distances;
}

// Function to solve the follow-up problem: 3 friends meeting and going to a 4th friend
long long solve_three_friends_to_fourth(
    int num_nodes,
    const std::vector<std::pair<int, int>>& edges,
    int friend1,
    int friend2,
    int friend3,
    int friend4) {

    // Build the adjacency list
    std::map<int, std::vector<int>> adj;
    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first); // Undirected graph
    }

    // Perform BFS from each of the four relevant nodes
    std::map<int, int> dist1 = bfs(num_nodes, adj, friend1);
    std::map<int, int> dist2 = bfs(num_nodes, adj, friend2);
    std::map<int, int> dist3 = bfs(num_nodes, adj, friend3);
    std::map<int, int> dist4 = bfs(num_nodes, adj, friend4);

    long long min_total_distance = std::numeric_limits<long long>::max();

    // Iterate through all possible meeting points
    for (int m = 0; m < num_nodes; ++m) {
        if (dist1[m] == std::numeric_limits<int>::max() ||
            dist2[m] == std::numeric_limits<int>::max() ||
            dist3[m] == std::numeric_limits<int>::max() ||
            dist4[m] == std::numeric_limits<int>::max()) {
            continue;
        }

        // Calculate the total path length
        long long current_total_distance =
            static_cast<long long>(dist1[m]) +
            static_cast<long long>(dist2[m]) +
            static_cast<long long>(dist3[m]) +
            static_cast<long long>(dist4[m]);

        min_total_distance = std::min(min_total_distance, current_total_distance);
    }

    // If no valid path exists
    if (min_total_distance == std::numeric_limits<long long>::max()) {
        return -1;
    }
    return min_total_distance;
}

// Example usage
int main() {
    int num_nodes = 6;
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}
    };

    int f1 = 0, f2 = 1, f3 = 2, f4 = 5;

    long long result = solve_three_friends_to_fourth(num_nodes, edges, f1, f2, f3, f4);
    if (result != -1) {
        std::cout << "Minimum total distance: " << result << std::endl;
    } else {
        std::cout << "No valid path exists." << std::endl;
    }

    return 0;
}
