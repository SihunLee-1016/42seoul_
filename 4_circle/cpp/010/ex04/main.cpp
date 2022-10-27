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
	std::string		outfile;
	std::string		contents;
	std::string		str1;
	std::string		str2;
	int				str1_len = 0;
	int				str2_len = 0;
	size_t			position = 0;

	read.open(av[1]);
	str1 = av[2];
	str2 = av[3];
	str1_len = str1.length();
	str2_len = str2.length();

	if (read.fail())
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	outfile = av[1];
	outfile.append(".replace");
	write.open(outfile);
	if (write.fail())
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	while (1)
	{
		std::getline(read, contents);
		position = 0;
		while(1)
		{
			position = contents.find(str1, position);
			if (position == std::string::npos)
			{
				break;
			}
			contents.erase(position, str1_len);
			contents.insert(position, str2);
			position += str2_len;
		}
		write << contents;
		if (read.eof())
			break;
		write << std::endl;
	}
	return (0);
}