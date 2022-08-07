// g++ std-shared-ptr-exp1.cpp -o a.out -std=c++11
#include <iostream>
#include <string>
#include <memory>

class LargeObject {
public:
    LargeObject() {
        printf("This is LargeObject::LargeObject()\n");
    }

    ~LargeObject() {
        printf("LargeObject::~LargeObject()\n");
    }

    void DoSomething() {
        printf("DoSomething, x=%d\n", x);
    }

    int x = 10;
};

int main() {
    printf("\n=========1=========\n");
    LargeObject *p = new LargeObject();
    printf("\n----------------------\n");

    p->DoSomething();
    printf("memory location: %p\n", p);

    printf("\n\n=========2=========\n");
    std::shared_ptr<LargeObject> pLarge(p);
    pLarge->DoSomething();
    printf("%p\n", pLarge.get());
    printf("memory location: %p\n", p);

    printf("\n=========3=========\n");
    delete p; // double free or corruption
    printf("\n=========4=========\n");
    return 0;
}