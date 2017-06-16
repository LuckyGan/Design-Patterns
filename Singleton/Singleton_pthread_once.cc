 ///
 /// @file    atexitSingleton.cc
 /// @author  zack(18357154046@163.com)
 /// @date    2017-06-15 19:18:21
//调用pthread_once方法的单例模式
//优点:1、利用pthread_once方法中注册的函数能在多线程环境下只被执行一次的特性，解决线程安全问题
//     2、利用atexit回调函数，自动释放对象
//     3、在未调用getInstance方法的情况下，在内存空间中不存在任何对象（解决了饱汉式的问题）
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance(){
		pthread_once(&_once,init);
		return _pInstance;
	}
	static void init(){
		_pInstance=new Singleton();
		atexit(destroy);
	}
	static void destroy(){
		if(_pInstance){
			delete _pInstance;
		}
	}
private:
	Singleton()=default;
	~Singleton()=default;
private:
	static Singleton* _pInstance;
	static pthread_once_t _once;
};
Singleton* Singleton::_pInstance=nullptr;
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;
