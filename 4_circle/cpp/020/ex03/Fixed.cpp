#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed &a)
{
    this->fixed = a.getRawBits();
    return (*this);
}

bool Fixed::operator < (const Fixed &a)
{
	return (this->getRawBits() < a.getRawBits());
}

bool Fixed::operator > (const Fixed &a)
{
	return (this->getRawBits() > a.getRawBits());
}
bool Fixed::operator >= (const Fixed &a)
{
	return (this->getRawBits() >= a.getRawBits());
}
bool Fixed::operator <= (const Fixed &a)
{
	return (this->getRawBits() <= a.getRawBits());
}
bool Fixed::operator == (const Fixed &a)
{
	return (this->getRawBits() == a.getRawBits());
}
bool Fixed::operator != (const Fixed &a)
{
	return (this->getRawBits() != a.getRawBits());
}

Fixed Fixed::operator + (const Fixed &a)
{
	Fixed ret(this->toFloat() + a.toFloat());
	return (ret);
}

Fixed Fixed::operator - (const Fixed &a)
{
	Fixed ret(this->toFloat() - a.toFloat());
	return (ret);
}

Fixed Fixed::operator * (const Fixed &a)
{
	Fixed ret(this->toFloat() * a.toFloat());
	return (ret);
}

Fixed Fixed::operator / (const Fixed &a)
{
	Fixed ret(this->toFloat() / a.toFloat());
	return (ret);
}

Fixed& Fixed::operator++ (void)
{
	this->fixed++;
	return (*this);
}

Fixed& Fixed::operator-- (void)
{
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator++ (int i)
{
	Fixed tmp(*this);

	(void) i;
	this->fixed++;
	return (tmp);
}

Fixed Fixed::operator-- (int i)
{
	Fixed tmp(*this);

	(void) i;
	this->fixed--;
	return (tmp);
}

Fixed& Fixed::getmin(Fixed &a, Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed& Fixed::getmin(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed& Fixed::getmax(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);

}

const Fixed& Fixed::getmax(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}



Fixed::Fixed(void)
{
	this->fixed = 0;
}



Fixed::Fixed(int num)
{
		this->fixed = num << this->fract;
}

Fixed::Fixed(float num)
{
		this->fixed = roundf(num * (1 << this->fract));
}

Fixed::Fixed(const Fixed &a)
{
	this->fixed = a.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::	getRawBits(void) const
{
	return (this->fixed);
}

void	Fixed:: setRawBits(int const raw)
{
	this->fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed / (1 << this->fract));
}

int		Fixed::toInt(void) const
{
	return (this->fixed >> this ->fract);
}