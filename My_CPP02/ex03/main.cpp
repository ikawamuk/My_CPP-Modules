#include "Point.hpp"
#include "Fixed.hpp"
#include <fstream>
#include <limits>

void	output_bsp_test_scv(const Point& a, const Point& b, const Point& c, std::ofstream& ofs);

void	test1(void)
{
	const Point	a(1, 5);
	const Point	b(2, 10);
	const Point	c(11, -1);
	std::ofstream	ofs("test1.csv");
	output_bsp_test_scv(a, b, c, ofs);
}

void	test2(void)
{
	const Point	a(-5.01f, 10.44);
	const Point	b(0.01f, -9.22);
	const Point	c(8.4f, 3.101);
	std::ofstream	ofs("test2.csv");
	output_bsp_test_scv(a, b, c, ofs);
}

void	test3(void)
{
	const Point	a(10, 2);
	const Point	b(10, 20);
	const Point	c(16.9f, 20.0f);
	std::ofstream	ofs("test3.csv");
	output_bsp_test_scv(a, b, c, ofs);
}

void	test4(void)
{
	const Point	a(1, 5);
	const Point	b(1.0f, 10.0);
	const Point	c(1, -1);
	std::ofstream	ofs("test4.csv");
	output_bsp_test_scv(a, b, c, ofs);
}

void	test5(void)
{
	Fixed	FIXED_MAX, FIXED_MIN;

	FIXED_MAX.setRawBits(std::numeric_limits<int>::max() / (1 << 8));
	FIXED_MIN.setRawBits(std::numeric_limits<int>::min() / (1 << 8));

	const Point	a(2000, 1000);
	const Point	b(0, -1000);
	const Point	c(-1000, 1000);
	std::ofstream	ofs("test5.csv");
	output_bsp_test_scv(a, b, c, ofs);
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return (0);
}
