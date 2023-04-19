typedef unsigned int uint;


uint h(const char* key){
	uint res = 0;
	const int a = 7;
	int cifre[] = {0, 1, 3, 6, 12}
	for (int i = 0; i < 5; i++) {
		res = res << a ^ key[cifre[i]];
	}
	return h(res);
}

uint h(uint key){
	const uint a = 2654435769;
	unsigned long long ak = a * key;
	return ak >> (32 - (int)log2(length));
}

void insert(ScatterObject obj){
	if (length == count)
		throw exception("Tablica je puna");
	uint probe = h(obj.getKey());
	if (table[probe].status == 2) {
		while (strcmp(table[probe].getKey(), obj.getKey()) != 0 and table[probe].next != -1 and table[probe].next != 0)
			probe = table[probe].next;
		if (table[probe].next == 0)
			throw exception("Pun izdvojen deo za sinonime");
		else if (strcmp(table[probe].getKey(), obj.getKey()) == 0)
			throw exception("Student je vec u tablici");
		table[probe].next = lrmp;
		probe = lrmp;
		lrmp = table[probe].next;
	}
	table[probe] = obj;
	table[probe].status = 2;
	table[probe].next = -1;
	count += 1;
}

bool find(ScatterObject obj) {
	uint probe = h(obj.getKey());
	if (table[probe].status != 2)
		return false;
	while (probe != -1 and probe != 0 and strcmp(obj.getKey(), table[probe].getKey()))
		probe = table[probe].next;
	if (probe == -1 or probe == 0)
		return false;
	return true;
}
