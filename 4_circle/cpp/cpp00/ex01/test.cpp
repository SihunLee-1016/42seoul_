#include <iostream>
using namespace std;

class A {
    int num;
public:
     
     //public에 따로 말이 없고 class명과 동일한 것이 있다면 이는 생성자에 해당.
    A() {
        this->num = 10;
    }

    int get_Num() {
        return num;
    }
};

int main(void) {

    A a;

    cout << a.get_Num() << endl;
    return 0;
}