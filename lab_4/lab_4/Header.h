#pragma once
#include <fstream> 
#include <iostream> 
#include <iomanip> 
#include <typeinfo>//для typeid() 
#include <process.h> 
#include <windows.h>

using namespace std;

const int SURNAMELEN = 32;//Максимальная длина фамилии 
const int MAXEMPL = 100;//максимальное число работников 
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
    char name[SURNAMELEN];//фамилия работника  
    char number[14];//номер телефона работника  
    float posobie;
    static int emplNum;//текущее количество работников  
    static Employee* staff[];//массив указателей 
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
        cout << "\nФИО: " << std::right << std::setw(73) << name<<endl;
        cout << "Номер телефона: " << std::right << std::setw(62) << number<<endl;
        cout << "Величина оклада: " << std::right << std::setw(61) << std::setprecision(4) << posobie << endl;
        cout.fill(' ');
    }
    virtual EmployeeType getType();//получить тип сотрудника  
    static void add();//добавить сотрудника в штат  
    static void display();//вывести данные обо всех сотрудниках  
    static void read(University);//чтение данных из файла  
    static void write(University);//запись данных в файл 
    static void change();//поменять информацию о сотруднике
    static void del();//удалить сотрудника
    static void search();
};

int Employee::emplNum;//текущее число работников 
Employee* Employee::staff[MAXEMPL];//массив указателей 

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
        cout << "Введите профессию администрации: "
            << "\n'r' для добавления ректора"
               "\n'v' для добавления проректора"
               "\n'd' для добавления декана"
               "\n'z' для добавления зам. декана"
               "\n'h' для добавления заведующего кафедры"
               "\nВаш выбор: ";
        bool check;
        do {
            check = false;
            cin >> userChoice;
            switch (userChoice) {//создать объект указанного типа 
            case 'r': userChoice = rector; break;
            case 'v': userChoice = viceRector; break;
            case 'd': userChoice = dean; break;
            case 'z': userChoice = deputyDean; break;
            case 'h': userChoice = headOfDepartment; break;
            default: cout << "Неизвестный тип работника\n"; check = true;
            }
        } while (check == true);
     
    }
    void putData() {
        cout << "\nПрофессия работника: ";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(57) << "Ректор" << endl; break;
        case 1: cout << std::right << std::setw(57) << "Проректор" << endl; break;
        case 2: cout << std::right << std::setw(57) << "Декан" << endl; break;
        case 3: cout << std::right << std::setw(57) << "Зам декана" << endl; break;
        case 4: cout << std::right << std::setw(57) << "Заведующий кафедры" << endl; break;
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
      cout << "Введите профессию преподовательского состава: "
         << "\n'd' для добавления доцента"
            "\n'p' для добавления преподователя"
            "\n'a' для добавления ассистента"
            "\n's' для добавления аспиранта"
            "\nВаш выбор: ";
      bool check;
      do {
          check = false;
          cin >> userChoice;
          switch (userChoice) {//создать объект указанного типа 
          case 'd': userChoice = associateProfessor; break;
          case 'p': userChoice = professor; break;
          case 'a': userChoice = assistant; break;
          case 's': userChoice = postgraduate; break;
          default: cout << "Неизвестный тип работника\n";   check==true;
          }
      } while (check == true);
    }
    void putData() {
        Employee::putData();
        cout << "\nПрофессия работника: ";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(57) << "Доцент" << endl; break;
        case 1: cout << std::right << std::setw(57) << "Преподователь" << endl; break;
        case 2: cout << std::right << std::setw(57) << "Ассистент" << endl; break;
        case 3: cout << std::right << std::setw(57) << "Аспирант" << endl; break;
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
        cout << "Введите профессию технического состава: "
            << "\n'l' для добавления лаборанта"
            "\n'w' для добавления вахтера"
            "\n'c' для добавления уборщицы"
            "\nВаш выбор: ";
        bool check;
        do {
            check = false;
            cin >> userChoice;
            switch (userChoice) {//создать объект указанного типа 
            case 'l': userChoice = laboratoryAssistant; break;
            case 'w': userChoice = watchman; break;
            case 'c': userChoice = cleaner; break;
            default: cout << "Неизвестный тип работника\n";   check=true;
            }
        } while (check == true);
    }
    void putData() {
        cout << "\nПрофессия работника";
        switch (userChoice)
        {
        case 0: cout << std::right << std::setw(59) << "Лаборант" << endl; break;
        case 1: cout << std::right << std::setw(59) << "Вахтер" << endl; break;
        case 2: cout << std::right << std::setw(59) << "Уборщица" << endl; break;
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
            throw "Ошибка ввода. Повторите попытку";
        }
        return i;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }
}
