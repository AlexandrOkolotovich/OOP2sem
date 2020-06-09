#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>

#include "ClassificationFood.h"
#include "SpoilFood.h"
#include "CalorieContent.h"

void addFood();
void viewFood();
void editingFood();

stack<ClassificationFood> stackClFood;
queue<SpoilFood> queueSpFood;
priority_queue<CalorieContent> pqCalorie;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) {
		system("cls");

		int choice;

		cout << std::right << std::setw(50) << "����" << endl
			<< " 1. ���������� ��������� �������" << endl
			<< " 2. ��������" << endl
			<< " 3. ��������������"<<endl
			<< " 0. �����" << endl
			<< " ��� ����� - ";

		do {
			choice = Check<int>();
			if (choice < 0 || choice > 3) cout << "����������� �������" << endl;
		} while (choice < 0 || choice > 3);

		switch (choice)
		{
		case 1:
			addFood();
			break;
		case 2:
			viewFood();
			break;
		case 3:
			editingFood();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}

void addFood() {
	while (1) {
		system("cls");

		int choice;

		cout << std::right << std::setw(50) << "����������" << endl
			<< " 1. ����������� ������ ��������� ������� �� ���� ���������" << endl
			<< " 2. ����������� ������ ��������� ������� �� ����� ��������" << endl
			<< " 3. ����������� ������ ��������� ������� �� �����������" << endl
			<< " 0. �����" << endl
			<< " ��� ����� - ";

		do {
			choice = Check<int>();
			if (choice < 0 || choice > 3) cout << "����������� �������" << endl;
		} while (choice < 0 || choice > 3);

		switch (choice)
		{

		case 1: {
			system("cls");
			ClassificationFood clFood;
			clFood.add();
			stackClFood.push(clFood);

			system("pause");
		}
			  break;
		case 2: {
			system("cls");
			SpoilFood  spFood;
			spFood.add();
			queueSpFood.push(spFood);

			system("pause"); }
			  break;
		case 3: {
			system("cls");
			CalorieContent calorieContent;

			calorieContent.add();
			pqCalorie.push(calorieContent);

			system("pause"); }
		break;

		case 0:
			return;
			break;

		}

	}
}

void viewFood() {
	while (1) {
		system("cls");

		int choice;

		cout << std::right << std::setw(50) << "��������" << endl
			<< " 1. �������� ������ ��������� ������� �� ���� ���������" << endl
			<< " 2. �������� ������ ��������� ������� �� ����� ��������" << endl
			<< " 3. �������� ������ ��������� ������� �� �����������" << endl
			<< " 0. �����" << endl
			<< " ��� ����� - ";

		do {
			choice = Check<int>();
			if (choice < 0 || choice > 3) cout << "����������� �������" << endl;
		} while (choice < 0 || choice > 3);

		switch (choice)
		{

		case 1: {
			system("cls");
			stack<ClassificationFood> temp;
			temp = stackClFood;
			while (!temp.empty()) {
				temp.top().show();
				temp.pop();
			}

			system("pause");
			system("cls");

		}
			  break;
		case 2: {
			system("cls");
			queue<SpoilFood> temp;
			temp = queueSpFood;
			while (!temp.empty()) {
				temp.front().show();
				temp.pop();
			}

			system("pause");
			system("cls");

		}
			  break;
		case 3: {
			system("cls");
			CalorieContent calorieContent;
			priority_queue<CalorieContent> temp;
			temp = pqCalorie;
			while (!temp.empty()) {
				calorieContent = temp.top();
				calorieContent.show();
				temp.pop();
			}

			system("pause");
			system("cls");
		}
			  break;

		case 0:
			return;
			break;

		}

	}
}

void editingFood() {
	while (1) {
		system("cls");

		int choice;

		cout << std::right << std::setw(50) << "��������������" << endl
			<< " 1. ������������� ��� ���������" << endl
			<< " 2. ������������� ���� ��������" << endl
			<< " 3. ������������� �����������" << endl
			<< " 0. �����" << endl
			<< " ��� ����� - ";

		do {
			choice = Check<int>();
			if (choice < 0 || choice > 3) cout << "����������� �������" << endl;
		} while (choice < 0 || choice > 3);

		switch (choice)
		{

		case 1: {
			string nameFood;
			cout << "������������ ��������, ������� ���������� �������� - ";
			nameFood = wordTest();
			stack<ClassificationFood> temp;

			ClassificationFood clFood;
			int flag = 0;
			while (!stackClFood.empty()) {
				if (stackClFood.top().getNamefood() == nameFood) {
					clFood = stackClFood.top();
					stackClFood.pop();
					flag = 1;
				}
				else {
					temp.push(stackClFood.top());
					stackClFood.pop();
				}
			}
			stackClFood = temp;
			if (flag == 0) {
				cout << "�� ����������." << endl;
			}
			else {
				string classification;
				cout << "������� ����� ��� ��� - ";
				classification = wordTest();
				clFood.setClassification(classification);
				stackClFood.push(clFood);

			}

			system("pause");
		}
			  system("cls");
			  break;
		case 2: {
			string nameFood;
			cout << "������������ ��������, ������� ���������� �������� - ";
			nameFood = wordTest();
			queue<SpoilFood> temp;

			SpoilFood spFood;
			int flag = 0;
			while (!queueSpFood.empty()) {

				if (queueSpFood.front().getNamefood() == nameFood) {
					spFood = queueSpFood.front();
					queueSpFood.pop();
					flag = 1;
				}
				else {
					temp.push(queueSpFood.front());
					queueSpFood.pop();
				}

			}
			queueSpFood = temp;
			if (flag == 0) {
				cout << "�� ����������." << endl;
			}
			else {
				int time;

				cout << "������� ������ ���� �������� - ";
				time = numberTest();
				spFood.setTime(time);
				queueSpFood.push(spFood);

			}

			system("pause");
		}
			  system("cls");
			  break;
		case 3: {
			string nameFood;
			cout << "������������ ��������, ������� ���������� �������� - ";
			nameFood = wordTest();
			priority_queue<CalorieContent> temp;

			CalorieContent calorieContent;
			CalorieContent calorieTemp;
			int flag = 0;
			while (!pqCalorie.empty()) {
				calorieTemp = pqCalorie.top();
				if (calorieTemp.getNamefood() == nameFood) {
					calorieContent = pqCalorie.top();
					pqCalorie.pop();
					flag = 1;
				}
				else {
					temp.push(pqCalorie.top());
					pqCalorie.pop();
				}

			}
			pqCalorie = temp;
			if (flag == 0) {
				cout << "�� ����������." << endl;
			}
			else {

				int calorie;
				cout << "������� ����� ���������� ������� - ";
				calorie = numberTest();
				calorieContent.setCalorie(calorie);
				pqCalorie.push(calorieContent);

			}

			system("pause"); }
			  break;

		case 0:
			return;
			break;

		}

	}
}