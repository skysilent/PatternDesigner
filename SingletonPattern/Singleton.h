#pragma once
#ifndef  SINGLETON_H_
#include<thread>
#include<mutex>
#include<memory.h>
class Singleton
{
private:
	static Singleton *instance;
	static std::mutex m_lock;
	Singleton();
	~Singleton();
	//·À¿½±´
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton&);
public:
	static Singleton *getInstance();
	void DelInstance();
	void print();
};

#endif //  SINGLETON_H_