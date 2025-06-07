#include <iostream>
#include <vector>
#include <algorithm>

// A struct to represent a ghost, bundling its position and stamina together.
// Using a struct makes the code cleaner and more readable.
struct Ghost {
    int position;
    int stamina;
};

/**
 * @brief Solves the Haunted Road problem.
 * @param N The total number of ghosts.
 * @param E The maximum energy allowed.
 * @param ghosts A vector of Ghost objects, pre-sorted by position.
 * @return The maximum number of ghosts that can be hunted.
 */
int solve(int N, long long E, const std::vector<Ghost>& ghosts) {
    // If there are no ghosts, we can't hunt any.
    if (N == 0) {
        return 0;
    }

    // We can always trap at least one ghost.
    int maxGhostsHunted = 1;

    // --- Main Loop: Iterate through each ghost, treating it as the "trap ghost" ---
    // The outer loop has a complexity of O(N).
    for (int i = 0; i < N; ++i) {
        const Ghost& trapGhost = ghosts[i];
        
        // --- Inner Step 1: Collect costs of all huntable ghosts ---
        // A ghost is huntable if it's to the right of the trap ghost
        // and has stamina greater than or equal to the trap ghost's stamina.
        std::vector<long long> huntCosts;
        for (int j = i + 1; j < N; ++j) {
            if (ghosts[j].stamina >= trapGhost.stamina) {
                // Cost calculation: (distance) * (stamina)
                // Use long long to prevent potential integer overflow.
                long long cost = (long long)(ghosts[j].position - trapGhost.position) * ghosts[j].stamina;
                huntCosts.push_back(cost);
            }
        }

        // --- Inner Step 2: Greedy approach to maximize hunts ---
        // To hunt the maximum number of ghosts, we should always pick the one
        // with the lowest energy cost first. So, we sort the costs.
        // Sort complexity: O(N log N) in the worst case.
        std::sort(huntCosts.begin(), huntCosts.end());

        long long currentEnergyUsed = 0;
        int currentGhostsHunted = 1; // Start with the trap ghost itself

        for (long long cost : huntCosts) {
            if (currentEnergyUsed + cost <= E) {
                currentEnergyUsed += cost;
                currentGhostsHunted++;
            } else {
                // If we can't afford this ghost, we can't afford any subsequent ones
                // either, since the costs are sorted.
                break;
            }
        }

        // Update the overall maximum.
        maxGhostsHunted = std::max(maxGhostsHunted, currentGhostsHunted);
    }

    return maxGhostsHunted;
}

int main() {
    // --- Input from the problem description ---
    // int L = 20; // L is not directly used in the logic but defines the road length.
    int N = 5;
    long long E = 100;
    std::vector<int> A = {2, 5, 10, 14, 18};
    std::vector<int> B = {3, 2, 4, 5, 6};

    // --- Data Preparation ---
    // 1. Combine the position and stamina arrays into a vector of Ghost structs.
    std::vector<Ghost> ghosts;
    for (int i = 0; i < N; ++i) {
        ghosts.push_back({A[i], B[i]});
    }

    // 2. Sort the ghosts by their position. This is crucial for the "move to the right" rule.
    // This allows us to simply iterate forward from a trap ghost.
    std::sort(ghosts.begin(), ghosts.end(), [](const Ghost& a, const Ghost& b) {
        return a.position < b.position;
    });

    // --- Call the solver and print the result ---
    int result = solve(N, E, ghosts);
    
    std::cout << "Maximum number of ghosts that can be hunted: " << result << std::endl;

    return 0;
}
