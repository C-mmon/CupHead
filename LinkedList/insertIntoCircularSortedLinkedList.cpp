class Node {
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };
    
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr = head;
        do {
            // Normal insertion point
            if (curr->val <= insertVal && insertVal <= curr->next->val) break;
            // Insert at rotation point
            if (curr->val > curr->next->val && 
               (insertVal >= curr->val || insertVal <= curr->next->val)) break;
            curr = curr->next;
        } while (curr != head);
        
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }