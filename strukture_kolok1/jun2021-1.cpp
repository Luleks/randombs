SLinkedList<T>* extractEven() {
	if (head == 0)
		return new SLinkedList<T>();
	SLLNode<T>* new_head = 0, * temp = 0;
	SLLNode<T>* prev = 0, * cur = head;
	while (cur != 0) {
		if (cur->info % 2 == 0) {
			if (prev == 0) 
				head = head->next;
			else
				prev->next = cur->next;
			cur->next = 0;
			if (new_head == 0) {
				new_head = cur;
				temp = new_head;
			}
			else {
				temp->next = cur;
				temp = cur;
			}
			if (prev == 0)
				cur = head;
			else
				cur = prev->next;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
	SLinkedList<T>* nova = new SLinkedList<T>();
	nova->head = new_head;
	return nova;
}