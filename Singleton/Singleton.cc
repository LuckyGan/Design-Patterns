 ///
 /// @file    Singleton.cc
 /// @author  zack(18357154046@163.com)
 /// @date    2017-06-08 21:23:50
 ///
#include <cstdio> 
#include <iostream>
using std::cout;
using std::endl;
//简单版的单例模式
//缺点:1、不是线程安全的,在多线程环境下是存在产生多个对象实例的可能性的
//     2、需要手动调用destroy方法去释放实例对象所占空间，不够智能
class Singleton{
private:
	static Singleton* _pInstance;
	Singleton()=default;
	~Singleton()=default;
public:
	static Singleton* getInstance(){
		if(nullptr==_pInstance){
			_pInstance=new Singleton;
		}
		return _pInstance;
	}
	static void destroy(){
		if(_pInstance){
			delete _pInstance;
		}
	}
};
Singleton* Singleton::_pInstance=nullptr;
