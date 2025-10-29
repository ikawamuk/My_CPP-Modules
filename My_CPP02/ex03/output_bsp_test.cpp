#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	output_bsp_test(const Point& a, const Point& b, const Point& c, std::ofstream& ofs)
{
	Fixed	MIN_X = Fixed::min(a.get_x(), Fixed::min(b.get_x(), c.get_x()));
	Fixed	MIN_Y = Fixed::min(a.get_y(), Fixed::min(b.get_y(), c.get_y()));
	Fixed	MAX_X = Fixed::max(a.get_x(), Fixed::max(b.get_x(), c.get_x()));
	Fixed	MAX_Y = Fixed::max(a.get_y(), Fixed::max(b.get_y(), c.get_y()));

	const int	N = 100;
	const int	buf = 5;
	const Fixed dx = (MAX_X - MIN_X) / Fixed(N);
	const Fixed dy = (MAX_Y - MIN_Y) / Fixed(N);
	const Fixed start_x = MIN_X - dx * Fixed(buf);
	const Fixed start_y = MIN_Y - dy * Fixed(buf);
	const int	steps = N + 2 * buf;  

	ofs << "x,y,color" << std::endl;
	for (int ix = 0; ix <= steps; ++ix)
	{
		const Fixed x = start_x + dx * Fixed(ix);
		for (int iy = 0; iy <= steps; ++iy)
		{
			const Fixed y = start_y + dy * Fixed(iy);
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
