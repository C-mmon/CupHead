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
ListNode* reverse(ListNode* n, int count)
{
    ListNode* storeHead = n;
    ListNode* prev = NULL, *temp, *curr= n;
    while(curr != NULL && count)
    {
        temp = curr->next;
        curr->next= prev;
        prev= curr;
        curr = temp;
        count--;
    }
    storeHead->next = curr;
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //Handling the corner case;
        if(!head || left == right)
        {
            return head;
        }

        ListNode* store= head;
        ListNode dummy(0);
        dummy.next =  head;
        ListNode* findLeft = &dummy;

        int count = right-left+1;
        left--;
        while(left && findLeft)
        {
            findLeft = findLeft->next;
            left--;
        }
        findLeft->next= reverse(findLeft->next, count);
        return dummy.next;
    }
};
