//Modify the content of linked list 
#include <bits/stdc++.h>

using namespace std;
Node* reverseList(Node* head)
{
	Node* curr= head;
	Node* prev= NULL;
	Node* temp;
	while(curr != NULL)
	{
		temp = curr->next;
		curr->next= prev;
		prev= curr;
		curr = temp;
	} 
	return prev;
}

//remember for the odd based length, return the exact middle, for even based lengthh return the second middle
Node* middleList(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while(fast!= NULL && fast->next != NULL)
	{
		fast= fast->next->next;
		slow= slow->next;
	}
	return slow;
}
void modifyTheContent(Node* n)
{
	if (!head || !head->next) return;

    // 1. Find middle
    Node* mid = findMiddle(head);

    // 2. Reverse second half
    Node* second = reverseList(mid->next);
    mid->next = nullptr;

    // 3. Modify first half
    Node* first = head;
    Node* tempSecond = second;
    while (tempSecond) {
        first->data = first->data - tempSecond->data;
        first = first->next;
        tempSecond = tempSecond->next;
    }

    // 4. Optional: Restore second half
    mid->next = reverseList(second);
}
int main()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(3);
	l1.push_back(6);

	//find the middle of the linked list 
	auto it = l1.begin();
	while(it != NULL)
	{
		it= it->next;
	}
	return 0;
}
