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

Form::Form(void) : sign_g(0), exe_g(0)
{
	set_type("Form");
}

Form::Form(const std::string str1, const int sg, const int eg) : _name(str1), sign_g(sg), exe_g(eg)
{
	this->sign = false;
}

Form::Form(const Form &obj) 
	: _name(obj.getname()), sign(obj.get_signed()),
		sign_g(obj.get_sign_g()), exe_g(obj.get_exe_g())
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
	return (*this);
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

std::string Form::gettype() const
{
 return (this->_type);
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

void	Form::set_type(const std::string str)
{
	*(const_cast<std::string*>(&this->_type)) = str;
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
  return o << "<" << f.getname() << ">, sign grade <"
          << f.get_sign_g() << ">, exec grade <"
          << f.get_exe_g() << ">, signed <"
          << f.get_signed() << ">";
}
