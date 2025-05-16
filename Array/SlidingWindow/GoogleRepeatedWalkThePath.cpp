#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <unordered_map> // For Q2

// Q1: Find the longest continuous streak of color c.
// n: length of the path (blockColors.size())
// targetColor: the specific color to find the streak for
int findLongestStreakQ1(const std::vector<int>& blockColors, int targetColor) {
    int n = blockColors.size();
    if (n == 0) {
        return 0;
    }

    int maxStreak = 0;
    int currentStreak = 0;

    for (int i = 0; i < n; ++i) {
        if (blockColors[i] == targetColor) {
            currentStreak++;
        } else {
            // If the color changes, the streak for targetColor is broken.
            // Update maxStreak with the streak that just ended (if it was for targetColor).
            // This check is implicitly handled by currentStreak being 0 if it wasn't targetColor.
            maxStreak = std::max(maxStreak, currentStreak);
            currentStreak = 0; // Reset for other colors
        }
    }
    // Final check for a streak that goes to the end of the path
    maxStreak = std::max(maxStreak, currentStreak);

    return maxStreak;
}

// Q2: Suppose we have many guests now, each with their own fav color. 
// For each guest, return the max beauty based on their favorite color.
// This function calculates the max beauty for ALL colors present in the path.
// Guests can then look up their favorite color in the returned map.
// n: length of the path (blockColors.size())
std::unordered_map<int, int> getMaxBeautyPerColorQ2(const std::vector<int>& blockColors) {
    int n = blockColors.size();
    std::unordered_map<int, int> maxBeautyMap;

    if (n == 0) {
        return maxBeautyMap;
    }

    int currentStreak = 0;
    int currentColor = -1; // Assuming colors are non-negative integers. Use a value not in color range.
                           // If blockColors can be empty or colors can be negative, adjust initialization.

    for (int i = 0; i < n; ++i) {
        if (blockColors[i] == currentColor) {
            currentStreak++;
        } else {
            // Color changed. Update max beauty for the previous color's streak.
            if (currentColor != -1) { // Check if currentColor was actually set
                 // If currentColor is not in map, it defaults to 0, then max is taken.
                maxBeautyMap[currentColor] = std::max(maxBeautyMap[currentColor], currentStreak);
            }
            // Reset for the new color
            currentColor = blockColors[i];
            currentStreak = 1;
        }
        // Crucial: Update the max beauty for the *current* color's ongoing streak at each step.
        // This ensures that even if a color appears only once or its streak is short,
        // it's correctly recorded. It also handles the last streak correctly.
        maxBeautyMap[currentColor] = std::max(maxBeautyMap[currentColor], currentStreak);
    }
    // The line above inside the loop handles the final streak as well.
    // No explicit post-loop update is needed for the last streak due to this.

    return maxBeautyMap;
}


// Q3: Let's go back to having 1 guest. Suppose you could repaint m blocks to any color. 
// Find the max beauty value if we could repaint m blocks for a specific favoriteColor.
// n: length of the path (blockColors.size())
// favoriteColor: the guest's favorite color
// m: the number of blocks that can be repainted
int findMaxBeautyWithRepaintsQ3(const std::vector<int>& blockColors, int favoriteColor, int m) {
    int n = blockColors.size();
    if (n == 0) {
        return 0;
    }

    int maxLen = 0;
    int left = 0;
    int otherColorCount = 0; // Count of colors in the current window that are NOT favoriteColor

    for (int right = 0; right < n; ++right) {
        // If the current block is not the favorite color, increment count of blocks to repaint
        if (blockColors[right] != favoriteColor) {
            otherColorCount++;
        }

        // If the number of blocks to repaint exceeds m, shrink the window from the left
        while (otherColorCount > m) {
            if (blockColors[left] != favoriteColor) {
                otherColorCount--; // We are removing a block that needed repainting
            }
            left++; // Shrink window
        }

        // The current window [left, right] is valid (uses at most m repaints)
        // Update the maximum length found so far
        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    // Example Path: [1, 1, 2, 3, 3, 3, 1, 2, 2, 2]
    // n = 10
    std::vector<int> path1 = {1, 1, 2, 3, 3, 3, 1, 2, 2, 2};
    int n1 = path1.size();

    // --- Q1 Demo ---
    std::cout << "--- Q1: Longest Streak ---" << std::endl;
    int targetColor1 = 1;
    std::cout << "Longest streak of color " << targetColor1 << ": " << findLongestStreakQ1(path1, targetColor1) << std::endl; // Expected: 2
    int targetColor2 = 3;
    std::cout << "Longest streak of color " << targetColor2 << ": " << findLongestStreakQ1(path1, targetColor2) << std::endl; // Expected: 3
    int targetColor4 = 4; // Color not in path
    std::cout << "Longest streak of color " << targetColor4 << ": " << findLongestStreakQ1(path1, targetColor4) << std::endl; // Expected: 0
    std::vector<int> pathEmpty = {};
    std::cout << "Longest streak (empty path) of color 1: " << findLongestStreakQ1(pathEmpty, 1) << std::endl; // Expected: 0
    std::vector<int> pathSingleColor = {5,5,5,5};
    std::cout << "Longest streak of color 5 in [5,5,5,5]: " << findLongestStreakQ1(pathSingleColor, 5) << std::endl; // Expected: 4


    // --- Q2 Demo ---
    std::cout << "\n--- Q2: Max Beauty Per Color ---" << std::endl;
    std::unordered_map<int, int> beautyMap1 = getMaxBeautyPerColorQ2(path1);
    std::cout << "Max beauty for path1:" << std::endl;
    for (const auto& pair : beautyMap1) {
        std::cout << "Color " << pair.first << ": " << pair.second << std::endl;
    }
    // Expected for path1: Color 1: 2, Color 2: 3, Color 3: 3

    std::vector<int> path2 = {1, 1, 1, 2, 1, 1, 3, 3, 1};
    // Streaks of 1: 3, 2, 1. Max for 1 is 3.
    // Streaks of 2: 1. Max for 2 is 1.
    // Streaks of 3: 2. Max for 3 is 2.
    std::unordered_map<int, int> beautyMap2 = getMaxBeautyPerColorQ2(path2);
    std::cout << "Max beauty for path2 {1,1,1,2,1,1,3,3,1}:" << std::endl;
    for (const auto& pair : beautyMap2) {
        std::cout << "Color " << pair.first << ": " << pair.second << std::endl;
    }
    // Expected for path2: Color 1: 3, Color 2: 1, Color 3: 2

    std::unordered_map<int, int> beautyMapEmpty = getMaxBeautyPerColorQ2(pathEmpty);
    std::cout << "Max beauty for empty path:" << std::endl;
    for (const auto& pair : beautyMapEmpty) {
        std::cout << "Color " << pair.first << ": " << pair.second << std::endl; // Expected: (nothing printed)
    }


    // --- Q3 Demo ---
    std::cout << "\n--- Q3: Max Beauty With Repaints ---" << std::endl;
    // Path: [1, 1, 2, 3, 3, 3, 1, 2, 2, 2], n=10
    int favColorQ3_1 = 1;
    int mQ3_1 = 1; // Can repaint one block

    std::cout << "Path: {1,1,2,3,3,3,1,2,2,2}, FavColor: " << favColorQ3_1 << ", m: " << mQ3_1 << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path1, favColorQ3_1, mQ3_1) << std::endl; // Expected: 3 ([1,1,2] -> [1,1,1]) or ([1,2] -> [1,1] etc)

    int favColorQ3_2 = 2;
    int mQ3_2 = 3;
    std::cout << "Path: {1,1,2,3,3,3,1,2,2,2}, FavColor: " << favColorQ3_2 << ", m: " << mQ3_2 << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path1, favColorQ3_2, mQ3_2) << std::endl; // Expected: 6 ([3,3,1,2,2,2] -> [2,2,2,2,2,2] by changing 3,3,1)

    std::vector<int> path3 = {1,0,0,1,0,1,0,0,0,1}; // n=10
    int favColorQ3_3 = 1;
    int mQ3_3 = 2;

    std::cout << "Path: {1,0,0,1,0,1,0,0,0,1}, FavColor: " << favColorQ3_3 << ", m: " << mQ3_3 << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path3, favColorQ3_3, mQ3_3) << std::endl; // Expected: 4

    std::vector<int> path4 = {1,1,1,1,1};
    std::cout << "Path: {1,1,1,1,1}, FavColor: 1, m: 2" << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path4, 1, 2) << std::endl; // Expected: 5

    std::vector<int> path5 = {0,0,0,0,0};
    std::cout << "Path: {0,0,0,0,0}, FavColor: 1, m: 2" << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path5, 1, 2) << std::endl; // Expected: 2 (can make two 1s)

    std::cout << "Path: {0,0,0,0,0}, FavColor: 1, m: 5" << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3(path5, 1, 5) << std::endl; // Expected: 5 (can make all 1s)
    
    std::cout << "Path: {}, FavColor: 1, m: 5" << std::endl;
    std::cout << "Max beauty: " << findMaxBeautyWithRepaintsQ3({}, 1, 5) << std::endl; // Expected: 0


    return 0;
}

