#ifndef SINGLETON_H
#define SINGLETON_H

#include<memory>

template<class T>
class Singleton
{
protected:

	Singleton() {}
	virtual ~Singleton() {}
public:

	static std::weak_ptr<T>Instance() 
	{
		if (!instance)
		{
			instance.reset(new T());
		}
		return instance;
	}
private:

	static std::shared_ptr<T>instance;
};

template<class T>
std::shared_ptr<T> Singleton<T>::instance = nullptr;

/*
	・weak_ptr
		weak_ptr<TMP>はshared_ptr<TMP>のリソースを弱参照を保持する
	・shared_ptr
		shared_ptrは指定のされたリソースの所有権を共有するスマートポインター
*/

#endif // !SINGLETON_H

