void swapNeighbors(DListNode* temp1) {
	if (temp1 == head) {
		head = temp1->next;
		temp1->next = temp1->next->next;
		temp1->next->prev = temp1;
		temp1->prev = head;
		head->next = temp1;
		head->prev = 0;
	}
	else {
		temp1->prev->next = temp1->next;
		temp1->next->prev = temp1->prev;
		temp1->prev = temp1->next;
		if (temp1->prev->next != 0)
			temp1->next = temp1->prev->next;
		else
			temp1->next = 0;
		temp1->prev->next = temp1;
		if (temp1->next != 0)
			temp1->next->prev = temp1;
	}
}

void swap(DListNode* node1, DListNode* node2) {
	if (node1 == node2)
		return;
	else if (node1->next == node2)
		swapNeighbors(node1);
	else {
		DListNode* prev1 = node1->prev;
		DListNode* prev2 = node2->prev;
		if (prev1 == 0) {
			head = node2;
			node2->prev = 0;
		}
		else {
			prev1->next = node2;
			node2->prev = prev1;
		}
		if (prev2 == 0) {
			head = node1;
			node1->prev == 0;
		}
		else {
			prev2->next = node1;
			node1->prev = prev2;
		}
		DListNode* next1 = node1->next;
		DListNode* next2 = node2->next;
		node1->next = next2;
		if (next2 != 0)
			next2->prev = node1;
		node2->next = next1;
		if (next1 != 0)
			next1->prev = node2;
	}
}

void exchange(int a, int b) {
	if (head == 0)
		return;
	DListNode* tempA = 0, * tempB = 0;
	DListNode* temp = head;
	while (temp != 0 && tempB == 0) {
		if (temp->info == a || temp->info == b)
			if (tempA == 0)
				tempA = temp;
			else
				tempB = temp;
		temp = temp->next;
	}
	if (tempB == 0)
		return;
	swap(tempA, tempB);
}