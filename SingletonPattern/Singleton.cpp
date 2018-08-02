#include "Singleton.h"

Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}



Singleton * Singleton::getInstance()
{
	if (instance == nullptr) {
		std::lock_guard<std::mutex> lock(m_lock);
		if (instance == nullptr) {
			instance = new Singleton;
		}
	}
	return instance;
}

void Singleton::DelInstance()
{
	if (instance != nullptr) {
		std::lock_guard<std::mutex> lock(m_lock);
		if (instance != nullptr) {
			delete instance;
			instance = NULL;
		}
	}
}

void Singleton::print()
{
	printf("demo function print\n");
}
//初始化静态成员变量

Singleton* Singleton::instance = NULL;   
std::mutex Singleton::m_lock;
