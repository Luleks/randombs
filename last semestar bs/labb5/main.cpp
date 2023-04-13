#include "Bafer.h"
#include "Student.h"

int main() {
	Bafer<char, 10> b1;
	Bafer<Student, 10> b2;

	for (char i = 65; i < 75; i++) {
		b1.add(i);
		Student* s = new Student("Student" + to_string(i), "Prezime", 18000 + i, i / 10);
		b2.add(*s);
	}

	cout << b1;
	cout << endl;
	cout << b2;
	cout << endl;
	cout << b2.getLast();
	cout << endl;
	cout << b1.getFirst();
	cout << endl;
	return 0;
}