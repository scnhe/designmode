#include<iostream>
#include<mutex>
using namespace std;

//单例模式 ---懒汉模式，非线程安全
class Singleton
{
public:
	static Singleton * getInstance();
	~Singleton() {}
private:
	static Singleton * m_pSingleton;
	Singleton() {}
	Singleton(const Singleton &obj) = delete;
	Singleton & operator = (const Singleton &obj) = delete;

};
#ifdef _LAZE_

Singleton * Singleton::m_pSingleton = nullptr;
#ifdef _THREAD_SAFE_
mutex t;
#endif
Singleton * Singleton::getInstance()
{
	if (m_pSingleton == nullptr)
	{
#ifdef  _THREAD_SAFE_
		t.lock();
#endif //  _THREAD_SAFE_

		m_pSingleton = new Singleton;  //注意delete释放内存

#ifdef  _THREAD_SAFE_
		t.unlock();
#endif //  _THREAD_SAFE_
	}
	return m_pSingleton;
}

#else
Singleton * Singleton::m_pSingleton = new Singleton();//线程安全，注意delete
Singleton * Singleton::getInstance()
{
	return m_pSingleton;
}

#endif // _LAZE_

int main(void)
{
	Singleton * sp = Singleton::getInstance();
	return 0;
}




//单例模式  饿汉模式