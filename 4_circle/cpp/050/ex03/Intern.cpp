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
  (void)obj;
}

Intern& Intern::operator=(const Intern &obj)
{
  (void)obj;
  return (*this);
}

Form * Intern::makeForm(const std::string nof, const std::string tg_name)
{
  std::string types[3] = {"shrubbery", "robotomy", "presidential"};
  int i;

  for (i = 0; i < 3 && (nof != types[i]); i++)
    ;

  try{
    switch(i) {
      case 0 :
        std::cout << "Intern Creates <" << nof << ">" << std::endl;
          return new ShrubberyCreationForm(tg_name);
      case 1 :
        std::cout << "Intern Creates <" << nof << ">"<< std::endl;
          return new RobotomyRequestForm(tg_name);

      case 2 :
        std::cout << "Intern Creates <" << nof << ">" << std::endl;
          return new PresidentialPardonForm(tg_name);
      default :
        throw TargetDoseNotExistException();
    }
  }
  catch (std::exception &e){
    std::cerr << e.what() << std::endl;
    throw e;
  }
    // try{
    //   if (nof == "shrubbery") {
    //     std::cout << "Intern Creates <" << nof << ">" << std::endl;
    //     return new ShrubberyCreationForm(tg_name);
    //   }
    //   else if (nof == "robotomy") {
    //     std::cout << "Intern Creates <" << nof << ">"<< std::endl;
    //     return new RobotomyRequestForm(tg_name);
    //   }
    //   else if (nof == "presidential") {
    //     std::cout << "Intern Creates <" << nof << ">" << std::endl;
    //     return new PresidentialPardonForm(tg_name);
    //   }
    //   else
    //     throw TargetDoseNotExistException();
    // }
    // catch (std::exception &e) {
    //   std::cerr << e.what() << std::endl;
    //   return NULL;
    // }
}