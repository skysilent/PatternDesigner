#pragma once
#include<iostream>
#include<string>
using namespace std;
class AbstractExpression {
public:
	virtual string operation() const= 0;
};
class NumberExpression :public AbstractExpression {
private:
	double _num;
	string values;
public:
	NumberExpression(double num) {
		_num = num;
		values.append(to_string(num));
	}
	virtual string operation()const override
	{
		return values;
	}
};
class AddOperationExpress :public AbstractExpression {
private:
	AbstractExpression * _left;
	AbstractExpression *_right;
	string values;
public:
	AddOperationExpress(AbstractExpression*l, AbstractExpression*r) {
		_left = l;
		_right = r;
		values.append("( ").append(l->operation()).append("  +  ").append(r->operation()).append("  )");
	}
	virtual string operation()const  override
	{
		return values;
	}
};
class MultiOperationExpress :public AbstractExpression {
private:
	AbstractExpression * _left;
	AbstractExpression *_right;
	string values;
public:
	MultiOperationExpress(AbstractExpression*l, AbstractExpression*r) {
		_left = l;
		_right = r;
		values.append("").append(l->operation()).append("*").append(r->operation());
	}
	virtual string operation()const  override
	{
		return values;
	}
};
//int main() {
//AbstractExpression *p = new AddOperationExpress(new NumberExpression(3), new NumberExpression(4));
//AbstractExpression *s = new MultiOperationExpress(p, new NumberExpression(6));
//cout << s->operation();
//}