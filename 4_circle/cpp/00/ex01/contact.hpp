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
