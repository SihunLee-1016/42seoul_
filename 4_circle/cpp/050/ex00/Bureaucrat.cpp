#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &str, int grade) : name(str)
{
	try
	{
		if (!(grade >= 1 && grade <= 150))
			throw grade;
		this->grade = grade;
	}
	catch(int expn)
	{
		if (expn < 1)
			grade2high();
		else if (expn > 150)
			grade2low();
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor activated" << std::endl;
}

void    Bureaucrat::grade2high()
{
	std::cout << "Grade Too High" << std::endl;   
}

void    Bureaucrat::grade2low()
{
	std::cout << "Grade Too Low" << std::endl;   
}

const std::string Bureaucrat::getname()
{
	return (this->name);
}

int Bureaucrat::getgrade()
{
	return (this->grade);
}

void Bureaucrat::grade_up()
{
	if (this->grade == 1)
		std::cout << "Grade up Faile (its already highest" << std::endl;
	else
		this->grade -= 1;
}

void Bureaucrat::grade_down()
{
	if (this->grade == 150)
		std::cout << "Grade up Faile (its already lowest" << std::endl;
	else
		this->grade += 1;		
}