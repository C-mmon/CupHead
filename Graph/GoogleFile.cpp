unordered_map<int, int> memo; // store the size against the entity ID

int dfs(int entityId) {
    // Check if already computed
    if (memo.find(entityId) != memo.end()) {
        return memo[entityId];
    }

    const Entity& entity = fileSystem[entityId];

    if (entity.type == "file") {
        return memo[entityId] = entity.size;
    }

    int currSize = 0;
    for (int childId : entity.childrenIds) {
        currSize += dfs(childId);
    }

    return memo[entityId] = currSize;
}

// Function to calculate size of given entity ID
int calculateSize(int entityId) {
    return dfs(entityId);
}
