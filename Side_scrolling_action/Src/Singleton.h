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
	�Eweak_ptr
		weak_ptr<TMP>��shared_ptr<TMP>�̃��\�[�X����Q�Ƃ�ێ�����
	�Eshared_ptr
		shared_ptr�͎w��̂��ꂽ���\�[�X�̏��L�������L����X�}�[�g�|�C���^�[
*/

#endif // !SINGLETON_H

