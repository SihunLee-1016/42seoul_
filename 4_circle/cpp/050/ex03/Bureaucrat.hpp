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
        Bureaucrat();
        Bureaucrat(const std::string &str, int grade);
        ~Bureaucrat();
        void    grade2high();
        void    grade2low();
        const std::string getname() const;
        int getgrade() const;
        void    grade_up();
        void    grade_down();
        void	signForm(const Form &f) const;
        void    executeForm(Form const & form);
};
#endif