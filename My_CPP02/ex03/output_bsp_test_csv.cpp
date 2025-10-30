#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	output_bsp_test_csv(const Point& a, const Point& b, const Point& c, std::ofstream& ofs)
{
	const Fixed	MIN_X = Fixed::min(a.get_x(), Fixed::min(b.get_x(), c.get_x()));
	const Fixed	MIN_Y = Fixed::min(a.get_y(), Fixed::min(b.get_y(), c.get_y()));
	const Fixed	MAX_X = Fixed::max(a.get_x(), Fixed::max(b.get_x(), c.get_x()));
	const Fixed	MAX_Y = Fixed::max(a.get_y(), Fixed::max(b.get_y(), c.get_y()));

	const int	N = 100;
	const int	buf = 5;
	Fixed dx = (MAX_X - MIN_X) / Fixed(N);
	Fixed dy = (MAX_Y - MIN_Y) / Fixed(N);
	const Fixed start_x = MIN_X - dx * Fixed(buf);
	const Fixed start_y = MIN_Y - dy * Fixed(buf);
	const Fixed end_x = MAX_X + dx * Fixed(buf);
	const Fixed end_y = MAX_Y + dy * Fixed(buf);

	if (dx == 0)
		dx.setRawBits(1);
	if (dy == 0)
		dy.setRawBits(1);
	ofs << "x,y,color" << std::endl;
	for (Fixed x = start_x; x <= end_x; x += dx)
	{
		for (Fixed y = start_y; y <= end_y; y += dy)
		{
			const Point p(x, y);
			ofs << p.get_x() << "," << p.get_y() << ",";
			if (bsp(a, b, c, p))
				ofs << "blue" << std::endl;
			else
				ofs << "red" << std::endl;
		}
	}
	return ;
}
