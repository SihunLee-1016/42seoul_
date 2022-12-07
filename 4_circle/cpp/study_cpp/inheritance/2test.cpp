#include <iostream>
#include <string>
class Base {
    private:
        std::string s;
    public :
    Base() : s("Base")
    {
        std::cout << "Base class" << std::endl;
    }
    void    what()
    {
        std::cout << s << std::endl;
    }
};

class Derived : public Base
{
    std::string s;

    public :
    //@@@기본 생성자에 멤버 초기화 변수로 먼저 기반의 생성을 먼저 처리해야한다.@@@
    Derived() : Base(), s("Derived")
    {
        std::cout << "Derived Class" << std::endl;
        what();
    }
    void what() {  std::cout << s <<  std::endl; }

};

int main() {
   std::cout << " === 기반 클래스 생성 ===" <<  std::endl;
  Base p;

   std::cout << " === 파생 클래스 생성 ===" <<  std::endl;
  Derived c;

  return 0;
}