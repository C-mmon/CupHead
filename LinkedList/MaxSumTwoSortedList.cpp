int maxSumPath(Node* head1, Node* head2) {
    Node *p1 = head1, *p2 = head2;
    int sum1 = 0, sum2 = 0, result = 0;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            sum1 += p1->data;
            p1 = p1->next;
        } else if (p2->data < p1->data) {
            sum2 += p2->data;
            p2 = p2->next;
        } else {
            // Common node found
            result += max(sum1, sum2) + p1->data;
            sum1 = 0;
            sum2 = 0;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining nodes
    while (p1) {
        sum1 += p1->data;
        p1 = p1->next;
    }

    while (p2) {
        sum2 += p2->data;
        p2 = p2->next;
    }

    result += max(sum1, sum2);
    return result;
}
