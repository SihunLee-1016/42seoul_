#include "Phonebook.hpp"

void    Phonebook::cnt_Add(void)
{
	if (this->idx <= 7)
	{
		this->contacts[this->idx].data_Add();
		this->idx++;
	}
	else if (this->idx > 7)
	{
		this->contacts[this->idx % 8].data_Add();
		this->idx++;
	}
}


void    Phonebook::cnt_Search(void)
{
	int s_idx;
	std::string input;

	if (this->idx == 0)
	{
		std::cout << "Phone book empty" << std::endl;
		return ;
	}
	std::cout << "Which one u wanna search? : ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);

	if (input.compare("1") == 0)
		s_idx = 1;
	else if (input.compare("2") == 0)
		s_idx = 2;
	else if (input.compare("3") == 0)
		s_idx = 3;
	else if (input.compare("4") == 0)
		s_idx = 4;
	else if (input.compare("5") == 0)
		s_idx = 5;
	else if (input.compare("6") == 0)
		s_idx = 6;
	else if (input.compare("7") == 0)
		s_idx = 7;
	else if (input.compare("8") == 0)
		s_idx = 8;
	else
	{
		std::cout << "Wrong input" << std::endl;
		return ;
	}
	std::cout << std::endl;
	s_idx -= 1;
	if (s_idx > 7 || s_idx < 0)
	{
		std::cout << "Wrong index input" << std::endl;
		return ;
	}
	if (s_idx >= this->idx)
	{
		std::cout << "Wrong index input" << std::endl;
		return ;
	}
	this->contacts[s_idx].data_Search(s_idx);
}


void	Phonebook::print_all(void)
{
	int	i = 0;

	std::cout << std::right;
	std::cout << std::setw(11);
	std::cout << "INDEX |";
	std::cout << std::setw(11);
	std::cout << "F_name |";
	std::cout << std::setw(11);
	std::cout << "L_name |";
	std::cout << std::setw(11);
	std::cout << "N_name |" << std::endl;
	std::cout << "--------------------------------------------"<<std::endl;
	while (i < this->idx && i < 8)
	{

		this->contacts[i].data_print(i);
		std::cout << std::endl;
		std::cout << "--------------------------------------------"<<std::endl;
		i++;
	}
}

int main(void)
{
	std::string cmd;
	Phonebook  data;

	while (!std::cin.eof())
	// while (1)
	{
		// if (std::cin.eof())
		// 	exit(0);
		std::cout << "Command (add, search, exit) : ";
		std::getline(std::cin, cmd);
		if (cmd == "add")
			data.cnt_Add();
		else if (cmd == "search")
		{
			data.print_all();
			data.cnt_Search();
		}
		else if (cmd == "exit")
		{
			exit(0);
		}            
	}
	return (0);
}