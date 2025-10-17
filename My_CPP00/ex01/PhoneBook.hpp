#ifndef PHONE_BOOK_HPP_
# define PHONE_BOOK_HPP_

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		static const int	MAX_STORE_SIZE = 8;
		Contact				contact_arr_[MAX_STORE_SIZE];

	public:
		PhoneBook(void);
		void	run(void);

	private:
		void			add(void);
		void			search(void) const;
		void			show_detail(void) const;
		int				get_index(std::string str) const;
		void			display_contact_info(int index) const;
		static void		read_input(const std::string& prompt, std::string& str);
		static Contact	add_new_contact(void);
		static void		ask_first_name(Contact& new_contact);
		static void		ask_last_name(Contact& new_contact);
		static void		ask_nickname(Contact& new_contact);
		static void		ask_phone_number(Contact& new_contact);
		static void		ask_darkest_secret(Contact& new_contact);
		static void		print_table_hedder(void);
		static void		print_contact(const Contact& contact, int i);
		static void		put_content(const std::string& content);
};

#endif