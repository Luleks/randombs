// Septembar 2021
void aggregateByValue(int points) {
	SLLNode<T>* first = head;
	while (first != 0 and first->info != points)
		first = first->next;
	if (first == 0)
		return;
	SLLNode<T>* niz = first;
	SLLNode<T>* prev = first, * cur = first->next;
	while (cur != 0) {
		if (cur->info == points and niz->next != cur) {
			prev->next = cur->next;
			cur->next = niz->next;
			niz->next = cur;
			niz = niz->next;
			cur = prev->next;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
}