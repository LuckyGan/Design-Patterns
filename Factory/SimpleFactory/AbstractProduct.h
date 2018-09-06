#ifndef __ABSTRACT_PRODUCT_H__
#define __ABSTRACT_PRODUCT_H__ 

#include <iostream>

class AbstractProduct {
public:
    AbstractProduct();
    virtual ~AbstractProduct();
public:
    virtual void operation() = 0;
};

class ProductA : public AbstractProduct {
public:
    ProductA() {
    }
    virtual ~ProductA() override {
    }
public:
    virtual void operation() override {
        std::cout << "ProductA operation!" << std::endl;
    }
};

class ProductB : public AbstractProduct {
public:
    ProductB() {
    }
    virtual ~ProductB() override {
    }
public:
    virtual void operation() override {
       std::cout << "ProductB operation!" << std::endl; 
    }
};

#endif