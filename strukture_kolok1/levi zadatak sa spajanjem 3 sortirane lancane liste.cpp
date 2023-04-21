static LList* merge(LList* l1, LList* l2, LList* l3) {
	LListNode* temp1 = l1->getHead(), * temp2 = l2->getHead(), * temp3 = l3->getHead();
	LListNode* head = 0, * cur = 0;
	while (temp1 != 0 && temp2 != 0 && temp3 != 0) {
		LListNode** temp;
		if (temp1->info <= temp2->info && temp1->info <= temp3->info)
			temp = &temp1;
		else if (temp2->info <= temp1->info && temp2->info <= temp3->info)
			temp = &temp2;
		else
			temp = &temp3;
		if (head == 0) {
			head = *temp;
			*temp = (*temp)->next;
			cur = head;
			cur->next = 0;
		}
		else {
			cur->next = *temp;
			cur = *temp;
			*temp = (*temp)->next;
			cur->next = 0;
		}
	}
	if (temp1 == 0)
		temp1 = temp3;
	else if (temp2 == 0)
		temp2 = temp3;
	while (temp1 != 0 && temp2 != 0) {
		LListNode** temp;
		if (temp1->info < temp2->info)
			temp = &temp1;
		else
			temp = &temp2;
		cur->next = *temp;
		cur = *temp;
		*temp = (*temp)->next;
		cur->next = 0;
	}
	while (temp1 != 0) {
		cur->next = temp1;
		cur = temp1;
		temp1 = temp1->next;
		cur->next = 0;
	}
	while (temp2 != 0) {
		cur->next = temp2;
		cur = temp2;
		temp1 = temp2->next;
		cur->next = 0;
	}
	LList* nova = new LList();
	nova->head = head;
	return nova;
}