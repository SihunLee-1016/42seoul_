#include "Form.hpp"
const char* Form::Grade2HighException::what(void) const throw()
{
  return "Grade Too High";
}

const char* Form::Grade2LowException::what(void) const throw()
{
  return "Grade Too Low";
}

Form::Form(const std::string str, const int sign, const int exe) : _name(str), sign_g(sign), exe_g(exe)
{
  this->sign = 0;
}

Form::Form(const Form &obj) 
  : _name(this->_name), sign(this->sign),
    sign_g(this->sign_g), exe_g(this->exe_g)

{
}

Form& Form::operator=(const Form &obj)
{

}

Form::~Form()
{

}

void	Form::besigned(const Bureaucrat obj)
{

}