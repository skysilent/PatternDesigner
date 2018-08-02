#pragma once
#include<iostream>
using namespace std;
class CommandReciever {
public:
	void doA() {
		cout << "doA()" << endl;
	}
	void doB() {
		cout << "doB()" << endl;
	}
};
class ICommand {
public:
	virtual void excute() = 0;
};
class CommandA :public ICommand {
private :
	CommandReciever *rc;
public:
	 ~CommandA() {}
	CommandA(CommandReciever *r) {
		rc = r;
	}
	virtual void excute() override {
		rc->doA();
	}
};
class CommandB :public ICommand {
private:
	CommandReciever *rc;
public:
	 ~CommandB() {};
	CommandB(CommandReciever *r) {
		rc = r;
	}
	virtual void excute() override {
		rc->doB();
	}
};
class Invoker {
private :
	ICommand *icommand;
public:
	~Invoker()
	{

	}
	void setCommand(ICommand*ic) {
		icommand=ic;
	}
	void RunCommand() {
		icommand->excute();
	}
};
//CommandReciever *creviever = new CommandReciever();
//ICommand *a = new CommandA(creviever);
//ICommand *b = new CommandB(creviever);
//Invoker invoker;
//
//invoker.setCommand(b);
//invoker.RunCommand();
//invoker.setCommand(a);
//invoker.RunCommand();