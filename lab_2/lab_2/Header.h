#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<typeinfo>
#include<process.h>

using namespace std;


class University {
	private:
		string name;

	public:
		University() {};
		University(int n) {
			if (n) throw 1;
		}
		~University() {};
		void get_name();
		void show_information();
};

class Information {
public:
	virtual void show() = 0; //Вывести информацию
	virtual void change() = 0; //Редактированние данных
	virtual bool search(float) = 0; //Поиск данных
	//virtual void read()=0;
	//virtual void write()=0;
//	virtual void diskIn(int)=0;
//	virtual void diskOut()=0;
	Information() {};

};

class Staff : public Information{
	private:
		enum ptype { administration, lectuter, technicalStaff};
		ptype temp;
		float posobie;
	public:
		Staff* st;
		Staff() {};
		void get_staff();
		float get_posobie();
		void change(); //Редактирование данных
		void show();  //Вывести информацию
		bool search(float); //Поиск данных
		//void read();
		//void write();
	//	void diskIn(int);
	//	void diskOut();
	//	int diskCount();

		void readstaffinfile(vector<Information*>); //запись билетов в файл
		void readStafffromfile(vector<Information*>); //чтение билетов из файла

		virtual ptype get_st() { return temp; };

		class  Administration  {
		private:
			enum atype { rector, viceRector, dean, deputyDean, headOfDepartment };
			atype temp;
		public:
			void get_administration();
			void show_admin();
			atype get_admin() { return temp; };

		};
		Administration* admin= new Administration;

		class Lectuter  {
		private:
			enum ltype { associateProfessor, professor, assistant, postgraduate };
			ltype temp;
		public:
			void get_lectuter();
			void show_lectuter();
			ltype get_lec() { return temp; };


		};
		Lectuter* lec=new Lectuter;

		class TechnicalStaff {
		private:
			enum ttype { laboratoryAssistant, watchman, cleaner };
			ttype temp;
		public:
			void get_technicalstaff();
			void show_technicalstaff();
			ttype get_tstaff() { return temp; };


		};
		TechnicalStaff* tstaff= new TechnicalStaff;

		class Employee : public Administration, Lectuter,TechnicalStaff  {
		private:
			string fio;
			string address;
			int workExperience;

		public:
			Employee() {};
			void get_employee();
			void show_employee();

			class Date
			{
			private:
				int day, mons, year;
			public:
				Date() {};
				void get_date()
				{
					cout << "Введите дату рождения сотрудника \"dd/mm/yy\":" << endl;

					while (true) {
						cout << "Введите день: ";
						cin.setf(ios::skipws);  
						cin >> day; 
						if (day > 31 || day < 1) {    
							cout<< "День должен быть между 1 и 31\n ";    
							cin.clear(ios::failbit);//установить флаг ошибки  
						}   
						if (cin.good()) {   
							cin.ignore(10, '\n'); 
							break; // Ввод корректный, выйти из 'while' 
						}   cin.clear(); // ошибка ввода; очистить статус ошибки  
						cin.ignore(10, '\n'); 
						cout << "Неверно введен день \n"; 
						cin.unsetf(ios::skipws);
					}

					while (true) {
						cout << "Введите месяц: ";
						cin.setf(ios::skipws); 
						cin >> mons;
						if (mons > 12 || mons < 1) {
							cout << "Месяц должен быть между 1 и 12\n ";
							cin.clear(ios::failbit);//установить флаг ошибки  
						}
						if (cin.good()) {
							cin.ignore(10, '\n');
							break; // Ввод корректный, выйти из 'while' 
						}   cin.clear(); // ошибка ввода; очистить статус ошибки  
						cin.ignore(10, '\n');
						cout << "Неверно введен месяц \n";
						cin.unsetf(ios::skipws);
					}

					while (true) {
						cout << "Введите год: ";
						cin.setf(ios::skipws);// не пропускать разделители  
						cin >> year;
						if (year > 2002 || year < 1940) {
							//cout << "Год должен быть между 1940 и 2002\n ";
							cin.clear(ios::failbit);//установить флаг ошибки  
						}
						if (cin.good()) {
							cin.ignore(10, '\n');
							break; // Ввод корректный, выйти из 'while' 
						}   cin.clear(); // ошибка ввода; очистить статус ошибки  
						cin.ignore(10, '\n');
						cout << "Неверно введен год \n";
						cin.unsetf(ios::skipws);
					}

				}
				void show_date()const {
						cout <<std::right << std::setw(56) << day << "/" << mons << "/" << year << endl;
				}
				

			};

			Date D1;
		};
		Employee* employee=new Employee;
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

class NegativeNumberExeption : public std::exception {
public:
	string m_error;
	NegativeNumberExeption(string error) :m_error(error) {}
	const char* what() const noexcept { return m_error.c_str(); }
	~NegativeNumberExeption() {};

};