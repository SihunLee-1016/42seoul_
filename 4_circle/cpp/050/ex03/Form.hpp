#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	const std::string _type;
	const std::string _name;
	const std::string target;
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
	
	class DoesNotSignedException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  class FileNotWorkingException : public std::exception {
   public:
      const char* what(void) const throw();
  };

	class NotSignedException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

	Form(void);
	Form(const std::string str1, const int sg, const int eg);
	Form(const Form &obj);
	Form& operator=(const Form &obj);
	void	besigned(const Bureaucrat &obj);
	std::string getname() const;
	std::string gettype() const;
	int	get_sign_g() const;
	int	get_exe_g() const;
	int get_signed() const;
	std::string get_target() const;

	void	set_type(const std::string str);
	void	set_target(const std::string target);
	void	set_name(const std::string str);
	
	void	set_sg(const int num);
	void	set_eg(const int num);
	void	set_signed(bool num);

	virtual void execute(Bureaucrat const &b) const = 0;
	virtual ~Form();

};
std::ostream& operator<<(std::ostream& o, const Form& f);
#endif