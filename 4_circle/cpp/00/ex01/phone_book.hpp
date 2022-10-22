#include <iostream>
#include <iomanip>
#include <string.h>
#include "contact.hpp"
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