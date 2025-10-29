#ifndef NOT_SED_HPP_
# define NOT_SED_HPP_

#include <string>
#include <fstream>

class NotSed
{
	public:
		NotSed(std::ifstream& ifs, std::ofstream& ofs, const std::string& s1, const std::string& s2);
		int	write_replace_file(void);
	
	private:
		NotSed(void);
		bool				read_file_by_chunk(void);
		std::string			replace_chunk(void);
		std::string			trim_pending(std::string& base_chunk);

		std::ifstream&		ifs_;
		std::ofstream&		ofs_;
		const std::string&	s1_;
		const std::string&	s2_;
		std::string			pending_;
};

#endif