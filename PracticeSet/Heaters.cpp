class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
sort(houses.begin(), houses.end());
sort(heaters.begin(), heaters.end());

int radius = 0, i = 0;

for (int house : houses) {
    // Move to the heater closest on the left or equal to the house
    while (i + 1 < heaters.size() && abs(heaters[i + 1] - house) <= abs(heaters[i] - house)) {
        i++;
    }
    radius = max(radius, abs(heaters[i] - house));
}

return radius;
    }
};
