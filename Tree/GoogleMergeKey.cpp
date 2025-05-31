The problem:
You have two trees: A and B. Each node has a key and a value, plus children.

You want to create a new merged tree with these rules:

If a node appears only in A, keep it as is (key and value from A).

If a node appears only in B, keep it as is (key and value from B).

If a node appears in both A and B (same key), create a new node with:

the key from A (or B, they are the same key),

the value from B,

and merge their children recursively with the same rules.

// Merge Function
shared_ptr<Node> mergeTrees(shared_ptr<Node> a, shared_ptr<Node> b) {
    if (!a) return b;
    if (!b) return a;

    // Merge root node: keep key, use value from B
    auto merged = make_shared<Node>(a->key, b->value);

    // Index A's children by key
    unordered_map<string, shared_ptr<Node>> aChildrenMap;
    for (auto& child : a->children)
        aChildrenMap[child->key] = child;

    unordered_set<string> seenKeys;

    // Add merged children from A first (and recursively merge if needed)
    for (auto& childA : a->children) {
        if (aChildrenMap.count(childA->key)) {
            shared_ptr<Node> childB = nullptr;
            for (auto& child : b->children) {
                if (child->key == childA->key) {
                    childB = child;
                    break;
                }
            }
            merged->children.push_back(mergeTrees(childA, childB));
        } else {
            merged->children.push_back(childA);
        }
        seenKeys.insert(childA->key);
    }

    // Add children from B that are not already added
    for (auto& childB : b->children) {
        if (seenKeys.count(childB->key) == 0) {
            merged->children.push_back(childB);
        }
    }

    return merged;
}
