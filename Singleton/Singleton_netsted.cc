//自动释放版单例模式
//确定：线程不安全，多线程下存在创建多个实例对象的可能性
//优点：利用嵌套类可以访问外部类数据成员的特性，实现自动释放对象实例

#include <cstdio> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton {
private:
	class AutoRelease {
		public:
			AutoRelease() = default;
			~AutoRelease() {
				if (_pInstance) {
					delete _pInstance;
				}
			}
	};
public:
	static Singleton* getInstance() {
		if (nullptr == _pInstance) {
			_pInstance = new Singleton;
		}
		return _pInstance;
	}
private:
	Singleton() = default;
	~Singleton() = default;
private:
	static Singleton* _pInstance;
	static AutoRelease _autoRelease;
};
Singleton* Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_autoRelease;
