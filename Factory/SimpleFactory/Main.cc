#include "SimpleFactory.h"

int main() {
    AbstractFactory* factory = new SimpleFactory();
    AbstractProduct* product = factory->createProduct(1);
    product->operation();
    delete product;
    product = nullptr;

    product = factory->createProduct(2);
    product->operation();
    delete product;
    product = nullptr;
    return 0;
}