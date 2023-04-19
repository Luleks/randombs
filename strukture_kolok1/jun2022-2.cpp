typedef unsigned int uint;

uint h(const char* key) {
	uint res = 0;
	for (int i = 11; i > 6; i--)
		res = res  << 7 ^ key[i];
	return h(res);
}

uint h(uint key) {
	const uint a = ;
	unsigned long long ak = a * key;
	return ak >> (32 - (int)log2(length));
}

void withdraw(const char* key) {
	uint index = h(key);
	if (table[index].status != 2)
		return;
	uint prev = -1;
	while (index != -1 and index != 0 and strcmp(table[index].getKey(), key) != 0) {
		prev = index;
		index = table[index].next;
	}
	if (prev == -1 and table[index].next == -1) {
		table[index].status = 1;
	}
	else if (prev == -1 and table[index].next != -1) {
		prev = index;
		index = table[index].next;
		table[prev] = table[index];
		table[index].next = lrmp;
		table[index].status = 1;
		lrmp = index;
	}
	else {
		table[prev].next = table[index].next;
		table[index].status = 1;
		table[index].next = lrmp;
		lrmp = index;
	}
	count -= 1;
}