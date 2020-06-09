#include "Header.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	main_menu();
}

string proverka() {
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

void main_menu() {
	while (1) {
		system("cls");
		int choice;
		cout << std::right << std::setw(50) << "МЕНЮ" << endl;
		cout << " 1. Сотрудники банка" << endl
			<< " 2. Результат" << endl
			<< " 0. Выход" << endl
			<< " Ваш выбор - ";

		do {
			choice = Check<int>();
			if (choice < 0 || choice > 2) cout << "Неизвестная команда" << endl;
		} while (choice < 0 || choice > 2);

		switch (choice)
		{
		case 1:
			employee_menu();
			break;
		case 2:
			result_menu();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}

void employee_menu() {
	string fio;
	list<Employee>::iterator employee;
	while (1) {
		system("cls");
		int choice;
		cout << std::right << std::setw(50) << "МЕНЮ ДОБАВЛЕНИЯ СОТРУДНИКОВ" << endl;
		cout << "1. Добавить сотрудника" << endl
			<< "2. Просмотр и добавление в файл сотрудников" << endl
			<< "3. Изменить" << endl
			<< "4. Удалить" << endl
			<< "5. Сортировка" << endl
			<< "6. Поиск" << endl
			<< "0. Назад" << endl
			<< "Ваш выбор: ";
		do {
			choice = Check<int>();
			if (choice < 0 || choice > 6) cout << "Неизвестная команда" << endl;
		} while (choice < 0 || choice > 6);
		switch (choice)
		{
		case 1:
			add_employee();
			break;
		case 2:
			view_all_empl();
			break;
		case 3:
			change_employee();
			break;
		case 4:
			system("cls");
			cout << "Введите ФИО:\n";
			fio = proverka();
			if (!exh_name(fio)) {
				cout << "Не существует данного сотрудника\n";
				system("pause");
				return;
			}
			delete_result(fio);

			employee = empl_list.begin();
			do {
				if (employee->get_fio() == fio) {
					empl_list.erase(employee);
					break;
				}
				employee++;
			} while (employee != empl_list.end());

			cout << "Удалено\n";
			system("pause");
			break;
		case 5:
			system("cls");
			empl_list.sort();
			cout << "Сортировка завершена" << endl;
			system("pause");
			break;
		case 6:
			find_employee();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}

void result_menu() {
	while (1) {
		system("cls");
		int choice;
		cout << std::right << std::setw(50) << "МЕНЮ ПРОСМОТРА РЕЗУЛЬТАТА" << endl;
		cout << "1. Просмотреть все результаты" << endl
			<< "2. Поиск" << endl
			<< "3. Изменить результат" << endl
			<< "0. Назад" << endl
			<< "Ваш выбор: ";
		do {
			choice = Check<int>();
			if (choice < 0 || choice > 3) cout << "Неизвестная команда" << endl;
		} while (choice < 0 || choice > 3);
		switch (choice)
		{
		case 1:
			view_all_result();
			break;
		case 2:
			system("cls");
			cout << "Введите ФИО:" << endl;
			cout << get_find_result(proverka());
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Введите ФИО сотрудника:\n";
			change_result(proverka());
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}

void add_employee() {
	string fio;
	string education;
	int experience;
	int age;
	bool ex = true;
	system("cls");
	cout << "Введите ФИО:" << endl;
	do {
		fio = proverka();
		if (!exh_name(fio)) ex = false;
		else cout << "Данный сотрудник уже существует" << endl;
	} while (ex);
	cout << "Введите образование:" << endl;
	education = proverka();
	cout << "Введите стаж работы:" << endl;
	experience = Check<int>();
	cout << "Введите возраст:" << endl;
	age = Check<int>();
	empl_list.push_back(Employee(fio, education, experience, age));
	create_result(fio);
}

bool exh_name(string fio) {
	for (Employee obj : empl_list) {
		if (obj.get_fio() == fio) {
			return true;
		}
	}
	return false;
}

string get_employee_info(Employee obj) {
	string return_str;
	return_str = return_str + "	ФИО: " + obj.get_fio() + '\n' + "	Образование: " + obj.get_education() + '\n' + "	Стаж работы: " + to_string(obj.get_experience()) + "\n	Возраст: " + to_string(obj.get_age()) + '\n';
	return return_str;
}

void view_all_empl() {
	system("cls");
	int i = 1;
	for (Employee obj : empl_list) {
		cout << i <<". "<<endl;
		cout << get_employee_info(obj);
		i++;
	}

		fstream file;
		file.open("employee.txt", ios::out);
		i = 1;
		for (Employee obj : empl_list) {
			file  << i << ". "<<endl;
			file << get_employee_info(obj);
			i++;
		}

	system("pause");
}

void change_employee() {
	int i = 1;
	system("cls");
	for (Employee employee : empl_list) {
		cout << i << ". " << employee.get_fio() << endl;
		i++;
	}
	cout << "Введите номер сотрудника" << endl;
	int pos = Check<int>();
	i = 1;
	for (Employee& employee : empl_list) {
		if (i == pos) {
			system("cls");


			while (1) {
				system("cls");
				int choice;
				cout << std::right << std::setw(50) << "МЕНЮ РЕДАКТИРОВАНИЯ" << endl;
				cout << "1. Изменить образование" << endl
					<< "2. Изменить опыт работы" << endl
					<< "3. Изменить возраст" << endl
					<< "0. Назад" << endl
					<< "Ваш выбор: ";
				do {
					choice = Check<int>();
					if (choice < 0 || choice > 3) cout << "Неизвестная команда" << endl;
				} while (choice < 0 || choice > 3);
				switch (choice)
				{
				case 1:
					system("cls");
					cout << "Введите образование" << endl;
					employee.set_education(proverka());
					break;
				case 2:
					system("cls");
					cout << "Введите опыт работы" << endl;
					employee.set_experience(Check<int>());
					break;
				case 3:
					system("cls");
					cout << "Введите возраст" << endl;
					employee.set_age(Check<int>());
					break;
				case 0:
					return;
					break;
				default:
					break;
				}
			}

		}
		i++;
	}
}

void find_employee() {
	system("cls");
	cout << "Введите диапазон опыта работы" << endl;
	int experience1 = Check<int>();
	int experience2 = Check<int>();
	int i = 1;
	for (Employee employee : empl_list) {
		if (experience1 <= employee.get_experience() && employee.get_experience() <= experience2) {
			cout << i <<". "<< endl << get_employee_info(employee);
			i++;
		}
	}
	system("pause");
}

void create_result(string fio) {
	map_result.insert(pair<string, string>(fio, "кандидат"));
}

void view_all_result() {
	system("cls");
	int i = 1;
	for (Employee employee : empl_list) {
		cout << i << ". " << get_find_result(employee.get_fio());
		i++;
	}
	system("pause");
}

string get_find_result(string fio) {
	if (!exh_name(fio)) return "Не существует данного сотрудника\n";
	map<string, string>::iterator obj;
	obj = map_result.find(fio);
	if (obj != map_result.end()) {
		return obj->first + ", профессия: " + obj->second + '\n';
	}
}

void change_result(string fio) {
	if (!exh_name(fio)) {
		cout << "Не существует данного сотрудника\n";
		system("pause");
		return;
	}
	map<string, string>::iterator obj;
	obj = map_result.find(fio);
	if (obj != map_result.end()) {
		cout << "Введите профессию" << endl;
		obj->second = proverka();
	}
}

void delete_result(string fio) {
	map<string, string>::iterator obj;
	obj = map_result.find(fio);
	map_result.erase(obj);
}
