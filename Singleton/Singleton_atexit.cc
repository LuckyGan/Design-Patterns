//饱汉式单例模式
//优点：1、利用atexit回调函数，自动释放对象
//      2、将静态数据成员初始化时间提前(饱汉式),解决线程不安全的问题
//缺点：1、不管有没有调用getInstance方法，内存中都存在一个实例对象，不符合某些情况下的单例模式要求

#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton {
public:
	static Singleton* getInstance() {
		if (nullptr == _pInstance) {
			_pInstance = new Singleton();
			atexit(destroy);
		}
		return _pInstance;
	}
	static void destroy() {
		if (_pInstance) {
			delete _pInstance;
		}
	}
private:
	Singleton() = default;
	~Singleton() = default;
private:
	static Singleton* _pInstance;
};
Singleton* Singleton::_pInstance = Singleton::getInstance();
