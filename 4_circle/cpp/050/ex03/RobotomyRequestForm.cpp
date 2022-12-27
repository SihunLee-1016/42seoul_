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

void RobotomyRequestForm::execute(Bureaucrat const & b) const {
  
  try {
    if (b.getgrade() > 45)
      throw Form::Grade2LowException();
    if(this->get_signed() != 1)
      throw Form::NotSignedException();
		}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

  srand((unsigned int)time(NULL));
  if (rand() % 2 == 0)
  {
    std::cout << "Success in Robotomy" << std::endl;
  }
  else
    std::cout << "Fail in Robotomy" << std::endl;

}

RobotomyRequestForm& 
  RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
  this->set_type(s.gettype());
  this->set_name(s.getname());
  this->set_sg(s.get_sign_g());
  this->set_eg(s.get_exe_g());
  this->set_signed(s.get_signed());
  return *this;
}