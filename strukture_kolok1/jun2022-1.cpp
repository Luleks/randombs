void GroupElements() {
	SLLNode* temp = head;
	while (temp->next != 0) {
		SLLNode* node = temp->next, *prev = temp;
		while (node != 0 and node->info != temp->info) {
			prev = node;
			node = node->next;
		}

		if (node == 0 or temp->next == node)
			temp = temp->next;
		else {
			prev->next = node->next;
			node->next = temp->next;
			temp->next = node;
			temp = node;
		}
	}
}