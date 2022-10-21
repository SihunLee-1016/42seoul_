#include <iostream>
#include <iomanip>
#include <string.h>
class contact
{
	private:
		std::string idx;
		std::string first;
		std::string last;
		std::string nickname;
		std::string phone_num;
		std::string secret;
	public :
		void    data_Add(void);
		void    data_Search(int	idx);
		void	data_print(int i);
};

class phone_book
{
	private :
		contact contacts[8];
		int     idx;
	public :
		phone_book(void) {
			this->idx = 0;
		}
		void    cnt_Add(void);
		void    cnt_Search(void);
		void	print_all(void);
};

void    phone_book::cnt_Add(void)
{
	if (this->idx <= 7)
	{
		this->contacts[this->idx % 8].data_Add();
		this->idx++;
	}
	else if (this->idx > 7)
	{
		this->contacts [7].data_Add();
		this->idx++;
	}
}

void    contact::data_Add(void)
{
	std::cout << "First name : ";
	std::cin >> this->first;

	std::cout << "Last name : ";
	std::cin >> this->last;
	
	std::cout << "Nick name : ";
	std::cin >> this->nickname;
	
	std::cout << "Phone number : ";
	std::cin >> this->phone_num;

	std::cout << "Secret : ";
	std::cin >> this->secret;
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

void	contact::data_print(int	i)
{
	int k = 0;

	std::cout << std::right;
	std::cout << "     Index	|";
	std::cout << std::setw(10) << i + 1 << std::endl;
	std::cout << "First name	|";
	std::cout << std::setw(10);
	
	while (k <= 9 && this->first[k])
	{
		std::cout << this->first[k];
		k++;
	}
	if (k == 10)
		std::cout << ".";
	std::cout << std::endl;
	k = 0;
	std::cout << " Last name	|";
	std::cout << std::setw(10);
	while (i <= 9 && this->last[k])
	{
		std::cout << this->last[k];
		k++;
	}
	if (k == 10)
		std::cout << ".";
	std::cout << std::endl;
	k = 0;
	std::cout << " Nick name	|";
	std::cout << std::setw(10);
	while (k <= 9 && this->nickname[k])
	{
		std::cout << this->nickname[k];
		k++;
	}
	if (k == 10)
		std::cout << ".";
	std::cout << std::endl;
}

void    contact::data_Search(int idx)
{
	this->data_print(idx);
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
	int     idx = 0;
	int     i = 0;

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