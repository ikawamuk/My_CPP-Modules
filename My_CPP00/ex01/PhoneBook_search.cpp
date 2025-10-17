#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

static const int			INDEX_COLUMN_WIDTH = 6;
static const int			COLUMN_WIDTH = 10;
static const std::string	SEPARATOR_LINE(41, '-');

void	PhoneBook::search(void) const
{
	print_table_hedder();
	for (int i = 0; i < MAX_STORE_SIZE; i++)
		print_contact(contact_arr_[i], i + 1);
	std::cout << SEPARATOR_LINE << std::endl;
	show_detail();
	return ;
}

void	PhoneBook::show_detail(void) const
{
	std::string	input;
	int			index;

	while (1)
	{
		read_input("Enter the index of the contact to display: ", input);
		index = get_index(input);
		if (index != -1)
			break ;
		std::cout << "Enter a valid index from 1 to " << MAX_STORE_SIZE << std::endl;
	}
	display_contact_info(index);
	return ;
}

int	PhoneBook::get_index(std::string str) const
{
	int	index;
	std::stringstream	ss(str);

	if (!(ss >> index))
		return (-1);
	if (index < 1 || MAX_STORE_SIZE < index)
		return (-1);
	return (index);
}

void	PhoneBook::display_contact_info(int index_based_one) const
{
	const int	LABELS_WIDTH = 16;
	int			i = index_based_one - 1;

	std::cout << std::left;
	std::cout << std::setw(LABELS_WIDTH) << "index: " << index_based_one << std::endl;
	std::cout << std::setw(LABELS_WIDTH) << "first name: " << contact_arr_[i].first_name() << std::endl;
	std::cout << std::setw(LABELS_WIDTH) << "last name: " << contact_arr_[i].last_name() << std::endl;
	std::cout << std::setw(LABELS_WIDTH) << "nickname: " << contact_arr_[i].nickname() << std::endl;
	std::cout << std::setw(LABELS_WIDTH) << "phone number: " << contact_arr_[i].phone_number() << std::endl;
	std::cout << std::setw(LABELS_WIDTH) << "darkest secret: " << contact_arr_[i].darkest_secret() << std::endl;
}

void	PhoneBook::print_table_hedder(void)
{
	std::cout << SEPARATOR_LINE << std::endl;
	std::cout << "|" << std::setw(INDEX_COLUMN_WIDTH) << "index";
	std::cout << "|" << std::setw(COLUMN_WIDTH) << "first name";
	std::cout << "|" << std::setw(COLUMN_WIDTH) << "last name";
	std::cout << "|" << std::setw(COLUMN_WIDTH) << "nickname";
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_contact(const Contact& contact, int i)
{
	std::cout << SEPARATOR_LINE << std::endl;
	std::cout << "|" << std::setw(INDEX_COLUMN_WIDTH) << i;
	put_content(contact.first_name());
	put_content(contact.last_name());
	put_content(contact.nickname());
	std::cout << "|" << std::endl;
}

void	PhoneBook::put_content(const std::string& content)
{
	std::cout << "|";
	if (content.length() > COLUMN_WIDTH)
	{
		for (int i = 0; i < COLUMN_WIDTH - 1; i++)
			std::cout << content[i];
		std::cout << ".";
		return ;
	}
	std::cout << std::setw(COLUMN_WIDTH) << content;
	return ;
}
