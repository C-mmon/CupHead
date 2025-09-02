vector<int> store;
int sizeStore = store.size();

vector<vector<int>> cost(sizeStore, vector<int>(32, 0));

for (int x = 0; x < sizeStore; x++) {
    int val = store[x];
    for (int i = 0; i < 32; i++) {
        if ((val >> i) & 1) {
            cost[x][i] = (i > 0 ? cost[x][i - 1] : 0);
        } else {
            int add = 1 << i;
            cost[x][i] = add + (i > 0 ? cost[x][i - 1] : 0);
        }
    }
}

vector<vector<int>> prefix(sizeStore + 1, vector<int>(32, 0));

for (int i = 0; i < sizeStore; i++) {
    for (int b = 0; b < 32; b++) {
        prefix[i + 1][b] = prefix[i][b] + cost[i][b];
    }
}
