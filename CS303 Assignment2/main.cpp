// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Single_Linked_List.h"
#include "Employees.h"
#include "Professional.h"
#include "Nonprofessional.h"


int main() {

	Single_Linked_List<int> names;
	names.push_back(1);
	names.push_back(2);
	names.push_front(3);
	names.pop_front();
	names.front();
	names.back();
	names.empty();
	names.insert(1, 4);
	names.remove(2);
	names.find(3);
	names.find(4);



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