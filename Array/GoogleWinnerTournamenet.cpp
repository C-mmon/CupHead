#include <queue>
#include <vector>

bool isValid(const std::vector<int>& nums) {
    int len = nums.size();
    if (len % 2 != 0)
        return false;

    std::queue<int> queue;
    for (int num : nums) {
        queue.push(num);
    }

    while (queue.size() > 1) {
        int player1 = queue.front(); queue.pop();
        int player2 = queue.front(); queue.pop();

        if (player1 + player2 != len + 1)
            return false;

        queue.push(std::min(player1, player2));
    }

    return true;
}
