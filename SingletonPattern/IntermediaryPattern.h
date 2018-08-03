#pragma once
#include<iostream>
using namespace std;
class AbstractMediator {
public:
	virtual void setNumber(int num) = 0;
	virtual void AactionB() = 0;
	virtual void BactionA() = 0;
};
class AbstractColleague {
public:
	virtual void setNumber(int num) = 0;
	virtual int getNumber() = 0;
	virtual void setNumber(int num, AbstractMediator* am) = 0;
};

class ACollleague :public AbstractColleague {
private :
	int _num;
public:
	virtual void setNumber(int num) override
	{
		_num = num;
	}
	virtual void setNumber(int num,AbstractMediator*am) override
	{
		_num = num;
		am->AactionB();
	}
	virtual int getNumber() override
	{
		return _num;
	}
};
class BCollleague :public AbstractColleague {
private:
	int _num;
public:
	virtual void setNumber(int num) override
	{
		_num = num;
	}
	virtual void setNumber(int num, AbstractMediator*am) override
	{
		_num = num;
		am->BactionA();
	}
	virtual int getNumber() override
	{
		return _num;
	}
};
class ConcreteMediator :public AbstractMediator {
private:
	AbstractColleague * ac;
	AbstractColleague*bc;
	int _num;
public:
	ConcreteMediator(AbstractColleague*a, AbstractColleague*b) {
		ac = a;
		bc = b;
	}
	virtual void setNumber(int num)override {
		_num = num;
	};
	virtual void AactionB() override {
		cout << "AactionB()" << endl;
		_num = ac->getNumber() / 100;
		bc->setNumber(_num);
	};
	virtual void BactionA() override {
		cout << "BactionA()" << endl;
		_num = bc->getNumber() / 100;
		ac->setNumber(_num);
	};
};
//int main() {
AbstractColleague*a = new ACollleague();
//AbstractColleague *b = new BCollleague();
//AbstractMediator *am = new ConcreteMediator(a, b);
//a->setNumber(100, am);
//cout << b->getNumber() << endl;
//b->setNumber(200, am);
//cout << a->getNumber() << endl;
//}