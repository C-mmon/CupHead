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
    ListNode* reverveList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = reverveList(head);
        ListNode* iterate = temp;
        int maxSoFar = INT_MIN;
        ListNode* prev = NULL;
        while (temp) {
            if (temp->val < maxSoFar) {
                prev->next = temp->next; //REMOVE THE CURRENT NODE
            }
            else
            {
                prev = temp;
                maxSoFar = max(maxSoFar, temp->val);
            }
            
            temp = temp->next;
        }
        ListNode* store = reverveList(iterate);
        return store;
    }
};
