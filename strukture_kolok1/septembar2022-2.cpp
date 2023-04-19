typedef unsigned int uint;

class Vreme {
private:
	int dan;
	int mesec;
	int godina;
	int sati;
	int minuti;
public:
	Vreme();
	Vreme(int, int, int, int, int);
	~Vreme();
	void print();
	bool istiDan(const Vreme& vreme);
};

class Ticket {
private:
	char* tablice;
	int parking_mesto;
	Datum datum;
	char* zona;
public:
	Ticket();
	Ticket(char*, int, Datum, char*);
	Ticket(const Ticket&);
	~Ticked();
	Ticket& operator=(const Ticket&);
	bool operator==(const Ticket&);
	char* getKey() {
		return tablice;
	}
	void print();
};

uint h(const char* key) {
	uint res = 0;
	const int a = 7;
	for (int i = 2; i < 6; i++)
		res = res << a ^ key[i];
	return h(res);
}

uint h(uint key) {
	const uint a = ;
	unsigned long long ak = a * key;
	return ak >> (32 - (int)log2(length));
}

bool wasFined(Ticket* ticket, Ticket* prevTicket) {
	if (ticket->parking_mesto == prevTicket->parking_mesto and ticket->getDatum().istiDan(prevTicket->getDatum()))
		return true;
	if (ticket->getZona() == prevTicket->getZone() and ticket->getDatum().istiDan(prevTicket->getDatum()))
		return true;
	return false;
}

bool fine(Ticket* ticket) {
	uint index = h(ticket.getKey());
	if (table[index].status == 2) {
		while (table[index].status == 2 and table[index].next != -1 and table[index].next != 0) {
			if (wasFined(ticket, table[index])
				return false;
			index = table[index].next
		}
		if (table[index].next == 0)
			throw exception("Previse izdatih kazni");
		table[index].next = lrmp;
		index = lrmp;
		lrmp = table[index].next;
	}
	table[index] = ticket;
	table[index].status = 2;
	table[index].next = -1;
	count += 1;
	return true;
}