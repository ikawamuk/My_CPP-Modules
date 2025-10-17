#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>

void	PhoneBook::add(void)
{
	for (int i = MAX_STORE_SIZE - 1; i > 0; i--)
		contact_arr_[i] = contact_arr_[i - 1];
	contact_arr_[0] = PhoneBook::add_new_contact();
	return ;
}

Contact	PhoneBook::add_new_contact(void)
{
	Contact	new_contact;

	PhoneBook::ask_first_name(new_contact);
	PhoneBook::ask_last_name(new_contact);
	PhoneBook::ask_nickname(new_contact);
	PhoneBook::ask_phone_number(new_contact);
	PhoneBook::ask_darkest_secret(new_contact);
	return (new_contact);
}

void	PhoneBook::ask_first_name(Contact &new_contact)
{
	std::string	first;
	while (1)
	{
		read_input("first name: ", first);
		if (!first.empty())
			break ;
	}
	new_contact.set_first_name(first);
	return ;
}

void	PhoneBook::ask_last_name(Contact &new_contact)
{
	std::string	last;
	while (1)
	{
		read_input("last name: ", last);
		if (!last.empty())
			break ;
	}
	new_contact.set_last_name(last);
	return ;
}

void	PhoneBook::ask_nickname(Contact &new_contact)
{
	std::string	nick;
	while (1)
	{
		read_input("nickname: ", nick);
		if (!nick.empty())
			break ;
	}
	new_contact.set_nickname(nick);
	return ;
}

void	PhoneBook::ask_phone_number(Contact &new_contact)
{
	std::string	phone;
	while (1)
	{
		read_input("phone number: ", phone);
		if (!phone.empty())
			break ;
	}
	new_contact.set_phone_number(phone);
	return ;
}

void	PhoneBook::ask_darkest_secret(Contact &new_contact)
{
	std::string	secret;
	while (1)
	{
		read_input("darkest secret: ", secret);
		if (!secret.empty())
			break ;
	}
	new_contact.set_darkest_secret(secret);
	return ;
}
