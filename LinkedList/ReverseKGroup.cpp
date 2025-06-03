class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        ListNode* curr = head;

        // Count total nodes
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        curr = head;

        while (count >= k) {
            // `prev` will move with the reversed nodes
            ListNode* prev = nullptr;
            ListNode* tail = curr;

            // Reverse k nodes
            for (int i = 0; i < k; ++i) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the previous part with the reversed group
            prevGroupEnd->next = prev;

            // Connect the reversed group with the remaining part
            tail->next = curr;

            // Move prevGroupEnd to the tail (now end of reversed group)
            prevGroupEnd = tail;
            count -= k;
        }

        return dummy.next;
    }
};
