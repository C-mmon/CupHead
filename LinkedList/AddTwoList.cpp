class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* temp;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        // skip leading zeros
        while (num1 && num1->data == 0) num1 = num1->next;
        while (num2 && num2->data == 0) num2 = num2->next;

        if (!num1 && !num2) return new Node(0);
        if (!num1) return num2;
        if (!num2) return num1;

        // reverse both lists
        Node* h1 = reverse(num1);
        Node* h2 = reverse(num2);

        Node* dummy = new Node(0);
        Node* curr = dummy;
        int carry = 0;

        while (h1 || h2 || carry) {
            int sum = carry;
            if (h1) {
                sum += h1->data;
                h1 = h1->next;
            }
            if (h2) {
                sum += h2->data;
                h2 = h2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        return reverse(dummy->next);
    }
};
