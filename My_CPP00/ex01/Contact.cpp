#include "Contact.hpp"
#include <iostream>
#include <string>

static const std::string EMPTY = "EMPTY";

Contact::Contact(void)
:first_name_(EMPTY)
,last_name_(EMPTY)
,nickname_(EMPTY)
,phone_number_(EMPTY)
,darkest_secret_(EMPTY)
{}

// setter
void	Contact::set_first_name(std::string arg)
{
	first_name_ = arg;
	return ;
}

void	Contact::set_last_name(std::string arg)
{
	last_name_ = arg;
	return ;
}

void	Contact::set_nickname(std::string arg)
{
	nickname_ = arg;
	return ;
}

void	Contact::set_phone_number(std::string arg)
{
	phone_number_ = arg;
	return ;
}

void	Contact::set_darkest_secret(std::string arg)
{
	darkest_secret_ = arg;
	return ;
}

// getter
std::string	Contact::first_name(void) const
{
	return (first_name_);
}

std::string	Contact::last_name(void) const
{
	return (last_name_);
}

std::string	Contact::nickname(void) const
{
	return (nickname_);
}

std::string	Contact::phone_number(void) const
{
	return (phone_number_);
}

std::string	Contact::darkest_secret(void) const
{
	return (darkest_secret_);
}
