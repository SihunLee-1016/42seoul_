#include <iostream>
#include <string>
class Fixed
{
	private:
		int					fixed;
		static const int	fract = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &a);
		~Fixed();
		Fixed& operator = (const Fixed &a);
		bool operator < (const Fixed &a);
		bool operator > (const Fixed &a);
		bool operator >= (const Fixed &a);
		bool operator <= (const Fixed &a);
		bool operator == (const Fixed &a);
		bool operator != (const Fixed &a);
		
		Fixed& operator += (const Fixed &a);
		Fixed& operator -= (const Fixed &a);
		Fixed& operator *= (const Fixed &a);
		Fixed& operator /= (const Fixed &a);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
