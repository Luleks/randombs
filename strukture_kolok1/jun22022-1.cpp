// Jun 2 2022
SLinkedList<T>* SplitOrMove() {
	if (head == 0)
		return new SLinkedList();
	SLLNode<T>* new_head = 0, * new_temp = 0;
	SLLNode<T>* prev = 0, * cur = head;
	SLLNode<T>* prev1, *temp1;
	SLLNode<T>* to_be_izlancan = 0, *to_be_izlancan_prev = 0;
	while (cur != 0) {
		prev1 = cur;
		temp1 = cur->next;
		while (temp1 != 0 and temp1->info != cur->info) {
			prev1 = temp1;
			temp1 = temp1->next;
		}
		if (temp1 == 0) {
			to_be_izlancan = cur;
			to_be_izlancan_prev = prev;
			cur = cur->next;
		}
		else {
			to_be_izlancan = temp1;
			to_be_izlancan_prev = prev1;
			prev = cur;
			cur = cur->next;
		}
		if (to_be_izlancan_prev == 0)
			head = to_be_izlancan->next;
		else
			to_be_izlancan_prev->next = to_be_izlancan->next;
		if (new_head == 0) {
			new_head = to_be_izlancan;
			to_be_izlancan->next = 0;
			new_temp = new_head;
		}
		else {
			to_be_izlancan->next = 0;
			new_temp->next = to_be_izlancan;
			new_temp = new_temp->next;
		}
	}
	SLinkedList<T>* nova = new SLinkedList<T>();
	nova->head = new_head;
	return nova;
}