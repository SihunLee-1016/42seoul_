#include <iostream>
#include <string>

class Test
{
    private:
        std::string *k;
        int a;
    public:
        Test();
        ~Test();
        void    print()
        {
            a = 1;
            std::cout << "test member function"<<std::endl;
            std::cout << "TEST CLASS , a :  " << a << std::endl;
        }
};

Test::Test()
{
    k = new std::string[10];
    a = 0;
    std::cout << "constructor TEST CLASS , a :  " << a << std::endl;
}

Test::~Test()
{
    delete k;
}

class Base {
    private:
        std::string s;
    public :
    Base() : s("Base")
    {
        std::cout << "constructor Base class" << std::endl;
    }
    void    what()
    {
        std::cout << s << std::endl;
    }
};

class Derived : public Base
{
    private:
        std::string s;
        Test ss;
    public :
    //@@@기본 생성자에 멤버 초기화 변수로 먼저 기반의 생성을 먼저 처리해야한다.@@@
    Derived() : Base(), s("Derived")
    {
        std::cout << "Derived Class" << std::endl;
        what();
    }
    void what() {  std::cout << s <<  std::endl; }
    void    print()
    {
        ss.print();
    }

};



int main()
{
    Base *base;
    Derived *der;
    std::cout << "@@" << std::endl;
    base = new Base;
    std::cout << "//" << std::endl;


    std::cout << "%%" << std::endl;
    der = new Derived; 
    der->print();
    std::cout << "!!" << std::endl;

    delete base;

}