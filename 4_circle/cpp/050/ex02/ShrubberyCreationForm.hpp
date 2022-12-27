#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
  private:

  public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    void execute(const Bureaucrat& b) const;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& s);
};


#endif