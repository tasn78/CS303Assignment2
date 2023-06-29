// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Single_Linked_List.hpp"
#include "Employees.h"
#include "Professional.h"
#include "Nonprofessional.h"

using namespace TS;

int main() {

	Single_Linked_List<std::string> names;
	names.push_back("Tom");
	names.push_back("Bill");
	names.push_front("Stacy");
	names.push_front("Lindsey");
	names.print();
	names.pop_front();
	names.print();
	std::string front = names.front();
	std::cout << "Front item : " << front << std::endl << std::endl;
	std::string back = names.back();
	std::cout << "Back item : " << back << std::endl << std::endl;
	names.empty();
	names.insert(1, "Mayumi");
	names.print();
	names.remove(0);
	names.print();
	int index1 = names.find("Tom");
	std::cout << "Tom is at index : " << index1 << std::endl << std::endl;
	names.find("Mayumi");
	int index2 = names.find("Mayumi");
	std::cout << "Mayumi is at index : " << index2 << std::endl << std::endl;
	names.print();



	Professional employee1(80000);
	employee1.setWeeklySalary();
	employee1.setVacationDays();
	employee1.setHealthContributions();

	Nonprofessional employee2(40);
	employee2.setWeeklySalary();
	employee2.setVacationDays();
	employee2.setHealthContributions();

	employee1.print();
	employee2.print();


	return 0;
}