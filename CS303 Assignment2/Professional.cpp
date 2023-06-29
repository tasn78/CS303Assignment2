// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Professional.h"

// Default constructor
Professional::Professional() {
	salary = 0;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

// Overloaded constructor
Professional::Professional(float yearlySalary) : Employee () {
	salary = yearlySalary;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

// Sets weekly pay based on salary
void Professional::setWeeklySalary() {
	weeklyPay = this->salary / 52.0;
}

// Sets vacation days based on salary, $75,000 or less = 18, more than $75,000 gets 25 days
void Professional::setVacationDays() {
	if (this->salary < 75000) {
		vacationDays = 18;
	}
	else {
		vacationDays = 25;
	}
}

// Sets health contributions based on salary * 15% paid on a weekly basis
void Professional::setHealthContributions() {
	healthContributions = this->salary * 0.15 / 52.0;
}

// Prints all professional information
void Professional::print() {
	std::cout << "Employee Type : Professional" << std::endl;
	std::cout << "Salary : $" << this->salary << std::endl;
	std::cout << "Weekly salary : $" << std::fixed << std::setprecision(2) << this->weeklyPay << std::endl;
	std::cout << "Vacation days : " << this->vacationDays << std::endl;
	std::cout << "Health care contributions per week : $" << std::fixed << std::setprecision(2) << this->healthContributions << std::endl << std::endl;
}
;