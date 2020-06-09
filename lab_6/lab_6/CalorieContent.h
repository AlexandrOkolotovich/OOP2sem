#pragma once
#include<iostream>

#include "Food.h"

using namespace std;

class CalorieContent  : public Food{
private:
	int calorie;
	double proteins;
	double fats;
	double carbohydrates;
public:
	void add() {
		Food::add();
		cout << "������� ���������� ������� - ";
		calorie = numberTest();
		cout << "������� ���������� ������ - ";
		proteins = doubleTest();
		cout << "������� ���������� ����� - ";
		fats = doubleTest();
		cout << "������� ���������� ��������� - ";
		carbohydrates = doubleTest();
	}

	void show() {
		cout << left << setw(30) << nameFood << setw(20) << calorie << setw(20) << proteins << setw(20) << fats << setw(20) << carbohydrates << endl;
	}

	void setCalorie(int calorie) {
		this->calorie = calorie;
	}

	friend bool operator<(const CalorieContent& f1, const CalorieContent& f2);

	friend bool operator>(const CalorieContent& f1, const CalorieContent& f2);
};

//���������� ��������� <  
bool operator<(const CalorieContent& f1, const CalorieContent& f2) {

	return f1.calorie > f2.calorie;

}

//���������� ��������� > 
bool operator> (const CalorieContent& f1, const CalorieContent& f2) {
	return f1.calorie < f2.calorie;
}