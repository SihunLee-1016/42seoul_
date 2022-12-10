#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>
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
        const std::string getname();
        int getgrade();
        void    grade_up();
        void    grade_down();
};
#endif