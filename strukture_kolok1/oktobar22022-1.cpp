void MoveMinToHead(SLLNode<T>* start) {
	SLLNode<T>* prev;
	if (start == head)
		prev = 0;
	else {
		prev = head;
		while (prev->next != start)
			prev = prev->next;
	}
	SLLNode<T>* min = start, *min_prev = prev;
	SLLNode<T>* temp = start->next, * prev_temp = start;
	while (temp != 0) {
		if (temp->info < min->info) {
			min_prev = prev_temp;
			min = temp;
		}
		prev_temp = temp;
		temp = temp->next;
	}
	if (min_prev != prev) {
		min_prev->next = min->next;
		if (prev == 0) {
			min->next = head;
			head = min;
		}
		else {
			min->next = prev->next;
			prev->next = min;
		}
	}
}
void SortList() {
	SLLNode<T>* prev = 0;
	for (SLLNode<T>* temp = head; temp->next != 0; ) {
		MoveMinToHead(temp);
		if ((prev == 0 and head == temp) or (prev != 0 and prev->next == temp)) {
			prev = temp;
			temp = temp->next;
		}
		else {
			if (prev == 0)
				prev = head;
			else
				prev = prev->next;
		}
	}
}