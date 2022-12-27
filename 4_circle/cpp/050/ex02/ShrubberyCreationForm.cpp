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

// good -> stream has not encountered an error
void ShrubberyCreationForm::execute(Bureaucrat const & b) const {

  try {
    if (b.getgrade() > 137)
      throw Form::Grade2LowException();
    if(this->get_signed() != 1)
      throw Form::NotSignedException();

    std::ofstream out("<" + getname() + ">_shrubbery",
                      std::ofstream::out | std::ofstream::trunc);
    if (!out.good())
      throw Form::FileNotWorkingException();

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
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

}


ShrubberyCreationForm& 
  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
  this->set_type(s.gettype());
  this->set_name(s.getname());
  this->set_sg(s.get_sign_g());
  this->set_eg(s.get_exe_g());
  this->set_signed(s.get_signed());
  return *this;
}