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
	: _name(obj.getname()), sign(obj.get_signed()),
		sign_g(obj.get_sign_g()), exe_g(obj.get_exe_g())
{
	try{
		if (sign_g > 150 || exe_g > 150)
			throw Grade2LowException();
		else if (sign_g < 1 || exe_g <1)
			throw Grade2HighException();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

//const_cast can used in 3 cases.
// 1. @@ Pointer that declared in const @@
// 2. if its not const pointer, const_cast cannot used.

// in operator=, Form's member variable are declared in const.
// in this case, 'this' pointer is non-const value so this pointer cannot call const function.
// so to use const function, we have to const_cast to pointer type (see first condition)
Form& Form::operator=(const Form &obj)
{
	// _name = obj.getname();
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
	try {
	if (obj.getgrade() <= this->sign_g)
		this->sign = true;
	else
		throw Grade2LowException();
		}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
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
