#include <iostream>
#include <string>
#include <cstdlib>
int main (int ac, char **av)
// int main()
{
    double  tmp;

    (void)ac;
    tmp = atof(av[1]);

    std::cout << "double : "<< tmp << std::endl;
    std::cout << "float : " << static_cast<float>(tmp) << "f"<< std::endl;
    std::cout << "char : " << static_cast<char*>(av[1]) << std::endl;
    // ss.append(" and its changed into string");
    // std::cout << ss << std::endl;


}