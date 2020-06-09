#include "Header.h"


int main() {
	string name, pas;
	smartPoint<user> editor(new user);
	char swch;

	cout << "Enter login\n";
	getline(cin, name);
	cout << "Enter password\n";
	getline(cin, pas);

	if (name == editor->seeName() && pas == editor->seePas()) {
		transact<file> inf;
		inf.startTrans();
		system("cls");
		while (1) {
			system("cls");
			cout << "1 - Work with file\n2 - Undo\n3 - Redo\n4 - View\n5 - Save\n0 - Eixt\n";
			swch = _getch();
			switch (swch) {
			case '1':
				system("cls");
				inf->work();
				inf.commit();
				break;
			case '2':
				inf->undo();
				cout << "Undone\n";
				system("pause");
				break;
			case '3':
				inf->redo();
				cout << "Redone\n";
				system("pause");
				break;
			case '4':
				inf->see();
				system("pause");
				break;
			case '5':
				inf.commit();
				cout << "Saved\n";
				system("pause");
				break;
			case '0':
				inf.commit();
				return 0;
			default:
				cout << "\nTry again\n";
				cin.clear();
				system("pause");
				break;
			}
		}
	}
	else {
		system("cls");
		cout << "Incorrect login or password\n";
	}
}