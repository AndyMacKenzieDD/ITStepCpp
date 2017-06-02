#include "Student.h"

void test()
{
	Student st1("Andrew", "Savitsky", "Valer'evich", "Gomel", "Named after F. Skaryna", 1991, "+375 44 567 90 60", "P31060");
	st1.printStudentInfo();
	st1.setName("Dmitriy", "Kolotusha", "Bat'kovich");
	st1.setCity("Minsk");
	st1.setPhone("+375 12 345 67 89");
	st1.printStudentInfo();
}

int main()
{
	test();

	return 0;
}