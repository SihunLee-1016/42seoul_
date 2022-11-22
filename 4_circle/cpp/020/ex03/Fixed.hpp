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
		
		Fixed operator + (const Fixed &a);
		Fixed operator - (const Fixed &a);
		Fixed operator * (const Fixed &a);
		Fixed operator / (const Fixed &a);
		
		Fixed& operator++ (void);
		Fixed& operator-- (void);
		Fixed operator++ (int i);
		Fixed operator-- (int i);

		Fixed& getmin(Fixed &a, Fixed &b);
		const Fixed& getmin(Fixed const &a, Fixed const &b);
		Fixed& getmax(Fixed &a, Fixed &b);
		const Fixed& getmax(Fixed const &a, Fixed const &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
