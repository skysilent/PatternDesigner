#pragma once
#include<iostream>
#include<vector>
using namespace std;
class IIterator {
public:
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual bool isFirst() = 0;
	virtual bool isLast() = 0;
};
class ICollections {
public :
	virtual IIterator*getIterator() = 0;
	virtual int getLength() = 0;
	virtual int getItem(int index) = 0;
};
class ConcreteIterator :public IIterator {
private:
	ICollections *_cc;
	int _index;
public:
	ConcreteIterator(ICollections *cc) {
		_cc = cc;
		_index = 0;
	}
	virtual void next() override
	{
		_index++;
	}
	virtual bool hasNext() override
	{
		if (_index < _cc->getLength()-1) {
			return true;
		}
		else return false;
	}
	virtual bool isFirst() override
	{
		if (_index == 0)
			return true;
		else return false;
	}
	virtual bool isLast() override
	{
		if (_index == _cc->getLength()-1) {
			return true;
		}
		else return false;
	}
};
class ConcreteCollection:public ICollections{
private:
	vector<int> collections;
	int _length;
public:
	 ConcreteCollection() {
		 collections.push_back(10);
		 collections.push_back(1);
		 collections.push_back(2);
		 collections.push_back(13);
		 collections.push_back(6);
		 collections.push_back(5);
		 _length = collections.size();;
	}
	virtual IIterator*getIterator() override
	{
		return new ConcreteIterator(this);
	}
	virtual int getLength() override {
		return _length;
	}
	virtual int getItem(int index) override {
		return collections[index];
	}
	~ConcreteCollection()
	{
	}
};
//int main() {
//	ICollections *c = new ConcreteCollection();
//	IIterator *ii = new ConcreteIterator(c);
//	cout << ii->hasNext() << endl;
//	cout << ii->isFirst() << endl;
//}