#include <iostream>

class MyCar {
private:
    int fuel = 0;
    bool power = false;

public:
    void go() {
        this->fuel--;
    }

    void oiling(int n) {
        this->fuel += n;
    }

    void fuel_check() {
        std::cout << "연료 : " << fuel << std::endl; 
    }
};

