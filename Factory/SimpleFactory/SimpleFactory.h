#ifndef __SIMPLE_FACTORY_H__
#define __SIMPLE_FACTORY_H__

#include "AbstractProduct.h"

class AbstractFactory {
public:
    AbstractFactory() {
    }
    virtual ~AbstractFactory() {
    }
public:
    virtual AbstractProduct* createProduct(int type) = 0;
};

class SimpleFactory : public AbstractFactory {
public:
    SimpleFactory() {
    }
    ~SimpleFactory() {
    }
public:
    AbstractProduct* createProduct(int type) override {
        AbstractProduct* tmp = nullptr;
        switch (type) {
            case 1:
                tmp = new ProductA();
                break;
            case 2:
                tmp = new ProductB();
                break;
            default:
                break;
        }
        return tmp;
    }
};

#endif