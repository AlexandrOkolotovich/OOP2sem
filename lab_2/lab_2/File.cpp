#include "Header.h"
/*
ptype Staff::getType() {//������� ���� �������  
	if (typeid(*this) == typeid(Manager))return EmployeeType::manager; 
	else if (typeid(*this) == typeid(Scientist)) 
		return EmployeeType::scientist;  
	else if (typeid(*this) == typeid(Laborer))
		return EmployeeType::laborer; 
	else { 
		cerr << "\n������������ ��� ���������";  
		exit(1);  
	}  
	return EmployeeType::manager; 
}

void Staff::write() {//�������� ��� ������� � ����  
	int size=0;  
	cout << "���� ������ " << emplNum << " ����������.\n";
	ofstream ouf;//������� ofstream  
	ptype etype;//��� ������� ������� Employee  
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);  
	if (!ouf) {
		cout << "\n���������� ������� ����\n";
		return;
	} 
	for (int j = 0; j < emplNum; j++) {//��� ������� ������� �������� ��� 
		etype = staff[j]->getType(); 
		ouf.write((char*)&etype, sizeof(etype));  
		/*switch (etype) { 
			case EmployeeType::manager:  size = sizeof(Manager); break; 
			case EmployeeType::scientist: size = sizeof(Scientist); break; 
			case EmployeeType::laborer:  size = sizeof(Laborer); break; 
		}  */ 

		/*switch (temp)
		{
		case 0: cout << "�������������" << endl; break;
		case 1: cout << "����������������� ������" << endl; break;
		case 2: cout << "����������� ������" << endl; break;
		}

		ouf.write((char*)(staff[j]), size);//������ ������� Employee 
		if (!ouf) {   
			cout << "\n������ � ���� ����������\n";  
			return; 
		}  
	} 
}

void Employee::read() {//������ ���� ������ �� �����  
	int size;//������ ������� Employee 
	EmployeeType etype;//��� ��������� 
	ifstream inf; 
	inf.open("EMPLOY.DAT", ios::binary); 
	if (!inf) {  
		cout << "\n���������� ������� ����\n"; 
		return; 
	}  
	emplNum = 0;//� ������ ���������� ��� 
	while (true) { 
		inf.read((char*)&etype, sizeof(etype));//������ ���� ��������� 
		if (inf.eof()) break;  
		if (!inf) {//������ ������ ����   
			cout << "\n���������� ������ ����\n"; 
			return; 
		}   
		switch (etype) {    //������� ������ ���������  
		case EmployeeType::manager://����������� ����  
		staff[emplNum] = new Manager; 
		size = sizeof(Manager); 
		break; 
		case EmployeeType::scientist:   
		staff[emplNum] = new Scientist;   
		size = sizeof(Scientist);    
		break;  
		case EmployeeType::laborer:  
		staff[emplNum] = new Laborer;  
		size = sizeof(Laborer);   
		break; 
		default: cout << "\n����������� ��� � �����\n";
			return;  
		}//������ ������ �� �����  
		inf.read((char*)staff[emplNum], size); 
		if (!inf) {//������, �� �� EOF 
			cout << "\n������ ������ �� ����� ����������\n";    
			return;  
		}   emplNum++;//������� ���������� ��������� 
	}//end while 
	cout << "���� ������ " << emplNum << " ����������\n";
} */
/*
class File {
public:
	File() {};
	void diskIn(int personNumber) {
		ifstream infile;
		infile.open("PERSFILE.DAT", ios::binary);
		infile.seekg(personNumber * sizeof(Staff));
		infile.read((char*)this, sizeof(*this));
	}

	void diskOut() {
		ofstream outfile;
		outfile.open("PERSFILE.DAT", ios::app | ios::binary);
		outfile.write((char*)this, sizeof(*this));
	}

	int diskCount() {//������� ����� ����� � ����� 
		ifstream infile;
		infile.open("PERSFILE.DAT", ios::binary);
		infile.seekg(0, ios::end);//������� �� ������� �0 ���� �� ����� �����  
		return (int)infile.tellg() / sizeof(Staff);//���������� 
	}
};*/