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

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
  if (b.getgrade() > 5)
    throw Grade2LowException();

  std::cout << "<" << this->getname() << "> has been pardoned by Zaphod Beeblebrox" << std::endl;
  
}

PresidentialPardonForm& 
  PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
  this->set_type(s.gettype());
  this->set_name(s.getname());
  this->set_sg(s.get_sign_g());
  this->set_eg(s.get_exe_g());
  this->set_signed(s.get_signed());
  return *this;
}