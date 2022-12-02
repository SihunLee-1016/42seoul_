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

	if (f.length() >= 10)
	{
		f.resize(9);
		f.append(".");
	}
	if (l.length() >= 10)
	{
		l.resize(9);
		l.append(".");
	}
	if (n.length() >= 10)
	{
		n.resize(9);
		n.append(".");
	}
	if (p.length() >= 10)
	{
		p.resize(9);
		p.append(".");
	}
	if (s.length() >= 10)
	{
		s.resize(9);
		s.append(".");
	}

	this->first = f;
	this->last = l;
	this->nickname = n;
	this->phone_num = p;
	this->secret = s;
}

void	Contact::data_print(int	i)
{
	std::cout << std::right;
	std::cout << std::setw(10) << i + 1;
	std::cout << "|";
	std::cout << std::setw(10) << this->first;
	std::cout << "|";
	std::cout << std::setw(10) << this->last;
	std::cout << "|";
	std::cout << std::setw(10) << this->nickname;
	std::cout << "|";
}

void	Contact::data_specific_print(int	i)
{
	std::cout << std::right;
	std::cout << std::setw(10) << i + 1;
	std::cout << "|";
	std::cout << std::setw(10) << this->first;
	std::cout << "|";
	std::cout << std::setw(10) << this->last;
	std::cout << "|";
	std::cout << std::setw(10) << this->nickname;
	std::cout << "|";
	std::cout << std::setw(10) << this->phone_num;
	std::cout << "|";
	std::cout << std::setw(10) << this->secret;
	std::cout << "|" << std::endl;

}

void    Contact::data_Search(int idx)
{
	std::cout << std::right;
	std::cout << std::setw(11);
	std::cout << "INDEX  |";
	std::cout << std::setw(11);
	std::cout << "F_name  |";
	std::cout << std::setw(11);
	std::cout << "L_name  |";
	std::cout << std::setw(11);
	std::cout << "N_name  |";
	std::cout << std::setw(11);
	std::cout << "Phone_n |";
	std::cout << std::setw(11);
	std::cout << "Secret |" << std::endl;
	std::cout << "------------------------------------------------------------------"<<std::endl;

	this->data_specific_print(idx);
}