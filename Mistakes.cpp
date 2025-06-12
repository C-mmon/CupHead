//Creating dummy pointer
ListNode x(0);
//creatingref
ListNode dummy(0);       // actual object
ListNode* tail = &dummy; // pointer

dummy.next = new ListNode(5);   // dot — actual object
tail->next = new ListNode(6);   // arrow — pointer


-> Order of the execution statement matter, although logically to our brain, it looks good, but deep within it might be mesed.
executing statement A, before B
and changing the order can have drastic effect on the statement
