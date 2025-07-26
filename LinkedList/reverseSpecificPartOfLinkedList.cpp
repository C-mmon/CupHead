if (!head || left == right) return head;

ListNode dummy(0);
dummy.next = head;
ListNode* leftPrev = &dummy;

// Move leftPrev to the node before `left`
for (int i = 1; i < left; i++) {
    leftPrev = leftPrev->next;
}

// Reverse the sublist from `left` to `right`
ListNode* curr = leftPrev->next;
ListNode* prev = nullptr;
for (int i = left; i <= right; i++) {
    ListNode* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
}

// Adjust pointers to link the reversed sublist
leftPrev->next->next = curr;  // Connect end of reversed sublist to rightNext
leftPrev->next = prev;        // Connect leftPrev to new head of reversed sublist

return dummy.next;


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
//reverse logic is correct
ListNode* reverse(ListNode* n, int count)
{
    ListNode* store = n, *curr=n, *prev= NULL, *temp;
    while(count-- && curr != NULL)
    {
        temp = curr->next;
        curr->next= prev;
        prev= curr;
        curr= temp;
    }
    n->next= curr;
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //we dont need to reer
        if (!head || left == right) return head;
        ListNode* temp = head;
        ListNode dummy(0);
        dummy.next= head;

        ListNode* prev = &dummy;
        for(int i=1; i<left; i++)
        {
            prev=prev->next;
        }
        ListNode* start = prev->next;

        prev->next = reverse(prev->next, right - left + 1);
        return dummy.next;
    }
};
/*
Let's understand different scenarios:

1. When left == right (No reversal needed):
   Input: 1->2->3->4->5, left = 2, right = 2
   Output: 1->2->3->4->5
   Explanation: Since left equals right, no reversal is needed
   
2. When left = 1 (Reversing from head):
   Input: 1->2->3->4->5, left = 1, right = 3
   
   Without dummy node:
   - Initial: head = 1->2->3->4->5
   - Need special case to update head
   - Complex pointer manipulation when starting from head
   
   With dummy node:
   dummy->1->2->3->4->5
   After reversal: dummy->3->2->1->4->5
   - Simply return dummy->next as new head
   - No special cases needed
   
3. Reversing entire list (left = 1, right = n):
   Input: 1->2->3->4->5, left = 1, right = 5
   
   Without dummy node:
   - Need to track new head explicitly
   - Need special handling for last node
   
   With dummy node:
   dummy->1->2->3->4->5
   After reversal: dummy->5->4->3->2->1
   - dummy->next automatically points to new head (5)
   - Clean uniform approach works for all cases

Key Benefits of Dummy Node:
1. Uniform handling: No special cases needed
2. Always have a valid leftPrev pointer
3. Easy head updates: dummy->next always points to correct head
4. Simplified pointer manipulation at boundaries
*/

//### **Why Use a Dummy Node?**

1. **Handles Edge Cases When Reversing from Head (`left == 1`)**
- If `left == 1`, `leftPrev` should be `nullptr` (i.e., there is no node before `left`).
- Without a dummy node, we would need extra conditions to handle the case where we need to update `head`.
- Using a dummy node, `leftPrev` is always a valid pointer, even when `left == 1`.
2. **Simplifies Pointer Manipulation**
- Normally, you need special handling if `leftPrev` is `nullptr` (when `left == 1`).
- With a dummy node, `leftPrev` is never `nullptr`, so we can safely do `leftPrev->next = prev` without checking for `nullptr`.
3. **Ensures `head` Remains Accessible**
- If the first node is reversed, `head` must be updated to the new head of the reversed sublist.
- The dummy node ensures `head = dummy.next` always holds the correct updated list.
