#include "Bureaucrat.hpp"
#include "Form.hpp"
std::ostream& operator<<(std::ostream &obj, Bureaucrat& data)
{
    	obj	<< data.getname() << ", bureaucrat of grade "
		<< data.getgrade() << std::endl;
        return (obj);
}

int main()
{
  Bureaucrat  mas("master", 1);
  Bureaucrat  head("headcheif", 75);
  Form  f1("f1", 30, 30);
  Form  f2(f1);
  Form  f3("f3", 75, 50);

  std::cout << f1 << std::endl
    << f2 << std::endl
    << f3 << std::endl;

  std::cout << std::endl;

  head.signForm(f1);
  mas.signForm(f2);
  head.signForm(f3);
  std::cout << std::endl;
  std::cout << f1 << std::endl
    << f2 << std::endl
    << f3 << std::endl;
  std::cout << std::endl;
  return 0;

}