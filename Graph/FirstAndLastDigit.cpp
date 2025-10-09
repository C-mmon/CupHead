// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// To store the array elements
vector<string> arr;

// Adjacency list for the graph nodes
vector<vector<int> > graph;

// To store the euler path
vector<string> path;

// Print eulerian path
bool print_euler(int i, int visited[], int count)
{
    // Mark node as visited
    // and increase the count
    visited[i] = 1;
    count++;

    // If all the nodes are visited
    // then we have traversed the euler path
    if (count == graph.size()) {
        path.push_back(arr[i]);
        return true;
    }

    // Check if the node lies in euler path
    bool b = false;

    // Traverse through remaining edges
    for (int j = 0; j < graph[i].size(); j++)
        if (visited[graph[i][j]] == 0) {
            b |= print_euler(graph[i][j], visited, count);
        }

    // If the euler path is found
    if (b) {
        path.push_back(arr[i]);
        return true;
    }

    // Else unmark the node
    else {
        visited[i] = 0;
        count--;
        return false;
    }
}

// Function to create the graph and
// print the required path
void connect()
{
    int n = arr.size();
    graph.clear();
    graph.resize(n);

    // Connect the nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            // If the last character matches with the
            // first character
            if (arr[i][arr[i].length() - 1] == arr[j][0]) {
                graph[i].push_back(j);
            }
        }
    }

    // Print the path
    for (int i = 0; i < n; i++) {
        int visited[n] = { 0 }, count = 0;

        // If the euler path starts
        // from the ith node
        if (print_euler(i, visited, count))
            break;
    }

    // Print the euler path
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0)
            cout << " ";
    }
}
// Driver code
int main()
{
    arr.push_back("451");
    arr.push_back("378");
    arr.push_back("123");
    arr.push_back("1254");

    // Create graph and print the path
    connect();

    return 0;
}
