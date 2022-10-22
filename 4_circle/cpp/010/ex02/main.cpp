#include <iostream>
#include <iomanip>
#include <string>
int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string& stringREF = str;
	std::string	*stringPTR = &str;

	std::cout << "text address : " << &str << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;
	std::cout << "stringPTR address : " << &stringPTR << std::endl << std::endl;

	std::cout << "using stringPTR : " << *stringPTR << std::endl;
	std::cout << "using stringREF : " << stringREF << std::endl;

	return (0);

}