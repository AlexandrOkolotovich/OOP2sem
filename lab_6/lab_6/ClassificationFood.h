#pragma once
#include "Food.h"

class ClassificationFood : public Food {
private:
	string classification;
public:
	void add() {
		Food::add();
		cout << "¬ведите тип еды - ";
		classification = wordTest();
	}

	void show() {
		cout << left << setw(30) << nameFood << setw(20) << classification << endl;
	}

	void setClassification(string classification) {
		this->classification = classification;
	}
};