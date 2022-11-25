#include "Fixed.hpp"
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(int num)
{
		std::cout << "Int constructor called" << std::endl;
		this->fixed = num << this->fract;
}

Fixed::Fixed(float num)
{
		std::cout << "Float constructor called" << std::endl;
		this->fixed = roundf(num * (1 << this->fract));
}


Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = a.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed = a.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::	getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
	return (this->fixed >> this->fract);
}