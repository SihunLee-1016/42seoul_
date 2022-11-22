#include "Point.hpp"
//초기화 리스트
Point::Point(void) : x(0), y(0)
{
	//블럭 안에는 할당. 
}

Point::Point(Point &a) : x(a.get_x()),y(a.get_y())
{
}

Point::Point(float const x,float const y) : x(x), y(y)
{

}

Fixed Point::get_x(void) const
{
	return (x);
}

Fixed Point::get_y(void) const
{
	return (y);
}

Point::~Point()
{

}
