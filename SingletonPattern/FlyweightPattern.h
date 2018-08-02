#pragma once
#include<iostream>
#include<map>
using namespace std;
class Flyweight{
public:
    virtual void operation()=0;
};
class ConcreteFlyweight:public Flyweight{
private:
    int item;
public:
    ConcreteFlyweight(int intItem){
        item=intItem;
    }
    virtual void operation() override
    {
        cout<<"ConcreteFlyweight is help "<<item<<endl;
    }
};
/*
class ConcreteFlyweightB:public Flyweight{
private:
    int item;
public:
    ConcreteFlyweightB(int intItem){
        item=intItem;
    }
    virtual void operation() override
    {
        cout<<"ConcreteFlyweightA is help"<<item<<endl;
    }
}*/
class FlyweightFactory{
private: 
    map<int,Flyweight*> flies;
public:
    Flyweight* factory(int iname){
		Flyweight* fw=NULL;
		map<int, Flyweight* >::iterator a = flies.find(iname);
		if (a != flies.end()) {
			fw = a->second;
		}
		else {
			fw = new ConcreteFlyweight(iname);
			flies.insert(pair<int, Flyweight*>(iname, fw));
		}
        return fw;
    }
};
/*
FlyweightFactory ff;
for (int i = 0; i < 4; i++) {
	Flyweight*f = ff.factory(i);
	f->operation();
}
*/