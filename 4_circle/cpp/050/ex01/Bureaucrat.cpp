#include "Bureaucrat.hpp"

const char* Bureaucrat::Grade2HighException::what(void) const throw()
{
	return "Grade Too High";
}

const char* Bureaucrat::Grade2LowException::what(void) const throw()
{
	return "Grade Too Low";
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &str, int grade) : name(str)
{
	try
	{
		if (grade < 1)
			throw Grade2HighException();
		else if (grade > 150)
			throw Grade2LowException();
		this->grade = grade;
		std::cout << "Bureaucrat constructor activated. grade : " << grade << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor activated" << std::endl;
}

const std::string Bureaucrat::getname()
{
	return (this->name);
}

int Bureaucrat::getgrade() const
{
	return (this->grade);
}

void Bureaucrat::grade_up()
{
	try
	{
		if (this->grade == 1)
			throw Grade2HighException();
		this->grade -= 1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::grade_down()
{
	try
	{
		if (this->grade == 150)
			throw Grade2LowException();
		this->grade += 1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(const Form &f) const
{
	try
	{
    (*const_cast<Form*>(&f)).besigned(*this);
		std::cout << "<" << this->name << "> signs <"
			<< f.getname() << ">" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "<" << this->name << "> cannot sign <"
			<< f.getname() << "> becasue <" << e.what() << " >" << std::endl;
	}
}
