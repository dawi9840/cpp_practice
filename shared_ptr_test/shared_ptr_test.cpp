// 範例4. 存取 std::shared_ptr 的原始指標
// 透過std::shared_ptr.get()可以取得原始指標，
// 大概有兩種情況會使用到，一種是需要呼叫傳統的api，會需要傳遞原始指標，另一種是直接用原始指標

// g++ std-shared-ptr.cpp -o a.out -std=c++11
#include <iostream>
#include <string>
#include <memory>

class LargeObject {
public:
    void DoSomething() {
        printf("Do_Some_thing\n");
    }
    void DoSomething2() {
        printf("Do_Some_thing_22222\n");
    }
};

void LegacyLargeObjectFunction(LargeObject *lo) {
    printf("LegacyLargeObjectFunction\n");
    lo->DoSomething();
}

int main() {
    printf("\n===1===\n");
    // Create the object and pass it to a smart pointer
    std::shared_ptr<LargeObject> pLarge(new LargeObject());

    printf("\n===2===\n");
    // Call a method on the object
    pLarge->DoSomething();
    pLarge->DoSomething2();

    printf("\n===3===\n");
    // 傳遞原始指標給 legacy API
    LegacyLargeObjectFunction(pLarge.get());

    printf("\n===4===\n");
    // 用原始指標去接
    LargeObject *p = pLarge.get();
    LegacyLargeObjectFunction(p);

    printf("\n===5===\n");
    return 0;

}