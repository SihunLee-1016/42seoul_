#include <iostream>
#include <iomanip>
#include <string.h>
#include "Contact.hpp"
class Phonebook
{
	private :
		Contact contacts[8];
		int     idx;
	public :
		Phonebook(void) {
			this->idx = 0;
		}
		void    cnt_Add(void);
		void    cnt_Search(void);
		void	print_all(void);
};