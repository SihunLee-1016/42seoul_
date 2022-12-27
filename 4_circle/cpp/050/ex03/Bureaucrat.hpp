#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"
class Form;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
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
        Bureaucrat();
        Bureaucrat(const std::string &str, int grade);
        ~Bureaucrat();
        const std::string getname();
        int getgrade() const;
        void    grade_up();
        void    grade_down();
        void    signForm(const Form &f) const;
        void    executeForm(Form const & f);

};
#endif