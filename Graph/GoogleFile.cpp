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

//if the interviewer ask what if we are visiting the same files again and again, use a unordered set 
Test Case	Why It’s Tricky
Empty FileSystem	calculateSize() must handle gracefully
EntityID not found	Should not crash; return -1 or throw exception
Cycle in structure	Should be caught with visited set
Shared subdirectories or files	Should be re-visited unless memoized
Multiple roots	Need to be handled if not starting from a single known root
Directory with zero children	Should return 0
Deep nesting (10,000 levels)	Check for stack overflow risk, may need iterative DFS
