#include <vector>
#include <windows.h>
#include "Header.h"

void exx() {
	cout << "��������� ����������� ��-�� ������";
	system("pause");
	exit(1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	vector<Information*> inf;
	University university;
	try {
		University* university = new University;
	}
	catch (bad_alloc exept) {
		cout << "�������� ���������� " << exept.what() << endl;
	}
	catch (int) { cout << "int exception hendler" << endl; }
	university.get_name();
	system("pause");
	system("cls");

	while (true)
	{
		int choice;
		university.show_information();
		cout << "1.�������� ��������� ������������\n2.����������� ������ ���������\n3.�������������� ������\n4.�������� ������\n5.�����\n0.�����\n";
		choice = Check<int>();
		while (choice < 0 || choice > 5) {
			choice = Check<int>();
		};
		system("cls");

		try {
			Staff* st = new Staff;

			switch (choice)
			{
			case 1: //���������� ����������
			{

				st->get_staff();

				if (st->get_st() == 0) {
					st->admin->get_administration();
				}
				if (st->get_st() == 1) {
					st->lec->get_lectuter();
				}
				if (st->get_st() == 2) {
					st->tstaff->get_technicalstaff();
				}

				while (1) {

					try {
						if (st->get_posobie() < 0) { throw NegativeNumberExeption("����� �� ����� ���� �������������"); }
						else
						{
							break;
						}
					}
					catch (const NegativeNumberExeption e) {
						cout << e.m_error << endl;
						system("pause");
					}
				}

				st->employee->get_employee();
				inf.push_back(st);

				system("pause");
			}; break;
			case 2: //����� ����������
			{
				if (!inf.empty()) {
					system("cls");
					for (int i = 0; i < inf.size(); i++) {
						cout << i + 1 << ". " << endl;
						inf[i]->show();
					}
				}
				else cout << "�� ������ �� ��������" << endl;
				system("pause");
			}; break;
			case 3:  //�������������� ������
			{
				if (!inf.empty()) {
					system("cls");
					for (int i = 0; i < inf.size(); i++) {
						cout << i + 1 << ". " << endl;
						inf[i]->show();
					}
					cout << "������� ����� ����������� ���������. ��� ������ ������� 0\n";
					int choice;
					choice = Check<int>();
					while (choice < 0 || choice > inf.size()) {
						cout << "������ �����. ��������� �������\n";
						choice = Check<int>();
					};
					if (choice == 0) break;
					else inf[choice - 1]->change();
				}
				else cout << "�� ������ �� ��������" << endl;
				system("pause");
			}; break;
			case 4:  //�������� ������
			{
				if (!inf.empty()) {
					system("cls");
					for (int i = 0; i < inf.size(); i++) {
						cout << i + 1 << ". " << endl;
						inf[i]->show();
					}
					cout << "������� ����� �������� �������� ������ �������. ��� ������ ������� 0\n";
					int choice;
					choice = Check<int>();
					while (choice < 0 || choice > inf.size()) {
						cout << "������ �����. ��������� �������\n";
						choice = Check<int>();
					};
					if (choice == 0) break;
					else {
						inf.erase(inf.begin() + choice - 1);  //�������� �� ���������� vector
						cout << "\n\n������ �" << choice << " ������� �������\n\n" << endl;
					}
				}
				else cout << "������� ���" << endl;
				system("pause");
			}; break;
			case 5: //����� ������
			{
				if (!inf.empty()) {
					system("cls");
					float searchpos;
					int count = 0;
					cout << "������� �������� ������� �� �������� ����������� �����" << endl;
					searchpos = Check<float>();
					for (int i = 0; i < inf.size(); i++) {
						if (inf[i]->search(searchpos) == true) {
							cout << i + 1 << ". " << endl;
							inf[i]->show();
							count++;
						}
					}
					if (count == 0) cout << "�� �������" << endl;
				}
				else cout << "�� ������ �� ��������" << endl;
				system("pause");
			}; break;
			case 0:
			{

				return 0;
			}; break;
			default:
			{
				cout << "�������� ����";
			}; break;
			}
		}
		catch (bad_alloc exept) { cout << "�������� ���������� " << exept.what() << endl; exx(); }
		catch (...) { cout << "�������� ���������� ����������" << endl; }
		system("cls");
	}

	return 0;
}
