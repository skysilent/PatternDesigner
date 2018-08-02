#pragma once
#include<iostream>
using namespace std;
class FacadeModuleA {
public:
	void Start() {
		cout << "ModelA is stating" << endl;
	}
	void Stop() {
		cout << "ModelA has stoped" << endl;
	}
};
class FacadeModuleB {
public:
	void Start() {
		cout << "ModelB is stating" << endl;
	}
	void Stop() {
		cout << "ModelB has stoped" << endl;
	}
};
class FacadeModuleC {
public:
	void Start() {
		cout << "ModelC is stating" << endl;
	}
	void Stop() {
		cout << "ModelC has stoped" << endl;
	}
};
class Facade {
private:
	FacadeModuleA *a;
	FacadeModuleB *b;
	FacadeModuleC *c;
public :
	void setA(FacadeModuleA*fma) {
		a=fma;
	}
	void setB(FacadeModuleB*fmb) {
		b = fmb;
	}
	void setC(FacadeModuleC*fmc) {
		c = fmc;
	}
	void Start() {
		a->Start();
		b->Start();
		c->Start();
	}
	void Stop() {
		c->Stop();
		b->Stop();		
		a->Stop();
	}
};
//
//FacadeModuleA *a = new FacadeModuleA();
//FacadeModuleB *b = new FacadeModuleB();
//FacadeModuleC *c = new FacadeModuleC();
//Facade f;
//f.setA(a);
//f.setB(b);
//f.setC(c);
//f.Start();
//f.Stop();