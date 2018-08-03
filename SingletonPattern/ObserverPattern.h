#pragma once
#include<iostream>
#include<list>
using namespace std;
class Obeserver {
public:
	virtual void Update(char*) = 0;
};
class Subject {
public:
	virtual void Attach(Obeserver*) = 0;
	virtual void Detach(Obeserver*) = 0;
	virtual void notify(char*) = 0;
};

class ConcreteSubject :public Subject {
private:
	list<Obeserver *> _oblist;
public:
	virtual void Attach(Obeserver*ob) override
	{
		_oblist.push_back(ob);
	};
	virtual void Detach(Obeserver*ob)override
	{
		_oblist.remove(ob);
	};
	virtual void notify(char*message)override
	{
		for (auto &item : _oblist) {
			item->Update(message);
		}
	};
};
class ConcreteObserver :public Obeserver {
private :
	int _id;
public:
	ConcreteObserver(int id) {
		_id = id;
	}
	virtual void Update(char* message)override {
		cout <<_id <<" was notify "<<message << endl;
	}
};
//int main() {
//	Obeserver* b1 = new ConcreteObserver(1);
//	Obeserver* b2 = new ConcreteObserver(2);
//	Obeserver* b3 = new ConcreteObserver(3);
//	Subject *s = new ConcreteSubject();
//	s->Attach(b1);
//	s->Attach(b2);
//	s->Attach(b3);
//	s->Detach(b2);
//	s->notify("update");
//}