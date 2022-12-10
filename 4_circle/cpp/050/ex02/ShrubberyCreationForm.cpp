#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, 145, 137)
{
  this->set_type("Shrubberry");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s)
{
  this->set_type("Shrubberry");
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
  executable(b);
  std::ofstream out("<" + getName() + ">_shrubbery",
                    std::ofstream::out | std::ofstream::trunc);
  if (!out.good())
    throw FileNotWorkingException();
  std::string shrubbery = "               ,@@@@@@@,\n"
                          "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                          "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                          "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                          "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                          "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                          "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                          "       |o|        | |         | |\n"
                          "       |.|        | |         | |\n"
                          "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
  out << shrubbery;
  out.close();
}


ShrubberyCreationForm& 
  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
  this->type = s.gettype();
  this->_name = s.getname();
  this->sign_g = s.get_sign_g();
  this->exe_g = s.get_exe_g();
  this->sign = s.get_signed();
  return *this;
}