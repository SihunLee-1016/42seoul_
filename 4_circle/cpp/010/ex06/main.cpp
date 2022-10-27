#include "./Harl.hpp"
int main(int ac, char **av)
{
    Harl harl;
    std::string str;


    if (ac != 2)
        return (1);
    str = av[1];

    harl.complain(str);
    return(0);
}