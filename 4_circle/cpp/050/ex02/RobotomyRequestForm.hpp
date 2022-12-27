#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
  private:
  public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    void execute(const Bureaucrat& b) const;
    RobotomyRequestForm& operator=(const RobotomyRequestForm& s);
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& s);

};


#endif