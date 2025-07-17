Node* findTheNodeIntersection(Node* a, Node* b)
{
	Node* ptra= a;
	Node* ptrb=b;
	while(ptra != ptrb)
	{
		ptra= (ptra== NULL) ? b: ptra->next;
		ptrb= (ptrb== NULL) ? a: ptrb->next;
	}
	return ptra;
}
