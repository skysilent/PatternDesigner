#pragma once
#include<iostream>
using namespace std;
class Component {
public:
	virtual void operation() = 0;
};
class Decorator:public Component {
private:
	Component *p;
public:
	Decorator(Component*c) {
		p = c;
	}
	virtual void operation() override{
		p->operation();
	}
};
class ConcreteComponet :public Component {
private:
public:
	ConcreteComponet() {
	}
	virtual void operation() override {
		cout <<"ConcreteComponet" <<endl;
	}
};

class ConcreteDecorator :public Decorator {
private:
	Component*p;
public:
	ConcreteDecorator(Component*c):Decorator(c) {
		p = c;
	}
	virtual void operation() override {
		cout << "ConcreteDecorator" << endl;
		p->operation();
	}
};
//Component *c = new ConcreteDecorator(new ConcreteComponet());
//c->operation();