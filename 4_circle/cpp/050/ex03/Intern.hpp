#ifndef INTERN_HPP
# define INTERN_HPP
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
  public:
	class TargetDoseNotExistException : public std::exception {
			const char* what(void) const throw();
	};
    Intern();
    Intern(const Intern &obj);
    Intern& operator=(const Intern &obj);
    ~Intern();
    Form *makeForm(const std::string nof, const std::string tg_name);
};


#endif