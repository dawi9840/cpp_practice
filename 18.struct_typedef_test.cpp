// Reference: https://ithelp.ithome.com.tw/m/articles/10284046
// g++ -c 18.struct_typedef_test.cpp && g++ -o 18.struct_typedef_test.exe 18.struct_typedef_test.o

# include <iostream>
#include <string> 

using namespace std;

struct Person
{
    float height;
    float weight;
    int age;
    string citizenship;
    string name;
};

typedef struct PPAP_fruit{
    string apple;
    int pen;
}ppap_fruit;

float BMI_calculate(float height_cm, float weight)
{
    float height_meter = height_cm / 100;
    return weight / (height_meter * height_meter);
}

void struct_test()
{
    // struct Person P;
    Person P;
    P.age = 28;
    P.height = 172;
    P.weight = 75;
    P.citizenship = "Taiwan";
    P.name = "Dawi";

    cout << "Name: " << P.name << endl;
    cout << "Age: " << P.age << endl;
    cout << "Citizenship: " << P.citizenship << endl;
    cout << "Height: " << P.height << " cm" << endl;
    cout << "Weight: " << P.weight << " kg" << endl;
    cout << "BMI: " << BMI_calculate(P.height, P.weight) << endl;
}

void typedef_test()
{
    ppap_fruit fruit;
    fruit.apple = "Taiwan Apple";
    fruit.pen = 21;
    cout << endl << "apple: " << fruit.apple << endl;
    cout << "pen: " << fruit.pen << " NT dollars" <<endl;
}

int main()
{
    struct_test();
    typedef_test();
}