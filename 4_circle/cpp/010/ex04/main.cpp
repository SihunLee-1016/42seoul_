#include <iostream>
#include <fstream>
#include <string>
//c++에서 파일 입출력을 통해서 한번 조작해봐라 -> fstream 쓰면 됨
int main (int ac, char **av)
{
	if (ac != 4)
		return (0);
	std::ofstream   write;
	std::ifstream   read;
	std::string		new_name;
	
	new_name = av[1];
	new_name.append(".replace");

	read.open(av[1]);
	write.open(new_name);

	if (read.fail() || write.fail())
	{
		std::cout << "ERROR";
		exit(1);
	}


}