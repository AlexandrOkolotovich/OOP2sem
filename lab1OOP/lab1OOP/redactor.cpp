#include "Header.h"
//Конструктор пользователя
user::user() {
	ifstream temp;

	temp.open("user.txt");
	temp >> name;
	temp >> pas;
	temp.close();
}
//Конструктор файла
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
//Деструктор файла
file::~file() {
	ofstream temp;

	temp.open(name + ".txt", ios::trunc);
	temp << text;
	temp.close();
}
//Работа с файлом
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
//Откат
void file::undo() {
	if (unredo.sizeGoBack() != 0) {
		unredo.getUngoBack(text);
		text = unredo.giveGoBack();
	}
}
//Откат отката
void file::redo() {
	if (unredo.sizeUngoBack() != 0) {
		unredo.getGoBack(text);
		text = unredo.giveUngoBack();
	}
}
//Посмотреть состояние файла
void file::see() {
	cout << text << endl;
}
//Функции для работы Undo Redo

//Получает состояние для Undo
void states::getGoBack(string text) {
	goBack.push_back(text);
}
//Получает состояние для Redo
void states::getUngoBack(string text) {
	ungoBack.push_back(text);
}

//Возращает состояния для Undo
string states::giveGoBack() {
	string temp;
	if (goBack.size() != 0)
		temp = goBack.back();
	if (goBack.size() > 1) {
		goBack.pop_back();
	}
	return temp;
}
//Возращает состояние для Redo
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