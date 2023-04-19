typedef unsigned int uint;

uint h(const char* key){
	uint res = 0;
	const int a = 7;
	for (int i = 5; i > 0; i--)
		res = res << 7 ^ key[i];
	return h(res);
}

uint h(uint key){
	const uint a = 2654435769;
	unsigned long long ak = a * key;
	return ak >> (32 - (int)log2(length));
}

Radnik* lastSynonim(const char* key){
	uint prev = 0;
	uint index = h(key);
	if (table[index].status != 2)
		return null;
	while (table[index].next != -1) {
		prev = index;
		index = table[index].next;
	}
	Radnik* toReturn = table[index].getRecord();
	table[index].status = 1;
	if (prev != -1)
		table[prev].next = -1;
	return toReturn;
}