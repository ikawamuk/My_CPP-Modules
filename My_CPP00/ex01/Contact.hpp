#ifndef CONTACT_HPP_
# define CONTACT_HPP_

#include <string>

class Contact
{
	private:
		std::string	first_name_;
		std::string	last_name_;
		std::string	nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;

	public:
		Contact(void);
		void		set_first_name(std::string arg);
		void		set_last_name(std::string arg);
		void		set_nickname(std::string arg);
		void		set_phone_number(std::string arg);
		void		set_darkest_secret(std::string arg);
		std::string	first_name(void) const;
		std::string	last_name(void) const;
		std::string	nickname(void) const;
		std::string	phone_number(void) const;
		std::string	darkest_secret(void) const;
};

#endif