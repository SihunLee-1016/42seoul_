#include <iostream>
#include <string>
class Fixed
{
	private:
		int					fixed;
		static const int	fract = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &a);
		~Fixed();
		Fixed& operator = (const Fixed &a);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
