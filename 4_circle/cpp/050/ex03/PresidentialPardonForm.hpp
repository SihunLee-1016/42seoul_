#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
class PresidentialPardonForm : public Form
{
  private:
  public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    void execute(const Bureaucrat& b) const;
    PresidentialPardonForm& operator=(const PresidentialPardonForm& s);
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& s);
};


#endif