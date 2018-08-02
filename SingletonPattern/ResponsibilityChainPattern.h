#pragma once
#include<iostream>
#include<vector>
using namespace std;
class ResponsibilityChain {
private:
	ResponsibilityChain *rc;
public :
	ResponsibilityChain * getSuccesser() {
		return rc;
	}
	virtual void Successer(ResponsibilityChain*p){
		rc=p;
	}
	virtual void process(char* message) = 0;
	virtual ~ResponsibilityChain() = 0;
};
class ResponsibilityChainA:public ResponsibilityChain {
public:
	void process(char* message) {
		cout << message << " was printed by ResponsibilityChainA" << endl;
		if (getSuccesser() != nullptr) {
			getSuccesser()->process(message);
		}
	}
	~ResponsibilityChainA() {};
};
class ResponsibilityChainB :public ResponsibilityChain {
public:
	void process(char* message) {
		cout << message << " was printed by ResponsibilityChainB" << endl;
		if (getSuccesser() != nullptr) {
			getSuccesser()->process(message);
		}
	}
	~ResponsibilityChainB() {};
};

//ResponsibilityChain *p1 = new ResponsibilityChainA();
//ResponsibilityChain *p2 = new ResponsibilityChainB();
//p2->Successer(p1);
//p2->process("from p1");