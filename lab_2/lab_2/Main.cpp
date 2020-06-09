#include <vector>
#include <windows.h>
#include "Header.h"
#include "File.cpp"

void exx() {
	cout << "Программа завершилась из-за ошибки";
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
		cout << "Возникло исключение " << exept.what() << endl;}
	catch (int) { cout << "int exception hendler" << endl; }
	university.get_name();
	system("pause");
	system("cls");

	while (true)
	{
		int choice;
		university.show_information();
		cout << "1.Добавить работника университета\n2.Просмотреть список персонала\n3.Редактирование данных\n4.Удаление данных\n5.Поиск\n0.Выход\n";
		choice = Check<int>();
		while (choice < 0 || choice > 5) {
			choice = Check<int>();
		};
		system("cls");

		try{
			Staff* st = new Staff;

			switch (choice)
			{
				case 1: //Добавление информации
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
							if (st->get_posobie() < 0) { throw NegativeNumberExeption("Оклад не может быть отрицательным"); }
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
			case 2: //Вывод информации
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
				else cout << "Вы ничего не добавили" << endl;
				system("pause");
			}; break;
			case 3:  //Редактирование данных
			{
				if (!inf.empty()) {
					system("cls");
					for (int i = 0; i < inf.size(); i++) {
						cout << i + 1 << ". "<<endl;
						inf[i]->show();
					}
					cout << "Введите номер изменяемого работника. Для выхода введите 0\n";
					int choice;
					choice = Check<int>();
					while (choice < 0 || choice > inf.size()) {
						cout << "Ошибка ввода. Повторите попытку\n";
						choice = Check<int>();
					};
					if (choice == 0) break;
					else inf[choice - 1]->change();
				}
				else cout << "Вы ничего не добавили" << endl;
				system("pause");
			}; break;
			case 4:  //Удаление данных
			{
				if (!inf.empty()) {
					system("cls");
					for (int i = 0; i < inf.size(); i++) {
						cout << i + 1 << ". "<<endl;
						inf[i]->show();
					}
					cout << "Введите номер рабочего которого хотите удалить. Для выхода введите 0\n";
					int choice;
					choice = Check<int>();
					while (choice < 0 || choice > inf.size()) {
						cout << "Ошибка ввода. Повторите попытку\n";
						choice = Check<int>();
					};
					if (choice == 0) break;
					else {
						inf.erase(inf.begin() + choice - 1);  //Удаление из контейнера vector
						cout << "\n\nЗапись №" << choice << " успешно удалена\n\n" << endl;
					}
				}
				else cout << "Записей нет" << endl;
				system("pause");
			}; break;
			case 5: //Поиск данных
			{
				if (!inf.empty()) {
					system("cls");
					float searchpos;
					int count=0;
					cout << "Введите величину пособия по которому производите поиск" << endl;
					searchpos = Check<float>();
					for (int i = 0; i < inf.size(); i++) {
						if (inf[i]->search(searchpos)==true) {
							cout << i + 1 << ". "<<endl;
							inf[i]->show();
							count++;
						}
					}
					if (count == 0) cout << "Не найдено" << endl;
				}
				else cout << "Вы ничего не добавили" << endl;
				system("pause");
			}; break;
			case 0:
			{

				return 0;
			}; break;
			default:
			{
				cout << "Неверный ввод";
			}; break;
			}
		}
		catch (bad_alloc exept) { cout << "Возникло исключение " << exept.what() << endl; exx(); }
		catch (...) { cout << "Сработал абсолютный обработчик" << endl; }
		system("cls");
	}

	return 0;
}
/*
void Staff::write() {//Записать все объекты в файл  
	int size = 0;
	cout << "Идет запись " << emplNum << " работников.\n";
	ofstream ouf;//открыть ofstream  
	ptype etype;//тип каждого объекта Employee  
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	for (int i = 0; i < emplNum; i++) {//Для каждого объекта получить тип 
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
			cout << "\nЗапись в файл невозможна\n";
			return;
		}

		
	}
	ouf.close();
}

void Staff::read() {//чтение всех данных из файла  
	int size;//размер объекта Employee 
	ptype etype;//тип работника 
	ifstream infile;
	infile.open("EMPLOY.DAT", ios::binary);
	if (!infile) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	emplNum = 0;//В памяти работников нет 
	while (true) {
		infile.read((char*)&etype, sizeof(etype));//чтение типа работника 
		if (infile.eof()) break;
		if (!infile) {//ошибка чтения типа   
			cout << "\nНевозможно чтение типа\n";
			return;
		}
		switch (etype) {    //создать нового работника  
		case ptype::administration://корректного типа  
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
		default: cout << "\nНеизвестный тип в файле\n";
			return;
		}//чтение данных из файла  
		infile.read((char*)inf[emplNum], size);
		if (!infile) {//ошибка, но не EOF 
			cout << "\nЧтение данных из файла невозможно\n";
			return;
		}   emplNum++;//счетчик работников увеличить 
	}//end while 
	cout << "Идет чтение " << emplNum << " работников\n";
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

int Staff::diskCount() {//подсчет число людей в файле 
	ifstream infile;
	infile.open("PERSFILE.DAT", ios::binary);
	infile.seekg(0, ios::end);//перейти на позицию «0 байт от конца файла»  
	return (int)infile.tellg() / sizeof(Staff);//количество 
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