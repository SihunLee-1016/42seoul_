#include "Form.hpp"
#include "Bureaucrat.hpp"
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
	this->sign = false;
}

Form::Form(const Form &obj) 
	: _name(this->_name), sign(this->sign),
		sign_g(this->sign_g), exe_g(this->exe_g)
{
	if (sign_g > 150 || exe_g > 150)
		throw Grade2LowException();
	else if (sign_g < 1 || exe_g < 1)
		throw Grade2HighException();
}

Form& Form::operator=(const Form &obj)
{
	*(const_cast<std::string*>(&_name)) = obj.getname();
	*(const_cast<int*>(&sign_g)) = obj.get_sign_g();
	*(const_cast<int*>(&exe_g)) = obj.get_exe_g();
	sign = obj.sign;
}

Form::~Form()
{

}

void	Form::besigned(const Bureaucrat &obj)
{
	if (obj.getgrade() <= this->sign_g)
		this->sign = true;
	else
		throw Grade2LowException();
}

std::string Form::getname() const
{
 return (this->_name);
}

int Form::get_sign_g() const
{
	return (this->sign_g);
}

int Form::get_exe_g() const
{
	return (this->exe_g);
}

int Form::get_signed() const
{
	return (this->sign);
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
  return o << "<" << f.getname() << ">, sign grade <"
          << f.get_sign_g() << ">, exec grade <"
          << f.get_exe_g() << ">, signed <"
          << f.get_signed() << ">";
}
