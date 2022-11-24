#include "phone_book.hpp"

void    phone_book::cnt_Add(void)
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


void    phone_book::cnt_Search(void)
{
	int s_idx;

	if (this->idx == 0)
	{
		std::cout << "Phone book empty" << std::endl;
		return ;
	}
	std::cout << "Which one u wanna search? : ";
	std::cin >> s_idx;
	if (s_idx == "exit")
	{
		std::cout << "EXIT" << std::endl;
		exit(0);
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


void	phone_book::print_all(void)
{
	int	i = 0;

	while (i < this->idx && i < 8)
	{
		this->contacts[i].data_print(i);
		std::cout << std::endl;
		i++;
	}
}

int main(void)
{
	std::string cmd;
	phone_book  data;

	while (!std::cin.eof())
	{
		std::cout << "Command (add, search, exit) : ";
		std::cin >> cmd;
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
		else
			std::cout << "cmd not found" << std::endl;
	}
	return (0);
}