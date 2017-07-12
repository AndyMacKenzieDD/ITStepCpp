#include "Date.h"
#include "RecordBook.h"
#include "Student.h"
int main()
{
	Date date;
	Date myBday(20, 12, 1991);
	std::cout << date.getDay() << " " << date.getMonth() << " " << date.getYear() << std::endl;
	std::cout << myBday.getDay() << " " << myBday.getMonth() << " " << myBday.getYear() << std::endl;
	
	//myBday.plusDate(16, 6, 25);
	myBday.plusDate(70);
	std::cout << myBday.getDay() << " " << myBday.getMonth() << " " << myBday.getYear() << std::endl;
	++myBday;
	std::cout << myBday.getDay() << " " << myBday.getMonth() << " " << myBday.getYear() << std::endl;
	--myBday;
	std::cout << myBday.getDay() << " " << myBday.getMonth() << " " << myBday.getYear() << std::endl;

	RecordBook book;
	book.printMarks();
	book.addMark("Phisical culture", 12);
	book.printMarks();
	std::cout << book.getMax().first << std::endl;
	std::cout << book.getAverage() << std::endl;
	std::cout << std::endl;
	Student st;
	Student st1("Savitski", "Andrew", "Valerievich", "B31016", 1, 20, 12, 1991);
	st1.printInfo();
	st1.setMarks();
	st1.addMark("Phisical culture", 12);
	st1.printInfo();
	return 0;
}