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
    nameUniversity = proverka();
   
}

void University::show_information() {
    cout.setf(ios::right);
    cout.width(50);
    cout << "�������� ������������: " << nameUniversity << endl;
    cout.unsetf(ios::right);

}

void Employee::add() {
    system("cls");
    char userChoice;
    bool check;
    cout <<   "'a' ��� ���������� �������������"   
            "\n'l' ��� ���������� �������������"   
            "\n't' ��� ���������� ������������ ��������" 
            "\n��� �����: ";  
    do {
        check = false;
        cin >> userChoice;
        switch (userChoice) {//������� ������ ���������� ���� 
        case 'a': staff[emplNum] = new Administration;  break;
        case 'l': staff[emplNum] = new Lectuter;   break;
        case 't': staff[emplNum] = new TechnicalStaff;  break;
        default: cout << "����������� ��� ���������\n"; check = true; //  return; 
        }
    } while (check==true);
    staff[emplNum++]->getData();//�������� ������ �� ������������ 
    system("pause");
    system("cls");
} 

void Employee::display() {//������� ������ ��� ���� ���������� 
    system("cls");
    for (int j = 0; j < emplNum; j++) {  
        cout << (j + 1)<<"."<<endl;//������� ����� 
        cout << "���:";
        cout.fill('_');
        switch (staff[j]->getType()) {//������� ��� ���������  
            case EmployeeType::administration:
                cout << std::right << std::setw(74) << "�������������"; break;
            case EmployeeType::lectuter:
                cout << std::right << std::setw(74) << "����������������� ������"; break;
            case EmployeeType::technicalStaff: 
                cout << std::right << std::setw(74) << "����������� ������"; break;
            default: 
                cout << "����������� ���";
        }   
        staff[j]->putData();//����� ������  
        cout << endl; 
    } 

} 

void Employee::get_emplinf() {
    cin.ignore(10, '\n');
    cout << "������� ��� ����������: ";
    cin.getline(name, 32, '\n');
    cout << "������� ����� �������� ����������: ";
   cin.getline(number, 14, '\n');

}

float Employee::get_posobie() {
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

EmployeeType Employee::getType() {//������� ���� �������  
    if (typeid(*this) == typeid(Administration))
        return EmployeeType::administration;  
    else if (typeid(*this) == typeid(Lectuter)) 
        return EmployeeType::lectuter;  
    else if (typeid(*this) == typeid(TechnicalStaff)) 
        return EmployeeType::technicalStaff;  
    else {   
        cerr << "\n������������ ��� ���������";   
        exit(1);  
    }  
    return EmployeeType::administration; 
} 

void Employee::write(University university) {//�������� ��� ������� � ���� 
    system("cls");
    int size=0;  
    cout << "���� ������ � ����...\n";  
    ofstream ouf;//������� ofstream  
    EmployeeType etype;//��� ������� ������� Employee  
    ouf.open(university.fileName, ios::trunc | ios::binary);
    if (!ouf) {  
        cout << "\n���������� ������� ����\n";  
        return;  
    }  
    for (int j = 0; j < emplNum; j++) {//��� ������� ������� �������� ���   
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
        ouf.write((char*)(staff[j]), size);//������ ������� Employee  
        if (!ouf) {   
            cout << "\n������ � ���� ����������\n";  
            return; 
        }  
    } 
    system("pause");
    system("cls");
} 

void Employee::read(University university) {//������ ���� ������ �� ����� 
    system("cls");
    int size;//������ ������� Employee 
    EmployeeType etype;//��� ���������  
    ifstream inf;  
    inf.open(university.fileName, ios::binary); 
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
            case EmployeeType::administration://����������� ����  
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
                cout << "\n����������� ��� � �����\n";
                return;  
        }
        //������ ������ �� �����   
        inf.read((char*)staff[emplNum], size);  
        if (!inf) {//������, �� �� EOF  
            cout << "\n������ ������ �� ����� ����������\n";    
            return;  
        }  
        emplNum++;//������� ���������� ��������� 
    }//end while  
    cout << "���� ������  �����...\n";
    system("pause");
    system("cls");
} 

void Employee::change() {
    display();
    cout << "������� ����� ����������� ���������. ��� ������ ������� 0\n";
    int choice;

        choice = Check<int>();
        while (choice < 0 || choice > emplNum) {
            cout << "������ �����. ��������� �������\n";
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
        cout << (j) << "." << endl;//������� �����  
        cout << "���:";
        cout.fill('_');
        switch (staff[j - 1]->getType()) {//������� ��� ��������� 
        case EmployeeType::administration:
            cout << std::right << std::setw(74) <<" �������������"; break;
        case EmployeeType::lectuter:
            cout<< std::right << std::setw(74) <<" ����������������� ������"; break;
        case EmployeeType::technicalStaff:
            cout << std::right << std::setw(74) << "����������� ������"; break;
        default:
            cout << "����������� ���";
        }
        staff[j - 1]->putData();//����� ������  
        cout << endl;

        int choice;
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
            getProfession();
        }; break;
        case 2:
        {
            cout << "������� ����� �������� ������" << endl;
            get_posobie();
        }; break;
        case 3:
        {
            cout << "������� ����� ������ � ���������" << endl;
            get_emplinf();
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

void Employee::del() {
    display();
    cout << "������� ����� ���������� ���������. ��� ������ ������� 0\n";
    int choice;

    choice = Check<int>();
    while (choice < 0 || choice > emplNum) {
        cout << "������ �����. ��������� �������\n";
        choice = Check<int>();
    }

    if (choice == 0) return;
    else { 
        for (int i = choice; i < emplNum; i++) {
            staff[i - 1]=staff[i];
            --emplNum;
        }
        cout << "������ �" << choice << " ������� �������" << endl;
    }
    system("pause");
    system("cls");
}

void Employee::search() {
    float searchpos;
    int count = 0;
    cout << "������� �������� ������ �� ������� ������������ �����: ";
    while (!(cin >> searchpos))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "�������� ����. " << endl;
        cout << "������� �����: ";
    }
    for (int i = 0; i < emplNum; i++) {
        if (searchpos == staff[i]->posobie) {
            system("cls");
            cout << (i+1) << "." << endl;//������� ����� 
            cout << "���:";
            cout.fill('_');
            switch (staff[i]->getType()) {//������� ��� ���������  
            case EmployeeType::administration:
                cout << std::right << std::setw(74) << "�������������"; break;
            case EmployeeType::lectuter:
                cout << std::right << std::setw(74) << "����������������� ������"; break;
            case EmployeeType::technicalStaff:
                cout << std::right << std::setw(74) << "����������� ������"; break;
            default:
                cout << "����������� ���";
            }
            staff[i]->putData();//����� ������  
            cout << endl;
            count++;
        }
        
    }
    if (count == 0) cout << "������ �� �������" << endl;
    system("pause");
    system("cls");
    
}

int InfInput() {  
    University university;
    try {
        University* university = new University;
    }
    catch (bad_alloc exept) {
        cout << "�������� ���������� " << exept.what() << endl;
    }
    catch (int) { cout << "int exception hendler" << endl; }

    university.get_name();
    university.fileName = university.nameUniversity + ".DAT";

    system("pause");
    system("cls");
    
    while (true) { 
        int choice;
        university.show_information();
        cout <<   "1 - ���������� �������� � ���������" 
                "\n2 - ������� �������� ��� ���� ����������"  
                "\n3 - �������������� "    
                "\n4 - �������� "  
                "\n5 - ����� "
                "\n0 - �����"    
                "\n��� �����: "; 
       do{
            choice = Check<int>();
            if (choice < 0 || choice > 5) cout << "����������� �������" << endl;
       }while (choice < 0 || choice > 5);
        system("cls");
        switch (choice) {
        case 1://�������� ��������� 
            Employee::add();
            Employee::write(university);
            break;
        case 2://������� ��� ��������
            Employee::read(university);
            Employee::display();
            system("pause");
            system("cls");
            break;
        case 3://�������������� ��������� 
            Employee::read(university);
            Employee::change();
            Employee::write(university);
            break;
        case 4://�������� ���������
            Employee::read(university);
            Employee::del();
            Employee::write(university);
            break;
        case 5://�����
            Employee::read(university);
            Employee::search();
            break;
        case 0: exit(0);//����� 
        default: cout << "\n����������� �������" << endl;  break;
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