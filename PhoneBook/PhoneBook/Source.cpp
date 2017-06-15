#include "Contact.h"
#include "PhoneBook.h"

void test()
{
	PhoneBook pb;
	//pb.addContact();
	pb.addContact("Andrew", "950-05-68", "+375(44)567-90-60");
	pb.addContact("Dima", "850-08-00", "+375(29)987-46-26");
	pb.addContact("Kirill", "710-05-00", "+375(29)783-46-53");
	pb.showAll();
	//pb.showContact();
	pb.deleteContact();
	pb.showAll();
}

int  main()
{
	test();

	return 0;
}
