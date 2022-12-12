#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <exception>
#include <string>
class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool	sign;
	const int sign_g;
	const int exe_g;

public :
	class Grade2HighException : public std::exception
	{
		public :
			const char* what(void) const throw();
	};

	class Grade2LowException : public std::exception
	{
		public :
			const char* what(void) const throw();
	};
	Form(const std::string str, const int sign, const int exe);
	Form(const Form &obj);
	Form& operator=(const Form &obj);
	~Form();
	void	besigned(const Bureaucrat &obj);
	std::string getname() const;
	int	get_sign_g() const;
	int	get_exe_g() const;
	int get_signed() const;
};
std::ostream& operator<<(std::ostream& o, const Form& f);
#endif