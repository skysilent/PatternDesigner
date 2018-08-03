#pragma once
#include<iostream>
using namespace std;
class Memento {
private:
	int _state;
public:
	Memento(int state) {
		_state = state;
	}
	void setState(int state) {
		_state = state;
	}
	int getState() {
		return _state;
	}
};
class Orginisor {
private:
	int _state=0;
public:
	Memento* CreateMemento() {
		return new Memento(_state);
	}
	void RestoreMemento(Memento *m) {
		_state = m->getState();
	}
	void setState(int state) {
		_state = state;
	}
	int getState() {
		return _state;
	}
};
class CareTaker {
private:
	Memento * _m;
public:
	void SetMemento(Memento*m) {
		this->_m = m;
	}
	Memento*getMemento() {
		return _m;
	}
};
//int main() {
//	Orginisor orgin;
//	CareTaker ctaker;
//	
//	cout <<"first time "<< orgin.getState() << endl;
//	orgin.setState(4);
//	ctaker.SetMemento(orgin.CreateMemento());
//	cout << "second time " << orgin.getState() << endl;
//	orgin.setState(9);
//	cout << "thrid time " << orgin.getState() << endl;
//	orgin.RestoreMemento(ctaker.getMemento());
//	cout << "restore time " << orgin.getState() << endl;
//}