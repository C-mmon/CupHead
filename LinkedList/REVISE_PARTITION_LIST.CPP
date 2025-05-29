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
    ListNode* partition(ListNode* head, int x) {
        ListNode before (0);
        ListNode after (0);
        ListNode* beforeCurr = &before;
        ListNode* afterCurr = &after;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val < x)
            {
                beforeCurr->next= temp;
                beforeCurr = temp;
            }
            else
            {
                afterCurr->next= temp;
                afterCurr = temp;
            }
            temp = temp->next;
        }
        afterCurr->next= NULL;
        beforeCurr->next = after.next;
        
return before.next;

    }
};
