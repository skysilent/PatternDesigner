#pragma once
class Operation {
private:
	double _a, _b;
public:
	Operation() {};
	~Operation() {};
	void setA(double a) { _a = a; }
	void setB(double b) { _b = b; }
	double getA() { return _a; }
	double getB() { return _b; }
	double virtual getResult() { return 0; }
};
class AddOperation :public Operation {
public:
	double getResult() {
		return getA() + getB();
	}
};
class SubOperation :public Operation {
public:
	double getResult() {
		return getA() - getB();
	}
};
class MultOperation :public Operation {
public:
	double getResult() {
		return getA()* getB();
	}
};
class DivOperation :public Operation {
public:
	double getResult() {
		return getA()/getB();
	}
};
class SimpleFactoryPattern
{
public:
	SimpleFactoryPattern() {};
	~SimpleFactoryPattern() {};
	Operation* createOperation(char ch) {
		Operation *p;
		switch (ch)
		{
		case '+':
			p = new AddOperation();
		case '-':
			p = new SubOperation();
		case '*':
			p = new MultOperation();
		case '/':
			p = new DivOperation();
		default:
			p = new DivOperation();
		}
		return p;
	}
};
/*
SimpleFactoryPattern sfp;
Operation *p=sfp.createOperation('/');
p->setA(27);
p->setB(9);
cout<<p->getResult();
*/
