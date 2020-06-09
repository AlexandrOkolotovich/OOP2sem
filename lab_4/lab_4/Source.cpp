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
    nameUniversity = proverka();
   
}

void University::show_information() {
    cout.setf(ios::right);
    cout.width(50);
    cout << "Название университета: " << nameUniversity << endl;
    cout.unsetf(ios::right);

}

void Employee::add() {
    system("cls");
    char userChoice;
    bool check;
    cout <<   "'a' для добавления администрации"   
            "\n'l' для добавления преподователя"   
            "\n't' для добавления технического сотстава" 
            "\nВаш выбор: ";  
    do {
        check = false;
        cin >> userChoice;
        switch (userChoice) {//создать объект указанного типа 
        case 'a': staff[emplNum] = new Administration;  break;
        case 'l': staff[emplNum] = new Lectuter;   break;
        case 't': staff[emplNum] = new TechnicalStaff;  break;
        default: cout << "Неизвестный тип работника\n"; check = true; //  return; 
        }
    } while (check==true);
    staff[emplNum++]->getData();//Получить данные от пользователя 
    system("pause");
    system("cls");
} 

void Employee::display() {//Вывести данные обо всех работниках 
    system("cls");
    for (int j = 0; j < emplNum; j++) {  
        cout << (j + 1)<<"."<<endl;//вывести номер 
        cout << "Тип:";
        cout.fill('_');
        switch (staff[j]->getType()) {//вывести тип работника  
            case EmployeeType::administration:
                cout << std::right << std::setw(74) << "Администрация"; break;
            case EmployeeType::lectuter:
                cout << std::right << std::setw(74) << "Преподовательский состав"; break;
            case EmployeeType::technicalStaff: 
                cout << std::right << std::setw(74) << "Технический состав"; break;
            default: 
                cout << "Неизвестный тип";
        }   
        staff[j]->putData();//Вывод данных  
        cout << endl; 
    } 

} 

void Employee::get_emplinf() {
    cin.ignore(10, '\n');
    cout << "Введите ФИО сотрудника: ";
    cin.getline(name, 32, '\n');
    cout << "Введите номер телефона сотрудника: ";
   cin.getline(number, 14, '\n');

}

float Employee::get_posobie() {
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

EmployeeType Employee::getType() {//Возврат типа объекта  
    if (typeid(*this) == typeid(Administration))
        return EmployeeType::administration;  
    else if (typeid(*this) == typeid(Lectuter)) 
        return EmployeeType::lectuter;  
    else if (typeid(*this) == typeid(TechnicalStaff)) 
        return EmployeeType::technicalStaff;  
    else {   
        cerr << "\nНеправильный тип работника";   
        exit(1);  
    }  
    return EmployeeType::administration; 
} 

void Employee::write(University university) {//Записать все объекты в файл 
    system("cls");
    int size=0;  
    cout << "Идет запись в файл...\n";  
    ofstream ouf;//открыть ofstream  
    EmployeeType etype;//тип каждого объекта Employee  
    ouf.open(university.fileName, ios::trunc | ios::binary);
    if (!ouf) {  
        cout << "\nНевозможно открыть файл\n";  
        return;  
    }  
    for (int j = 0; j < emplNum; j++) {//Для каждого объекта получить тип   
        etype = staff[j]->getType();   
        ouf.write((char*)&etype, sizeof(etype));   
        switch (etype) {   
            case EmployeeType::administration:   
                size = sizeof(Administration); break;  
            case EmployeeType::lectuter:    
                size = sizeof(Lectuter); break;  
            case EmployeeType::technicalStaff:    
                size = sizeof(TechnicalStaff); break;  
        }  
        ouf.write((char*)(staff[j]), size);//запись объекта Employee  
        if (!ouf) {   
            cout << "\nЗапись в файл невозможна\n";  
            return; 
        }  
    } 
    system("pause");
    system("cls");
} 

void Employee::read(University university) {//чтение всех данных из файла 
    system("cls");
    int size;//размер объекта Employee 
    EmployeeType etype;//тип работника  
    ifstream inf;  
    inf.open(university.fileName, ios::binary); 
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
            case EmployeeType::administration://корректного типа  
                staff[emplNum] = new Administration;  
                size = sizeof(Administration);  
                break;   
            case EmployeeType::lectuter: 
                staff[emplNum] = new Lectuter;   
                size = sizeof(Lectuter); 
                break;  
            case EmployeeType::technicalStaff:   
                staff[emplNum] = new TechnicalStaff; 
                size = sizeof(TechnicalStaff);  
                break;  
            default: 
                cout << "\nНеизвестный тип в файле\n";
                return;  
        }
        //чтение данных из файла   
        inf.read((char*)staff[emplNum], size);  
        if (!inf) {//ошибка, но не EOF  
            cout << "\nЧтение данных из файла невозможно\n";    
            return;  
        }  
        emplNum++;//счетчик работников увеличить 
    }//end while  
    cout << "Идет чтение  файла...\n";
    system("pause");
    system("cls");
} 

void Employee::change() {
    display();
    cout << "Введите номер изменяемого работника. Для выхода введите 0\n";
    int choice;

        choice = Check<int>();
        while (choice < 0 || choice > emplNum) {
            cout << "Ошибка ввода. Повторите попытку\n";
            choice = Check<int>();
        }

        if (choice == 0) return;
        else staff[choice - 1]->change_inf(choice);
  
    system("cls");
}

void Employee::change_inf(int j) {
    while (true)
    {

        system("cls");
        cout << (j) << "." << endl;//вывести номер  
        cout << "Тип:";
        cout.fill('_');
        switch (staff[j - 1]->getType()) {//вывести тип работника 
        case EmployeeType::administration:
            cout << std::right << std::setw(74) <<" Администрация"; break;
        case EmployeeType::lectuter:
            cout<< std::right << std::setw(74) <<" Преподовательский состав"; break;
        case EmployeeType::technicalStaff:
            cout << std::right << std::setw(74) << "Технический состав"; break;
        default:
            cout << "Неизвестный тип";
        }
        staff[j - 1]->putData();//Вывод данных  
        cout << endl;

        int choice;
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
            getProfession();
        }; break;
        case 2:
        {
            cout << "Введите новую величину оклада" << endl;
            get_posobie();
        }; break;
        case 3:
        {
            cout << "Введите новые данные о работнике" << endl;
            get_emplinf();
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

void Employee::del() {
    display();
    cout << "Введите номер удаляемого работника. Для выхода введите 0\n";
    int choice;

    choice = Check<int>();
    while (choice < 0 || choice > emplNum) {
        cout << "Ошибка ввода. Повторите попытку\n";
        choice = Check<int>();
    }

    if (choice == 0) return;
    else { 
        for (int i = choice; i < emplNum; i++) {
            staff[i - 1]=staff[i];
            --emplNum;
        }
        cout << "Запись №" << choice << " успешно удалена" << endl;
    }
    system("pause");
    system("cls");
}

void Employee::search() {
    float searchpos;
    int count = 0;
    cout << "Введите величину оклада по которой производится поиск: ";
    while (!(cin >> searchpos))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Неверный ввод. " << endl;
        cout << "Введите число: ";
    }
    for (int i = 0; i < emplNum; i++) {
        if (searchpos == staff[i]->posobie) {
            system("cls");
            cout << (i+1) << "." << endl;//вывести номер 
            cout << "Тип:";
            cout.fill('_');
            switch (staff[i]->getType()) {//вывести тип работника  
            case EmployeeType::administration:
                cout << std::right << std::setw(74) << "Администрация"; break;
            case EmployeeType::lectuter:
                cout << std::right << std::setw(74) << "Преподовательский состав"; break;
            case EmployeeType::technicalStaff:
                cout << std::right << std::setw(74) << "Технический состав"; break;
            default:
                cout << "Неизвестный тип";
            }
            staff[i]->putData();//Вывод данных  
            cout << endl;
            count++;
        }
        
    }
    if (count == 0) cout << "Записи не найдены" << endl;
    system("pause");
    system("cls");
    
}

int InfInput() {  
    University university;
    try {
        University* university = new University;
    }
    catch (bad_alloc exept) {
        cout << "Возникло исключение " << exept.what() << endl;
    }
    catch (int) { cout << "int exception hendler" << endl; }

    university.get_name();
    university.fileName = university.nameUniversity + ".DAT";

    system("pause");
    system("cls");
    
    while (true) { 
        int choice;
        university.show_information();
        cout <<   "1 - добавление сведений о работнике" 
                "\n2 - вывести сведения обо всех работниках"  
                "\n3 - редактирование "    
                "\n4 - удаление "  
                "\n5 - поиск "
                "\n0 - выход"    
                "\nВаш выбор: "; 
       do{
            choice = Check<int>();
            if (choice < 0 || choice > 5) cout << "Неизвестная команда" << endl;
       }while (choice < 0 || choice > 5);
        system("cls");
        switch (choice) {
        case 1://добавить работника 
            Employee::add();
            Employee::write(university);
            break;
        case 2://вывести все сведения
            Employee::read(university);
            Employee::display();
            system("pause");
            system("cls");
            break;
        case 3://редактирование изменений 
            Employee::read(university);
            Employee::change();
            Employee::write(university);
            break;
        case 4://удаление работника
            Employee::read(university);
            Employee::del();
            Employee::write(university);
            break;
        case 5://поиск
            Employee::read(university);
            Employee::search();
            break;
        case 0: exit(0);//выход 
        default: cout << "\nНеизвестная команда" << endl;  break;
        }
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    InfInput();

    return 0;
}