#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
std::ostream& operator<<(std::ostream &obj, Bureaucrat& data)
{
    	obj	<< data.getname() << ", bureaucrat of grade "
		<< data.getgrade() << std::endl;
        return (obj);
}

int main()
{
  Intern someRandomIntern;
  Form* rrf;
  
  rrf = someRandomIntern.makeForm("shrubberry", "silee");

  std::cout << rrf->getname() << std::endl;

  delete rrf;
}