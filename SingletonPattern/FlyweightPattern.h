#pragma once
#include<iostream>
using namespace std;
class Flyweight{
public:
    virtual void operation()=0;
}
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
}
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
    map<int,Flyweight*> mp;
public:
    Flyweight* factory(int iname){
        Flyweight *fw=files.get(iname);
        if(fw==nullptr){
            fly=new ConcreteFlyweight(iname);
            files.push_back(iname,fly);
        }
        return fw;
    }
}