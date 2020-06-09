#pragma once
#include <iostream>


using namespace std;

string wordTest() {
	string str;
	while (1) {
		try {
			rewind(stdin);
			getline(cin, str);
			for (char c : str) {
				if (c >= '0' && c <= '9') cin.clear(ios::failbit);
			}
			if (cin.good()) {
				cin.clear();
				return str;
			}
			else {
				cin.clear();
				throw 1;
			}
		}
		catch (int) {
			cout << "Введено число. Повторите попытку" << endl;
		}
	}
}

int numberTest() {
	cin.clear();
	int number;
	while (true) {
		rewind(stdin);
		cin.unsetf(ios::skipws);
		cin >> number;
		if (cin.good()) {
			cin.ignore(100, '\n');
			break;
		}
		cin.clear();
		cout << "Данные введенны неверно\n";
	}
	cin.clear();
	rewind(stdin);
	cin.setf(ios::skipws);
	return number;
}

double doubleTest() {
	cin.clear();
	string str;
	while (true) {
		rewind(stdin);
		cin.unsetf(ios::skipws);
		cin >> str;
		for (char c : str) {
			if ((c < '0' || c > '9') && c != '.') cin.clear(ios::failbit);
		}
		if (cin.good()) {
			cin.ignore(100, '\n');
			break;
		}
		cin.clear();
		cout << "Данные введенны неверно\n";
		cin.ignore(100, '\n');
	}
	cin.clear();
	rewind(stdin);
	cin.setf(ios::skipws);
	return atof(str.c_str());
}

class Food {
protected:
	string nameFood;
public:
	void add() {
		cout << "Введите наименование продукта - ";
		nameFood = wordTest();
	}

	string getNamefood() {
		return nameFood;
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