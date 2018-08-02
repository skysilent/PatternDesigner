#pragma once
#include<iostream>
class AdapterClassA
{
public:
	AdapterClassA() {};
	~AdapterClassA(){}
	void Print() {
		printf("print A\n");
	}
};
class AdapterClassB
{
public:
	AdapterClassB(){}
	~AdapterClassB() {}
	virtual void PRINT() {
		printf("printB");
	}
};
class AdapterChanger:public AdapterClassB {
private:
	AdapterClassA m_a;
public:
	AdapterChanger(AdapterClassA adapterA) {
		m_a = adapterA;
	}
	void PRINT() {
		m_a.Print();
	}
};
