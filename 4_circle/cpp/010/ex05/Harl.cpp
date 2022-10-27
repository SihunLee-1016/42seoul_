#include "./Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG level: Messages in this level contain extensive contextual information. They are mostly used for problem diagnosis. Example: I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"<< std::endl;
    std::cout << std::endl;
}
void Harl::info(void)
{
    std::cout << "INFO level: These messages contain some contextual information to help trace execution in a production environment. Example: I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    std::cout << std::endl;
}
void Harl::warning(void)
{
    std::cout <<"WARNING level: A warning message indicates a potential problem in the system. The system is able to handle the problem by itself or to proceed with this problem anyway. Example: I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
    std::cout << std::endl;
}
void Harl::error(void)
{
    std::cout << "ERROR level: An error message indicates a serious problem in the system. The problem is usually non-recoverable and requires manual intervention. Example: This is unacceptable, I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}
void Harl::complain( std::string level )
{
    std::string strs[4] = {"DEBUG","INFO","WARNING","ERROR"};
    int i = 0;
    void    (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    while (i < 4)
    {
        if (strs[i] == level)
            (this->*f[i])();
        i++;
    }
}