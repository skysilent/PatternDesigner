#pragma once
#include<iostream>
using namespace std;
class BaseProduct {
public:
	virtual void dosomething() = 0;
};
class FactoryProductA :public BaseProduct {
public:
	virtual void dosomething() override 
	{
		cout << "FactoryProductA is doing something" << endl;
	}
};
class FactoryProductB:public BaseProduct {
public:
	virtual void dosomething() override
	{
		cout << "FactoryProductB is doing something" << endl;
	}
};
class BaseFactory {
public:
	virtual BaseProduct* getBaseProduct() = 0;
};
class ConcreteFactoryA:public BaseFactory {
public:
	virtual BaseProduct* getBaseProduct() override 
	{
		return new FactoryProductA();
	}
};
class ConcreteFactoryB :public BaseFactory {
public:
	virtual BaseProduct* getBaseProduct() override
	{
		return new FactoryProductB();
	}
};
//
//BaseFactory*bf = new ConcreteFactoryB();
//BaseProduct *bp = bf->getBaseProduct();
//bp->dosomething();
//
//BaseFactory*bf2 = new ConcreteFactoryA();
//BaseProduct *bp2 = bf2->getBaseProduct();
//bp2->dosomething();