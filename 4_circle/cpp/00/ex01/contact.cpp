#include "contact.hpp"
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