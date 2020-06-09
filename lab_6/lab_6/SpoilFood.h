#pragma once

#include "Food.h"

class SpoilFood : public Food {
private:
	int time;
public:
	void add() {
		Food::add();
		cout << "Введите время за которое испортится еда - ";
		time = numberTest();
	}

	void show() {
		cout << left << setw(30) << nameFood << setw(20) << time << endl;
	}

	void setTime(int time) {
		this->time = time;
	}

};