#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <map>
#include <Windows.h>
#include <string>

using namespace std;

class Employee {
	string fio;
	string education;
	int experience;
	int age;
public:
	Employee() {
		fio = "null";
		education = "null";
		experience = 0;
		age = 0;
	}
	Employee(string fio, string education, int experience, int age) {
		this->fio = fio;
		this->education = education;
		this->experience = experience;
		this->age = age;
	}
	void set_name(string fio) {
		this->fio = fio;
	}
	void set_education(string education) {
		this->education = education;
	}
	void set_experience(int experience) {
		this->experience = experience;
	}
	void set_age(int age) {
		this->age = age;
	}
	string get_fio() {
		return fio;
	}
	string get_education() {
		return education;
	}
	int get_experience() {
		return experience;
	}
	int get_age() {
		return age;
	}
	bool operator<(Employee a) {
		return fio < a.fio;
	}
};

template <class T>
T Check()
{
	T i;
	try {
		while (!(cin >> i) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			throw "Ошибка ввода. Повторите попытку";
		}
		return i;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

list<Employee> empl_list;
map<string, string> map_result;

void main_menu();
void employee_menu();
void result_menu();
void add_employee();
bool exh_name(string);
void view_all_empl();
string get_employee_info(Employee);
void change_employee();
void find_employee();
void create_result(string);
void view_all_result();
string get_find_result(string);
void change_result(string);
void delete_result(string);
