#include "Vec2d.hpp"
#include "Point.hpp"
#include "Fixed.hpp"

static bool	is_positive(const Fixed& value);
static bool	is_negative(const Fixed& value);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const Vec2d	ab(a, b), bc(b, c), ca(c, a);
	const Vec2d	ap(a, point), bp(b, point), cp(c, point);
	const Fixed ab_cross_ap(ab.cross_scalar(ap)), bc_cross_bp(bc.cross_scalar(bp)), ca_cross_cp(ca.cross_scalar(cp));

	if (is_positive(ab_cross_ap) && is_positive(bc_cross_bp) && is_positive(ca_cross_cp))
		return (true);
	if (is_negative(ab_cross_ap) && is_negative(bc_cross_bp) && is_negative(ca_cross_cp))
		return (true);
	return (false);
}

static bool	is_positive(const Fixed& value)
{
	return (value > Fixed(0));
}

static bool	is_negative(const Fixed& value)
{
	return (value < Fixed(0));
}
