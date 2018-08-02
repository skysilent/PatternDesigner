#pragma once
#include<iostream>
#include<vector>
using namespace std;
class BuilderProduct {
private:
	vector<char*> vcs;
public:
	void Add(char* cs) {
		vcs.push_back(cs);
	}
	void Show() {
		for (auto cs : vcs) {
			cout << cs << endl;
		}
	}
};
class Builder {
public :
	virtual void buildPartA()=0;
	virtual void buildPartB()=0;
	virtual void buildPartC()=0;
	virtual BuilderProduct getBuilderProduct() = 0;
};
class BuildDirector {
public:
	void Create(Builder*b) {
		b->buildPartA();
		b->buildPartB();
		b->buildPartC();
	}
};
class ConcreteBuilder :public Builder {
private:
	BuilderProduct product;
public:
	

	// Í¨¹ý Builder ¼Ì³Ð
	virtual void buildPartA() override {
		product.Add("BuilPartA");
	}

	virtual void buildPartB() override {
		product.Add("BuilPartB");
	}

	virtual void buildPartC() override {
		product.Add("BuilPartC");
	}
	virtual  BuilderProduct getBuilderProduct() override {
		return product;
	}
};
//int main() {
//	Builder *b = new ConcreteBuilder();
//BuildDirector bd;
//bd.Create(b);
//BuilderProduct p = b->getBuilderProduct();
//p.Show();
//	system("pause");
//}