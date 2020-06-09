#pragma once
#include <fstream> 
#include <iostream> 
#include <iomanip> 
#include <typeinfo>//��� typeid() 
#include <process.h> 
#include <windows.h>

using namespace std;

const int SURNAMELEN = 32;//������������ ����� ������� 
const int MAXEMPL = 100;//������������ ����� ���������� 
enum EmployeeType { administration, lectuter, technicalStaff };

class University {

public:
    string nameUniversity;
    string fileName;
    University() {};
    University(int n) {
        if (n) throw 1;
    }
    ~University() {};
    void get_name();
    void show_information();
};

class Employee {
    char name[SURNAMELEN];//������� ���������  
    char number[14];//����� �������� ���������  
    float posobie;
    static int emplNum;//������� ���������� ����������  
    static Employee* staff[];//������ ���������� 
public:
    Employee() { strcpy_s(name, "");   strcpy_s(number, ""); }
    float get_posobie();
    void get_emplinf();
    void change_inf(int);
    virtual void getData() {
        get_emplinf();
        get_posobie();
    }
    virtual void getProfession()=0;
    virtual void putData() {
        cout << "\n���: " << std::right << std::setw(73) << name<<endl;
        cout << "����� ��������: " << std::right << std::setw(62) << number<<endl;
        cout << "�������� ������: " << std::right << std::setw(61) << std::setprecision(4) << posobie << endl;
        cout.fill(' ');
    }
    virtual EmployeeType getType();//�������� ��� ����������  
    static void add();//�������� ���������� � ����  
    static void display();//������� ������ ��� ���� �����������  
    static void read(University);//������ ������ �� �����  
    static void write(University);//������ ������ � ���� 
    static void change();//�������� ���������� � ����������
    static void del();//������� ����������
    static void search();
};

int Employee::emplNum;//������� ����� ���������� 
Employee* Employee::staff[MAXEMPL];//������ ���������� 

class Administration : public Employee {
private:
    enum atype { rector, viceRector, dean, deputyDean, headOfDepartment };
    char userChoice;
public:
    void getData() {
  
        getProfession();

        Employee::getData();
    }
    void getProfession() {
        cout << "������� ��������� �������������: "
            << "\n'r' ��� ���������� �������"
               "\n'v' ��� ���������� ����������"
               "\n'd' ��� ���������� ������"
               "\n'z' ��� ���������� ���. ������"
               "\n'h' ��� ���������� ����������� �������"
               "\n��� �����: ";
        bool check;
        do {
            check = false;
            cin >> userChoice;
            switch (userChoice) {//������� ������ ���������� ���� 
            case 'r': userChoice = rector; break;
            case 'v': userChoice = viceRector; break;
            case 'd': userChoice = dean; break;
            case 'z': userChoice = deputyDean; break;
            case 'h': userChoice = headOfDepartment; break;
            default: cout << "����������� ��� ���������\n"; check = true;
            }
        } while (check == true);
     
    }
    void putData() {
        cout << "\n��������� ���������: ";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(57) << "������" << endl; break;
        case 1: cout << std::right << std::setw(57) << "���������" << endl; break;
        case 2: cout << std::right << std::setw(57) << "�����" << endl; break;
        case 3: cout << std::right << std::setw(57) << "��� ������" << endl; break;
        case 4: cout << std::right << std::setw(57) << "���������� �������" << endl; break;
        }
        Employee::putData();
    }
};

class Lectuter : public Employee {
private:
    enum ltype { associateProfessor, professor, assistant, postgraduate };
    char userChoice;
public:
    void getData() {
   
        getProfession();

        Employee::getData();
    }
    void getProfession() {
      cout << "������� ��������� ������������������ �������: "
         << "\n'd' ��� ���������� �������"
            "\n'p' ��� ���������� �������������"
            "\n'a' ��� ���������� ����������"
            "\n's' ��� ���������� ���������"
            "\n��� �����: ";
      bool check;
      do {
          check = false;
          cin >> userChoice;
          switch (userChoice) {//������� ������ ���������� ���� 
          case 'd': userChoice = associateProfessor; break;
          case 'p': userChoice = professor; break;
          case 'a': userChoice = assistant; break;
          case 's': userChoice = postgraduate; break;
          default: cout << "����������� ��� ���������\n";   check==true;
          }
      } while (check == true);
    }
    void putData() {
        Employee::putData();
        cout << "\n��������� ���������: ";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(57) << "������" << endl; break;
        case 1: cout << std::right << std::setw(57) << "�������������" << endl; break;
        case 2: cout << std::right << std::setw(57) << "���������" << endl; break;
        case 3: cout << std::right << std::setw(57) << "��������" << endl; break;
        }
        Employee::putData();
    }
};

class TechnicalStaff : public Employee {
private:
    enum ttype { laboratoryAssistant, watchman, cleaner };
    char userChoice;
public:
    void getData() {
     
        getProfession();

        Employee::getData();
    }
    void getProfession() {
        cout << "������� ��������� ������������ �������: "
            << "\n'l' ��� ���������� ���������"
            "\n'w' ��� ���������� �������"
            "\n'c' ��� ���������� ��������"
            "\n��� �����: ";
        bool check;
        do {
            check = false;
            cin >> userChoice;
            switch (userChoice) {//������� ������ ���������� ���� 
            case 'l': userChoice = laboratoryAssistant; break;
            case 'w': userChoice = watchman; break;
            case 'c': userChoice = cleaner; break;
            default: cout << "����������� ��� ���������\n";   check=true;
            }
        } while (check == true);
    }
    void putData() {
        cout << "\n��������� ���������";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(59) << "��������" << endl; break;
        case 1: cout << std::right << std::setw(59) << "������" << endl; break;
        case 2: cout << std::right << std::setw(59) << "��������" << endl; break;
        }
        Employee::putData();
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
            throw "������ �����. ��������� �������";
        }
        return i;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }
}
