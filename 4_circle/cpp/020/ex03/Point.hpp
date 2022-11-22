#include "Fixed.hpp"
class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		Point(Point &a);
		Point(float const x, float const y);
		~Point();
		Fixed Point::get_x(void) const;
		Fixed Point::get_y(void) const;

};
