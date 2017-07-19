#include "List_Test.h"
#include <exception>
#include <iostream>

void List_Test::print_res(const char* test, bool res){
	std::cout << test << ":\t";
	if(res) {
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}
}

void List_Test::test1(){
	ForwardList<int> f_list;
	
	bool res = false;
	res = (f_list.size() == 0) ? true : false;
	print_res("Test 1a", res); 
	
	res = f_list.empty();
	print_res("Test 1b", res);
	std::cout << std::endl;
}

void List_Test::test2(){
	ForwardList<int> f_list;
	
	f_list.push_front(42);
	bool res = (f_list.size() == 1) ? true : false;
	print_res("Test 2a", res); 
	
	res = f_list.empty();
	print_res("Test 2b", !res);
	
	f_list.push_front(111);
	f_list.push_front(99);
	f_list.push_front(15);
	res = (f_list.size() == 4) ? true : false;
	print_res("Test 2c", res); 

	std::cout << "   Your answer: ";
	f_list.print();
	std::cout << "Correct answer: " << "15 99 111 42" << std::endl;	
	std::cout << std::endl;
}

void List_Test::test3(){
	ForwardList<int> f_list;
	
	f_list.push_back(55);
	bool res = (f_list.size() == 1) ? true : false;
	print_res("Test 3a", res); 
	
	res = f_list.empty();
	print_res("Test 3b", !res);
	
	f_list.push_back(12);
	f_list.push_back(16);
	f_list.push_back(18);
	res = (f_list.size() == 4) ? true : false;
	print_res("Test 3c", res); 
	
	std::cout << "   Your answer: ";
	f_list.print();
	std::cout << "Correct answer: " << "55 12 16 18" << std::endl;
	std::cout << std::endl;
}

void List_Test::test4(){
	ForwardList<int> f_list;
	
	f_list.push_front(3);
	f_list.push_back(4);
	f_list.push_front(2);
	f_list.push_back(5);
	f_list.push_front(1);
	bool res = (f_list.size() == 5) ? true : false;
	print_res("Test 4", res); 

	std::cout << "   Your answer: ";
	f_list.print();
	std::cout << "Correct answer: " << "1 2 3 4 5" << std::endl;
	std::cout << std::endl;
}

void List_Test::test5(){
	ForwardList<int> f_list;
	f_list.insert(0, 10);
	f_list.push_back(3);
	f_list.push_front(1);
	f_list.insert(2, 3);
	f_list.insert(1, 2);
	f_list.push_back(5);
	f_list.insert(4, 5);
	bool res = (f_list.size() == 6) ? true : false;
	print_res("Test 5a", res); 
	std::cout << "   Your answer: ";
	f_list.print();
	std::cout << "Correct answer: " << "1 3 2 1 5 4" << std::endl;
	f_list.insert(10, 0);
	std::cout << std::endl;
}

void List_Test::test6(){
	ForwardList<int> f_list;
	
	f_list.push_front(5);
	f_list.push_back(7);
	f_list.push_front(11);
	f_list.push_back(13);
	f_list.push_front(10);
	f_list.push_back(4);
	f_list.push_back(14);
	f_list.insert(9, 7);
	f_list.insert(0, 5);
	f_list.insert(1, 19);

	bool res = (f_list.size() == 9) ? true : false;
	print_res("Test 6a", res); 
	std::cout << "   Your answer: ";
	f_list.print();
	std::cout << "Correct answer: " << "10 11 5 0 7 9 13 4 14" << std::endl;
	std::cout << std::endl;
}

void List_Test::test7(){
	ForwardList<int> f_list;
	
	try {
		f_list.pop_front();
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}
	
	for (int i = 4; i >= 0; --i) {
		f_list.push_front(i);
	}
	bool res = true;
	for (unsigned int i = 0; i < 5; ++i){
		auto tmp = f_list.pop_front();
		if (tmp != i) {
			res = false;
			break;
		}
	}
	print_res("Test 7a", res);
	
	res = (f_list.size() == 0) ? true : false;
	print_res("Test 7b", res); 

	try {
		f_list.pop_front();
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
}

void List_Test::test8(){
	ForwardList<int> f_list;
	
	try {
		f_list.pop_back();
	}
	catch(std::exception& ex){

		std::cout << ex.what() << std::endl;
	}

	for (unsigned int i = 0; i < 100; ++i){
		f_list.push_back(i);
	}
	bool res = true;
	for (int i = 99; i >=0 ; --i){
		auto tmp = f_list.pop_back();
		if (tmp != i) {
			res = false;
			break;
		}
	}
	print_res("Test 8a", res);
	
	res = (f_list.size() == 0) ? true : false;
	print_res("Test 8b", res); 

	try {
		f_list.pop_back();
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
}

void List_Test::test9(){
	ForwardList<int> f_list;
	
	try {
		f_list.erase(10);
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}

	for (unsigned int i = 0; i < 100; ++i){
		f_list.push_back(i);
	}

	for (int i = 0; i < 20 ; ++i){
		f_list.erase(i);
	}

	for (int i = 99; i > 50; --i){
		f_list.erase(i);
	}
	
	for (int i = 21; i < 50; ++i){
		f_list.erase(i);
	}
	f_list.erase(20);
	f_list.erase(50);
	bool res = (f_list.size() == 0) ? true : false;
	print_res("Test 9", res); 

	try {
		f_list.erase(10);
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << std::endl;
}

void List_Test::test(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}
