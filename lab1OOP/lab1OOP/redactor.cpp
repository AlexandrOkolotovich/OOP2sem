#include "Header.h"
//����������� ������������
user::user() {
	ifstream temp;

	temp.open("user.txt");
	temp >> name;
	temp >> pas;
	temp.close();
}
//����������� �����
file::file() {
	ifstream temp;
	cout << "File name" << endl;
	cin >> name;
	temp.open(name + ".txt");
	if (temp.is_open()) {
		while (getline(temp, text)) {
			temp >> text;
		}
	}
	temp.close();
}
//���������� �����
file::~file() {
	ofstream temp;

	temp.open(name + ".txt", ios::trunc);
	temp << text;
	temp.close();
}
//������ � ������
void file::work() {
	char temp;
	unredo.getGoBack(text);

	cout << text;

	bool enter = true;
	

	while (enter)

	{
		int code = _getch();
		if ( code != 13 && code != 26 && code != 27 && code != 25 )
		{
		
			cout << static_cast<char>(code);
			text.push_back(code);
			

		}
	
		else if (code == 13)
		{
			cout << "\n";
			text += '\n';
		}
		else if (code == 27)
		{
			enter = false;

		}
		else if (code == 26) //undo
		{
			system("cls");
			undo();
			cout << text;

		}
		else if (code == 25 ) //redo
		{
			system("cls");
			redo();
			cout << text;
		}

	}

}
//�����
void file::undo() {
	if (unredo.sizeGoBack() != 0) {
		unredo.getUngoBack(text);
		text = unredo.giveGoBack();
	}
}
//����� ������
void file::redo() {
	if (unredo.sizeUngoBack() != 0) {
		unredo.getGoBack(text);
		text = unredo.giveUngoBack();
	}
}
//���������� ��������� �����
void file::see() {
	cout << text << endl;
}
//������� ��� ������ Undo Redo

//�������� ��������� ��� Undo
void states::getGoBack(string text) {
	goBack.push_back(text);
}
//�������� ��������� ��� Redo
void states::getUngoBack(string text) {
	ungoBack.push_back(text);
}

//��������� ��������� ��� Undo
string states::giveGoBack() {
	string temp;
	if (goBack.size() != 0)
		temp = goBack.back();
	if (goBack.size() > 1) {
		goBack.pop_back();
	}
	return temp;
}
//��������� ��������� ��� Redo
string states::giveUngoBack() {
	string temp;
	if (ungoBack.size() != 0)
		temp = ungoBack.back();
	if (ungoBack.size() > 1) {
		ungoBack.pop_back();
	}
	return temp;
}

void states::clearUndo() {
	ungoBack.clear();
}