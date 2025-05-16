/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // storing the head
        // need to count the nodes
        ListNode* count = head;
        int counter = 0;
        while (count != NULL) {
            count = count->next;
            counter++;
        }
        k = k % counter;
        if (k != 0) {
            ListNode* store = head;
            for (int i = 0; i < counter- k-1 ; i++) {
                store = store->next;
            }
            ListNode* temp = store->next;
            ListNode* ans = temp;
            store->next = NULL;
            // now reaching the end
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = head;
            return ans;
        }
        return head;
    }
};