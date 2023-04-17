 int MoveHigher(int value) {
	if (head == 0)
		return 0;
	SLLNode<T>* prev;
	if (head->info > value)
		prev = head;
	else
		prev = 0;
	SLLNode<T>* prev1 = head, *temp = head->next;
	while (temp != 0) {
		if (temp->info > value) {
			if (prev == 0) {
				prev1->next = temp->next;
				temp->next = head;
				head = temp;
				prev = head;
				temp = prev1->next;
			}
			else if (prev->next != temp) {
				prev1->next = temp->next;
				temp->next = prev->next;
				prev->next = temp;
				prev = temp;
				temp = prev1->next;
			}
			else {
				prev = prev->next;
				prev1 = temp;
				temp = temp->next;
			}
		}
		else {
			prev1 = temp;
			temp = temp->next;
		}
	}
	return 0;
}
