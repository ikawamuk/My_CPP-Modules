#ifndef HARL_HPP_
# define HARL_HPP_

#include <string>

class Harl
{
	public:
		Harl(void);
		void	complain(std::string level);
		void	filter(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef struct s_comment
		{
			std::string	label;
			void	(Harl::*member_func_p)(void);
		}	t_comment;

		static const std::size_t	TABLE_SIZE = 4;
		t_comment					comment_table_[TABLE_SIZE];
};

#endif