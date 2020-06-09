
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <conio.h>

using namespace std;

//Умный указатель
template <class T>
class smartPoint {
	T* ptr;
	int cnt;
public:
	smartPoint(T* ptr = 0);
	~smartPoint();
	T* operator->();
	void showCounter() { return cnt; }
};

//Поддержка транзакции
template <class T>
class transact {
	T* now;
	T* before;
public:
	void startTrans();
	void commit();
	void undo();
	transact() { before = NULL, now = new T; }
	~transact() { delete now, delete before; }
	T* operator->() { return now; }
};

//Пользователь
class user {
	string name="admin";
	string pas="admin";
public:
	user();
	~user() {};
	string seeName() { return name; }
	string seePas() { return pas; }

};


//Файл
class file {
	string text;
	states unredo;
	string name;
public:
	file();
	~file();
	void see();
	void undo();
	void redo();
	void work();
};

//Список состояний
class states : public file  {
	list<string> goBack;
	list<string> ungoBack;
public:
	states() {};
	~states() {};
	int sizeGoBack() { return goBack.size(); }
	int sizeUngoBack() { return ungoBack.size(); }
	string giveGoBack();
	void getGoBack(string temp);
	string giveUngoBack();
	void getUngoBack(string temp);
	void clearUndo();
};


template <class T>
T* smartPoint<T>::operator->() {
	return ptr;
}

template <class T>
smartPoint<T>::smartPoint(T* ptr) {
	if (!ptr) this->ptr = NULL;
	else {
		this->ptr = ptr;
		cnt = 1;
	}
}

template <class T>
smartPoint<T>::~smartPoint() {
	if (cnt)
		cnt--;
	if (cnt <= 0) {
		delete ptr;
	}
}

template <class T>
void transact<T>::commit() {
	delete before;
	before = NULL;
}

template <class T>
void transact<T>::undo() {
	if (before != NULL) {
		delete now;
		now = before;
		before = NULL;
	}
}

template <class T>
void transact<T>::startTrans() {
	delete before;
	before = now;
	now = new T(*before);
}