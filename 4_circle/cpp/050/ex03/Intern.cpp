#include "Intern.hpp"

const char* Intern::TargetDoseNotExistException::what(void) const throw()
{
	return "Target Dose Not Exist";
}

Intern::Intern()
{

}
Intern::~Intern()
{

}

Intern::Intern(const Intern &obj)
{

}

Intern& Intern::operator=(const Intern &obj)
{

}

Form * Intern::makeForm(const std::string nof, const std::string tg_name)
{

  std::string types[3] = {"shrubbery", "robotomy", "presidential"};
  
  try {
    for (int i = 0; i < 3; i++)
    {
      switch(i)
      {
        case 0 : // s 72, e 45
        {
          std::cout << "Intern Creates <" << nof << ">"<< std::endl;
          return new RobotomyRequestForm(tg_name);
        }
        case 1 : // s 25 e 5
        {
          std::cout << "Intern Creates <" << nof << ">" << std::endl;
          return new PresidentialPardonForm(tg_name);
        }

        case 2 : // s 145 e 137
        {
          std::cout << "Intern Creates <" << nof << ">" << std::endl;
          return new ShrubberyCreationForm(tg_name);
        }
      }

    }
    }
  catch (std::exception &e)
  {
    throw TargetDoseNotExistException();
  }
  return NULL;
}