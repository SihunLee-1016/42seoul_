#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &obj, Bureaucrat& data)
{
    	obj	<< data.getname() << ", bureaucrat of grade "
		<< data.getgrade() << std::endl;
        return (obj);
}

int main()
{
    Bureaucrat A("AA", 1);
    Bureaucrat B("BB", 150);
    Bureaucrat C("CC", 50);
    Bureaucrat D("DD", -1);
    Bureaucrat E("EE", 151);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << A;
    std::cout << B;
    std::cout << C;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    C.grade_down();
    C.grade_down();
    C.grade_down();

    std::cout << C;
    
    std::cout << std::endl;
    std::cout << std::endl;

    C.grade_up();
    C.grade_up();
    C.grade_up();
    C.grade_up();
    C.grade_up();    
    std::cout << C;

    std::cout << std::endl;
    std::cout << std::endl;

    A.grade_up();
    std::cout << A;

    std::cout << std::endl;
    std::cout << std::endl;
    
    B.grade_down();
    std::cout << B;

}