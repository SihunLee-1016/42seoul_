#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, 72, 45)
{
  this->set_type("Robotomy");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : Form(s)
{
  this->set_type("Robotomy");
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const {
  executable(b);
  int v = rand() % 10;

  if (v % 2 == 0)
  {
    std::cout << "Success in Robotomy" << std::endl;
  }
  else
    std::cout << "Fail in Robotomy" << std::endl;

}

RobotomyRequestForm& 
  RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
  this->type = s.gettype();
  this->_name = s.getname();
  this->sign_g = s.get_sign_g();
  this->exe_g = s.get_exe_g();
  this->sign = s.get_signed();
  return *this;
}