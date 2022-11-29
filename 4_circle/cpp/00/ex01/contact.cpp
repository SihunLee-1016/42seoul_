#include "Contact.hpp"
void    Contact::data_Add(void)
{
	std::string f;
	std::string l;
	std::string n;
	std::string p;
	std::string s;

	
	while (1)
	{
		std::cout << "First name : ";
		std::getline(std::cin, f);
		if (std::cin.eof())
			exit(0);
		if (f.empty())
			std::cout << "First name input empty" << std::endl;
		else
			break;
	}

	while (1)
	{
		std::cout << "Last name : ";
		std::getline(std::cin, l);
		if (std::cin.eof())
			exit(0);
		if (l.empty())
			std::cout << "Last name input empty" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Nick name : ";
		std::getline(std::cin, n);
		if (std::cin.eof())
			exit(0);
		if (n.empty())
			std::cout << "Nick name input empty" << std::endl;
		else
			break;
	}

	while (1)
	{
		std::cout << "Phone number : ";
		std::getline(std::cin, p);
		if (std::cin.eof())
			exit(0);
		if (p.empty())
			std::cout << "Phone number input empty" << std::endl;
		else
			break;
	}
	
	while (1)
	{
		std::cout << "Secret : ";
		std::getline(std::cin, s);
		if (std::cin.eof())
			exit(0);
		if (s.empty())
			std::cout << "Secret input empty" << std::endl;
		else
			break;
	}

	this->first = f;
	this->last = l;
	this->nickname = n;
	this->phone_num = p;
	this->secret = s;
}

void	Contact::data_print(int	i)
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
	while (k <= 9 && this->last[k])
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

void	Contact::data_specific_print(int	i)
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
	while (k <= 9 && this->last[k])
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
	
	k = 0;
	std::cout << " Phone number	|";
	std::cout << std::setw(10);
	while (k <= 9 && this->phone_num[k])
	{
		std::cout << this->phone_num[k];
		k++;
	}
	if (k == 10)
		std::cout << ".";
	std::cout << std::endl;

	k = 0;
	std::cout << " Secret		|";
	std::cout << std::setw(10);
	while (k <= 9 && this->secret[k])
	{
		std::cout << this->secret[k];
		k++;
	}
	if (k == 10)
		std::cout << ".";
	std::cout << std::endl;
}

void    Contact::data_Search(int idx)
{
	this->data_specific_print(idx);
}