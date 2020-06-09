#include <vector>
#include <windows.h>
#include "Header.h"
#include "File.cpp"

void exx() {
	cout << "��������� ����������� ��-�� ������";
	system("pause");
	exit(1);
}

int emplNum = 0;
vector<Information*> inf;
//File file;
//Staff file;

int main()
{
	SetConsoleCP(1251);  
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	//vector<Information*> inf;
	University university;
	try {
		University* university = new University;
	}
	catch (bad_alloc exept) {
		cout << "�������� ���������� " << exept.what() << endl;}
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

		try{
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
				//	st->diskOut();
					inf.push_back(st);
					emplNum = inf.size();

					

					//st->write();
				//	for (int i = 0; i < inf.size(); i++) {
				//		file.get_st;
				//		file.get_posobie;

					//	file.diskOut();
				//	}
					system("pause");
				}; break;
			case 2: //����� ����������
			{
				//st->read();///////////////////////////////////////////////////
			//	st->diskIn(inf.size());
				//int n = Staff::diskCount();
	//			int n = file.diskCount();
	//			for (int i = 0; i < n; i++) {
		//			file.diskIn(i);
	//				inf[i]->show();

					
		//		}
				if (!inf.empty()) {
					system("cls");
					for (int j = 0; j < inf.size(); j++) {
					//	inf[i]->diskIn(inf.size());
						cout << j + 1 << ". "<<endl;
						inf[j]->show();
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
						cout << i + 1 << ". "<<endl;
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
						cout << i + 1 << ". "<<endl;
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
					int count=0;
					cout << "������� �������� ������� �� �������� ����������� �����" << endl;
					searchpos = Check<float>();
					for (int i = 0; i < inf.size(); i++) {
						if (inf[i]->search(searchpos)==true) {
							cout << i + 1 << ". "<<endl;
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
/*
void Staff::write() {//�������� ��� ������� � ����  
	int size = 0;
	cout << "���� ������ " << emplNum << " ����������.\n";
	ofstream ouf;//������� ofstream  
	ptype etype;//��� ������� ������� Employee  
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	for (int i = 0; i < emplNum; i++) {//��� ������� ������� �������� ��� 
		//etype = getType();
		
		etype = get_st();
		ouf.write((char*)&etype, sizeof(etype));

		switch (temp)
		{
		case 0: temp = administration;
			size = sizeof(Administration); break;
		case 1: temp = lectuter;
			size = sizeof(Lectuter); break;
		case 2: temp = technicalStaff; 
			size = sizeof(TechnicalStaff); break;
		}



		ouf.write((char*)(inf[i]), size);
		if (!ouf) {
			cout << "\n������ � ���� ����������\n";
			return;
		}

		
	}
	ouf.close();
}

void Staff::read() {//������ ���� ������ �� �����  
	int size;//������ ������� Employee 
	ptype etype;//��� ��������� 
	ifstream infile;
	infile.open("EMPLOY.DAT", ios::binary);
	if (!infile) {
		cout << "\n���������� ������� ����\n";
		return;
	}
	emplNum = 0;//� ������ ���������� ��� 
	while (true) {
		infile.read((char*)&etype, sizeof(etype));//������ ���� ��������� 
		if (infile.eof()) break;
		if (!infile) {//������ ������ ����   
			cout << "\n���������� ������ ����\n";
			return;
		}
		switch (etype) {    //������� ������ ���������  
		case ptype::administration://����������� ����  
			inf[emplNum] = new Staff;
			size = sizeof(Administration);
			break;
		case ptype::lectuter:
			inf[emplNum] = new Staff;
			size = sizeof(Lectuter);
			break;
		case ptype::technicalStaff:
			inf[emplNum] = new Staff;
			size = sizeof(TechnicalStaff);
			break;
		default: cout << "\n����������� ��� � �����\n";
			return;
		}//������ ������ �� �����  
		infile.read((char*)inf[emplNum], size);
		if (!infile) {//������, �� �� EOF 
			cout << "\n������ ������ �� ����� ����������\n";
			return;
		}   emplNum++;//������� ���������� ��������� 
	}//end while 
	cout << "���� ������ " << emplNum << " ����������\n";
	infile.close();
}
*/
/*
void Staff::diskIn(int personNumber) {
	ifstream infile; 
	infile.open("PERSFILE.DAT", ios::binary); 
	infile.seekg(personNumber * sizeof(Staff));
	infile.read((char*)this, sizeof(*this)); 
} 

void Staff::diskOut() {
	ofstream outfile;  
	outfile.open("PERSFILE.DAT", ios::app | ios::binary); 
	outfile.write((char*)this, sizeof(*this));
}

int Staff::diskCount() {//������� ����� ����� � ����� 
	ifstream infile;
	infile.open("PERSFILE.DAT", ios::binary);
	infile.seekg(0, ios::end);//������� �� ������� �0 ���� �� ����� �����  
	return (int)infile.tellg() / sizeof(Staff);//���������� 
}
	*/


void Staff::readstaffinfile(vector<Information*> inf)
{
	fstream file;
	Staff *staff=new Staff();
	file.open("Staff.DAT", ios::out | ios::trunc | ios::binary);
	for (int i = 1; i <= inf.size(); i++)
	{
		staff == inf[i];/////////////////////////////////////////////////////////////////////////////////////////
		file.write((char*)&staff, sizeof(staff));
	}
	file.close();
}

void Staff::readStafffromfile(vector<Information*> inf)
{
	int n;
	long size;
	fstream file;
	file.open("Staff.DAT", ios::in | ios::binary);
	file.seekg(0, ios::end);
	size = file.tellg();
	n = size / sizeof(Staff);
	file.seekg(0);
	if (size > 0)
		for (int i = 0; i < n; i++)
		{
			Staff *staff= new Staff();
			file.read((char*)&staff, sizeof(staff));
			inf.push_back(staff);
		}
	file.close();
}