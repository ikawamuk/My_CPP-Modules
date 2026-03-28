/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:55:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 09:05:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

bool	is_operator(char c);
long	calcurate_op(std::stack<long>& stack, char op);
long	(*get_operation_func(char op))(long lhs, long rhs);
bool	safe_pop(std::stack<long>& stack, long& value);
bool	consume_digit(std::stack<long>& stack, std::string::const_iterator& it);
bool	consume_operator(std::stack<long>& stack, std::string::const_iterator& it);

long	rpn(const std::string& expr)
{
	std::stack<long>	stack;
	std::string::const_iterator it = expr.begin();
	if (!consume_digit(stack, it))
		throw std::invalid_argument("invalid token");
	while (it != expr.end())
	{
		if (*it++ != ' ')
			throw std::invalid_argument("expected space");
		if (consume_operator(stack, it));
		else if (consume_digit(stack, it));
		else
			throw std::invalid_argument("invalid token");
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Incomplete expression");
	return (stack.top());
}

long	calcurate_op(std::stack<long>& stack, char op)
{
	long	lhs, rhs;
	if (!safe_pop(stack, rhs) || !safe_pop(stack, lhs))
		throw std::invalid_argument("invalid argument");
	return (get_operation_func(op)(lhs, rhs));
}

bool	consume_operator(std::stack<long>& stack, std::string::const_iterator& it)
{
	if (is_operator(*it))
	{
		stack.push(calcurate_op(stack, *it++));
		return (true);
	}
	return (false);
}

bool	consume_digit(std::stack<long>& stack, std::string::const_iterator& it)
{
	if (std::isdigit(*it))
	{
		stack.push(*it++ - '0');
		return (true);
	}
	return (false);
}

long add(long a, long b)
{
	return (a + b);
}

long sub(long a, long b)
{
	return (a - b);
}

long mul(long a, long b)
{
	return (a * b);
}

long div(long a, long b)
{ 
	if (b == 0)
		throw std::runtime_error("division by zero");
	return a / b; 
}

long	(*get_operation_func(char op))(long lhs, long rhs)
{
	if (op == '+')
		return &add;
	if (op == '-')
		return &sub;
	if (op == '*')
		return &mul;
	if (op == '/')
		return &div;
	throw std::invalid_argument("invalid operator");
}

bool	is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	safe_pop(std::stack<long>& stack, long& value)
{
	if (stack.empty())
		return (false);
	value = stack.top();
	stack.pop();
	return (true);
}
