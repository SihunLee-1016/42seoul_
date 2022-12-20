#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
int main (int ac, char **av)
{
	if (ac == 1)
		return (0);
	double	d = std::strtod(av[1], nullptr);


	if ( 31 < d && d < 127)
		std::cout << "char : " << static_cast<char>(d) << std::endl;
	else if (strcmp(av[1], "nan") == 0)
		std:: cout << "char : impossible" << std::endl;
	else
		std:: cout << "char : Non displayable" << std::endl;

	if (INT_MIN <= d && d <= INT_MAX)
		std::cout << "int : " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	
	std::cout << std::fixed;
	std::cout.precision(1);

	if (__FLT_MIN__ <= d && d <= __FLT_MAX__)
		std::cout << "float : " << static_cast<float>(d) << "f"<< std::endl;
	else if (strcmp(av[1], "nan") == 0)
		std:: cout << "float : nanf" << std::endl;
	else
		std::cout << "float : impossible" << std::endl;

	if (__DBL_MIN__ <= d && d <= __DBL_MAX__ )
		std::cout << "double : " << d << std::endl;
	else if (strcmp(av[1], "nan") == 0)
		std:: cout << "double : nan" << std::endl;
	else
		std::cout << "double : impossible "<< std::endl;
}