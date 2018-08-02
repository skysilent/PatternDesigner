#pragma once
#include<iostream>
#include<list>
using namespace std;
class Component {
public:
	virtual void AddComponent(Component*p) = 0;
	virtual void RemoveComponent(Component*p) = 0;
	virtual void Display(int level) = 0;
};
class Composite :public Component {
private :
	list<Component*> list;
	char * compositeName;
public:
	Composite(char* name) {
		compositeName = name;
	}
	virtual void AddComponent(Component*p)override {
		list.push_back(p);
	}
	virtual void RemoveComponent(Component*p) {
		list.remove(p);
	}
	virtual void Display(int level) {
		cout << "composite node"<<compositeName <<" level "<<level<< endl;
		for (auto *a : list) {
			a->Display(level+1);
		}
	};
};
class Leaf :public Component {
private:
	char* leafname;
public:
	Leaf(char* name) {
		leafname = name;
	}
	virtual void AddComponent(Component*p) override {
		cout << "该节点已经是叶子节点，不能添加下级" << endl;
	}
	virtual void RemoveComponent(Component*p) override {
		cout << "该节点已经是叶子节点，不能删除下级" << endl;
	}
	virtual void Display(int level) override {
		cout << "该节点已经是叶子节点，名字为 "<<leafname <<" level "  <<level<< endl;
	} ;
};
/*
Leaf * l1 = new Leaf("leaf1");
Leaf * l2 = new Leaf("leaf2");
Leaf * l3 = new Leaf("leaf3");
Leaf * l4 = new Leaf("leaf4");
Leaf * l5 = new Leaf("leaf5");
Composite *c1 = new Composite("Composite1");
Composite *c2 = new Composite("Composite2");
Composite *c3 = new Composite("Composite3");
c2->AddComponent(l1);
c2->AddComponent(l2);
c2->AddComponent(l3);
c3->AddComponent(l4);
c2->RemoveComponent(l3);
c1->AddComponent(c2);
c1->AddComponent(c3);
c1->AddComponent(l5);
c1->Display(1);
*/