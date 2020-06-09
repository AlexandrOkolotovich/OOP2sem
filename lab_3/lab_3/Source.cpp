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
			cout << "������� �����. ��������� �������" << endl;
		}
	}
}

void University::get_name() {
	cout << "������� �������� ������������: " << endl;
	name = proverka();
}

void University::show_information() {
	cout.setf(ios::right);
	cout.width(50);
	cout << "�������� ������������: " << name << endl;
	cout.unsetf(ios::right);

}

void Staff::get_staff() {
	int choice;
	cout << "������� ������ � ������ ��������� ��������� ������� ��������� " << endl
		<< "1. ������������� " << endl
		<< "2. ������������� " << endl
		<< "3. ����������� ������ " << endl;
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
	cout << "�� ������� ������: ";
	switch (temp)
	{
	case 0: cout << "�������������" << endl; break;
	case 1: cout << "����������������� ������" << endl; break;
	case 2: cout << "����������� ������" << endl; break;
	}

}

float Staff::get_posobie() {
	cout << "������� �������� ������: ";
	while (!(cin >> posobie))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����. " << endl;
		cout << "������� �����: ";
	}
	return posobie;
}

void Staff::show() {
	cout << "������ � ������� ��������� ��������� ���������: ";
	cout.fill('_');
	switch (temp)
	{
		cout.fill('_');
	case 0: cout << std::right << std::setw(30) << "�������������" << endl; break;
	case 1: cout << std::right << std::setw(30) << "����������������� ������" << endl; break;
	case 2: cout << std::right << std::setw(30) << "����������� ������" << endl; break;
	}
	cout << "�������� ������: " << std::right << std::setw(61) << std::setprecision(4) << posobie << endl;

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
		cout << "1. �������� ���������\n2. �������� �������� ������\n3. �������� ���������� � ���������\n0. �����\n";
		choice = Check<int>();
		while (choice < 0 || choice > 3) {
			cout << "������ �����. ��������� �������\n";
			choice = Check<int>();
		};
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "�������� ����� ���������" << endl;
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
			cout << "������� ����� �������� ������" << endl;
			get_posobie();
		}; break;
		case 3:
		{
			cout << "������� ����� ������ � ���������" << endl;
			employee->get_employee();
		}; break;
		case 0:
		{
			return;
		}; break;
		default:
		{
			cout << "�������� ����";
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
	cout << "�������� ��������� ��������� " << endl
		<< "1. ������ " << endl
		<< "2. ��������� " << endl
		<< "3. ����� " << endl
		<< "4. ��� ������ " << endl
		<< "5. ���������� ������� " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 5) {
		cout << "������ �����. ��������� �������\n";
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
	cout << "�� ������� ���������: ";
	switch (temp)
	{
	case 0: cout << "������" << endl; break;
	case 1: cout << "���������" << endl; break;
	case 2: cout << "�����" << endl; break;
	case 3: cout << "��� ������" << endl; break;
	case 4: cout << "���������� �������" << endl; break;
	}
}

void Staff::Administration::show_admin() {
	cout << "��������� �������������: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(53) << "������" << endl; break;
	case 1: cout << std::right << std::setw(53) << "���������" << endl; break;
	case 2: cout << std::right << std::setw(53) << "�����" << endl; break;
	case 3: cout << std::right << std::setw(53) << "��� ������" << endl; break;
	case 4: cout << std::right << std::setw(53) << "���������� �������" << endl; break;
	}
}

void Staff::Lectuter::get_lectuter() {
	int choice;
	cout << "�������� ��������� ������������������ �������: " << endl
		<< "1. ������ " << endl
		<< "2. ������������� " << endl
		<< "3. ��������� " << endl
		<< "4. �������� " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 4) {
		cout << "������ �����. ��������� �������\n";
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = associateProfessor; break;
	case 2: temp = professor; break;
	case 3: temp = assistant; break;
	case 4: temp = postgraduate; break;
	}
	cout << "�� ������� ���������: ";
	switch (temp)
	{
	case 0: cout << "������" << endl; break;
	case 1: cout << "�������������" << endl; break;
	case 2: cout << "���������" << endl; break;
	case 3: cout << "��������" << endl; break;
	}
}

void Staff::Lectuter::show_lectuter() {
	cout << "��������� ���������: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(57) << "������" << endl; break;
	case 1: cout << std::right << std::setw(57) << "�������������" << endl; break;
	case 2: cout << std::right << std::setw(57) << "���������" << endl; break;
	case 3: cout << std::right << std::setw(57) << "��������" << endl; break;
	}
}

void Staff::TechnicalStaff::get_technicalstaff() {
	int choice;
	cout << "������� ��������� ������������ ���������: " << endl
		<< "1. �������� " << endl
		<< "2. ������ " << endl
		<< "3. �������� " << endl;
	choice = Check<int>();
	while (choice < 0 || choice > 3) {
		cout << "������ �����. ��������� �������\n";
		choice = Check<int>();
	};
	switch (choice)
	{
	case 1: temp = laboratoryAssistant; break;
	case 2: temp = watchman; break;
	case 3: temp = cleaner; break;
	}
	cout << "�� ������� ���������: ";
	switch (temp)
	{
	case 0: cout << "��������" << endl; break;
	case 1: cout << "������" << endl; break;
	case 2: cout << "��������" << endl; break;
	}
}

void Staff::TechnicalStaff::show_technicalstaff() {
	cout << "��������� ���������: ";
	switch (temp)
	{
	case 0: cout << std::right << std::setw(57) << "��������" << endl; break;
	case 1: cout << std::right << std::setw(57) << "������" << endl; break;
	case 2: cout << std::right << std::setw(57) << "��������" << endl; break;
	}
}

void Staff::Employee::get_employee() {
	cout << "������� ���: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fio);
	cout << "������� ������: " << endl;
	getline(cin, address);
	cout << "������� ���� ������: " << endl;
	while (!(cin >> workExperience))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����. " << endl;
		cout << "������� �����: ";
	}
	D1.get_date();
}

void Staff::Employee::show_employee() {
	cout << "���: " << std::right << std::setw(73) << fio << endl
		<< "������: " << std::right << std::setw(70) << address << endl
		<< "���� ������: " << std::right << std::setw(65) << workExperience << endl
		<< "���� ��������: "; D1.show_date();
	cout << endl;
	cout.fill(' ');

}
