#include "Header.h"

string proverka() {
	string str;
	while (1) {
		try {
			rewind(stdin);
			cin >> str;
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

void University::get_name() {
	cout << "Введите название универистета: " << endl;
	name = proverka();
}

void University::show_information() {
	cout.setf(ios::right);
	cout.width(50);
	cout << "Название университета: " << name << endl;
	cout.unsetf(ios::right);

}

void Staff::get_staff() {
	int choice;
	cout << "Введите группу к которй относится профессия данного работника " << endl
		<< "1. Администрация " << endl
		<< "2. Преподователь " << endl
		<< "3. Технический состав " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 3) {
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = administration; break;
	case 2: temp = lectuter; break;
	case 3: temp = technicalStaff; break;
	}
	cout << "Вы выбрали группу: ";
	switch (temp)
	{
	case 0: cout << "Администрация" << endl; break;
	case 1: cout << "Преподовательский состав" << endl; break;
	case 2: cout << "Технический состав" << endl; break;
	}

}

float Staff::get_posobie() {
	cout << "Введите величину оклада: ";
	while (!(cin >> posobie))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод. " << endl;
		cout << "Введите число: ";
	}
	return posobie;
}

void Staff::show() {
	cout << "Группа к которой относится профессия работника: ";
	cout.fill('_');
	switch (temp)
	{
		cout.fill('_');
	case 0: cout << std::right << std::setw(30) << "Администрация" << endl; break;
	case 1: cout << std::right << std::setw(30) << "Преподовательский состав" << endl; break;
	case 2: cout << std::right << std::setw(30) << "Технический состав" << endl; break;
	}
	cout << "Величина оклада: " << std::right << std::setw(61) << std::setprecision(4) << posobie << endl;

	if (get_st() == 0) {
		admin->show_admin();
	}
	if (get_st() == 1) {
		lec->show_lectuter();
	}
	if (get_st() == 2) {
		tstaff->show_technicalstaff();
	}
	employee->show_employee();
}

void Staff::change() {
	while (true)
	{
		int choice;
		system("cls");
		this->show();
		cout << "1. Изменить профессию\n2. Изменить величину оклада\n3. Изменить информацию о работнике\n0. Выход\n";
		choice = Check<int>();
		while (choice < 0 || choice > 3) {
			cout << "Ошибка ввода. Повторите попытку\n";
			choice = Check<int>();
		};
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "Выберите новую профессию" << endl;
			get_staff();

			if (get_st() == 0) {
				admin->get_administration();
			}
			if (get_st() == 1) {
				lec->get_lectuter();
			}
			if (get_st() == 2) {
				tstaff->get_technicalstaff();
			}
		}; break;
		case 2:
		{
			cout << "Введите новую величину оклада" << endl;
			get_posobie();
		}; break;
		case 3:
		{
			cout << "Введите новые данные о работнике" << endl;
			employee->get_employee();
		}; break;
		case 0:
		{
			return;
		}; break;
		default:
		{
			cout << "Неверный ввод";
		}; break;
		}
		system("cls");
	}
}

bool Staff::search(float searchpos) {
	if (searchpos == posobie) {
		return true;
	}
}

void Staff::Administration::get_administration() {
	int choice;;
	cout << "Выберите профессию работника " << endl
		<< "1. Ректор " << endl
		<< "2. Проректор " << endl
		<< "3. Декан " << endl
		<< "4. Зам декана " << endl
		<< "5. Заведующий кафедры " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 5) {
		cout << "Ошибка ввода. Повторите попытку\n";
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = rector; break;
	case 2: temp = viceRector; break;
	case 3: temp = dean; break;
	case 4: temp = deputyDean; break;
	case 5: temp = headOfDepartment; break;
	}
	cout << "Вы выбрали профессию: ";
	switch (temp)
	{
	case 0: cout << "Ректор" << endl; break;
	case 1: cout << "Проректор" << endl; break;
	case 2: cout << "Декан" << endl; break;
	case 3: cout << "Зам декана" << endl; break;
	case 4: cout << "Заведующий кафедры" << endl; break;
	}
}

void Staff::Administration::show_admin() {
	cout << "Профессия администрации: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(53) << "Ректор" << endl; break;
	case 1: cout << std::right << std::setw(53) << "Проректор" << endl; break;
	case 2: cout << std::right << std::setw(53) << "Декан" << endl; break;
	case 3: cout << std::right << std::setw(53) << "Зам декана" << endl; break;
	case 4: cout << std::right << std::setw(53) << "Заведующий кафедры" << endl; break;
	}
}

void Staff::Lectuter::get_lectuter() {
	int choice;
	cout << "Выберите профессию преподавательского состава: " << endl
		<< "1. Доцент " << endl
		<< "2. Преподователь " << endl
		<< "3. Ассистент " << endl
		<< "4. Аспирант " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 4) {
		cout << "Ошибка ввода. Повторите попытку\n";
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = associateProfessor; break;
	case 2: temp = professor; break;
	case 3: temp = assistant; break;
	case 4: temp = postgraduate; break;
	}
	cout << "Вы выбрали профессию: ";
	switch (temp)
	{
	case 0: cout << "Доцент" << endl; break;
	case 1: cout << "Преподователь" << endl; break;
	case 2: cout << "Ассистент" << endl; break;
	case 3: cout << "Аспирант" << endl; break;
	}
}

void Staff::Lectuter::show_lectuter() {
	cout << "Профессия работника: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(57) << "Доцент" << endl; break;
	case 1: cout << std::right << std::setw(57) << "Преподователь" << endl; break;
	case 2: cout << std::right << std::setw(57) << "Ассистент" << endl; break;
	case 3: cout << std::right << std::setw(57) << "Аспирант" << endl; break;
	}
}

void Staff::TechnicalStaff::get_technicalstaff() {
	int choice;
	cout << "Введите профессию технического персонала: " << endl
		<< "1. Лаборант " << endl
		<< "2. Вахтер " << endl
		<< "3. Уборщица " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 3) {
		cout << "Ошибка ввода. Повторите попытку\n";
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = laboratoryAssistant; break;
	case 2: temp = watchman; break;
	case 3: temp = cleaner; break;
	}
	cout << "Вы выбрали профессию: ";
	switch (temp)
	{
	case 0: cout << "Лаборант" << endl; break;
	case 1: cout << "Вахтер" << endl; break;
	case 2: cout << "Уборщица" << endl; break;
	}
}

void Staff::TechnicalStaff::show_technicalstaff() {
	cout << "Профессия работника: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(57) << "Лаборант" << endl; break;
	case 1: cout << std::right << std::setw(57) << "Вахтер" << endl; break;
	case 2: cout << std::right << std::setw(57) << "Уборщица" << endl; break;
	}
}

void Staff::Employee::get_employee() {
	cout << "Введите ФИО: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fio);
	cout << "Введите адресс: " << endl;
	getline(cin, address);
	cout << "Введите опыт работы: " << endl;
	while (!(cin >> workExperience))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод. " << endl;
		cout << "Введите число: ";
	}
	D1.get_date();
}

void Staff::Employee::show_employee() {
	cout << "ФИО: " << std::right << std::setw(73) << fio << endl
		<< "Адресс: " << std::right << std::setw(70) << address << endl
		<< "Опыт работы: " << std::right << std::setw(65) << workExperience << endl
		<< "Дата рождения: "; D1.show_date();
	cout << endl;
	cout.fill(' ');

}
