#include "Header.h"
/*
ptype Staff::getType() {//Возврат типа объекта  
	if (typeid(*this) == typeid(Manager))return EmployeeType::manager; 
	else if (typeid(*this) == typeid(Scientist)) 
		return EmployeeType::scientist;  
	else if (typeid(*this) == typeid(Laborer))
		return EmployeeType::laborer; 
	else { 
		cerr << "\nНеправильный тип работника";  
		exit(1);  
	}  
	return EmployeeType::manager; 
}

void Staff::write() {//Записать все объекты в файл  
	int size=0;  
	cout << "Идет запись " << emplNum << " работников.\n";
	ofstream ouf;//открыть ofstream  
	ptype etype;//тип каждого объекта Employee  
	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);  
	if (!ouf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	} 
	for (int j = 0; j < emplNum; j++) {//Для каждого объекта получить тип 
		etype = staff[j]->getType(); 
		ouf.write((char*)&etype, sizeof(etype));  
		/*switch (etype) { 
			case EmployeeType::manager:  size = sizeof(Manager); break; 
			case EmployeeType::scientist: size = sizeof(Scientist); break; 
			case EmployeeType::laborer:  size = sizeof(Laborer); break; 
		}  */ 

		/*switch (temp)
		{
		case 0: cout << "Администрация" << endl; break;
		case 1: cout << "Преподовательский состав" << endl; break;
		case 2: cout << "Технический состав" << endl; break;
		}

		ouf.write((char*)(staff[j]), size);//запись объекта Employee 
		if (!ouf) {   
			cout << "\nЗапись в файл невозможна\n";  
			return; 
		}  
	} 
}

void Employee::read() {//чтение всех данных из файла  
	int size;//размер объекта Employee 
	EmployeeType etype;//тип работника 
	ifstream inf; 
	inf.open("EMPLOY.DAT", ios::binary); 
	if (!inf) {  
		cout << "\nНевозможно открыть файл\n"; 
		return; 
	}  
	emplNum = 0;//В памяти работников нет 
	while (true) { 
		inf.read((char*)&etype, sizeof(etype));//чтение типа работника 
		if (inf.eof()) break;  
		if (!inf) {//ошибка чтения типа   
			cout << "\nНевозможно чтение типа\n"; 
			return; 
		}   
		switch (etype) {    //создать нового работника  
		case EmployeeType::manager://корректного типа  
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
		default: cout << "\nНеизвестный тип в файле\n";
			return;  
		}//чтение данных из файла  
		inf.read((char*)staff[emplNum], size); 
		if (!inf) {//ошибка, но не EOF 
			cout << "\nЧтение данных из файла невозможно\n";    
			return;  
		}   emplNum++;//счетчик работников увеличить 
	}//end while 
	cout << "Идет чтение " << emplNum << " работников\n";
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

	int diskCount() {//подсчет число людей в файле 
		ifstream infile;
		infile.open("PERSFILE.DAT", ios::binary);
		infile.seekg(0, ios::end);//перейти на позицию «0 байт от конца файла»  
		return (int)infile.tellg() / sizeof(Staff);//количество 
	}
};*/