#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form(target, 25, 5)
{
  this->set_type("PresidentialPardon");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : Form(s)
{
  this->set_type("PresidentialPardon");
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
  executable(b);
  std::cout << "<" << this->getname << "> has been pardoned by Zaphod Beeblebrox" << std::endl;
  
}

PresidentialPardonForm& 
  PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
  this->type = s.gettype();
  this->_name = s.getname();
  this->sign_g = s.get_sign_g();
  this->exe_g = s.get_exe_g();
  this->sign = s.get_signed();
  return *this;
}