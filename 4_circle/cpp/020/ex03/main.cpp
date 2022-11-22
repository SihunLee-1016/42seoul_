#include "Fixed.hpp"
#include "Point.hpp"
std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int main(void)
{
    Point a(0,0);
    Point b(4,0);
    Point c(2,2);
    Point p1(1,1);
    Point p2(4,4);

    
}