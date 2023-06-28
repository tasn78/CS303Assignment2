// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Professional.h"

Professional::Professional() {
	salary = 0;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}


Professional::Professional(float yearlySalary) : Employee () {
	salary = yearlySalary;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

void Professional::setWeeklySalary() {
	weeklyPay = this->salary / 52.0;
}
void Professional::setVacationDays() {
	if (this->salary < 75000) {
		vacationDays = 18;
	}
	else {
		vacationDays = 25;
	}
}
void Professional::setHealthContributions() {
	healthContributions = this->salary * 0.15 / 52.0;
}

void Professional::print() {
	std::cout << "Employee Type : Professional" << std::endl;
	std::cout << "Salary : $" << this->salary << std::endl;
	std::cout << "Weekly salary : $" << std::fixed << std::setprecision(2) << this->weeklyPay << std::endl;
	std::cout << "Vacation days : " << this->vacationDays << std::endl;
	std::cout << "Health care contributions per week : $" << std::fixed << std::setprecision(2) << this->healthContributions << std::endl << std::endl;
}
;