#include "NotSed.hpp"
#include <string>
#include <fstream>

NotSed::NotSed(std::ifstream& ifs, std::ofstream& ofs, const std::string& s1, const std::string& s2)
:ifs_(ifs)
,ofs_(ofs)
,s1_(s1)
,s2_(s2)
,pending_("")
{}

static bool			read_by_chunk(std::ifstream& ifs, std::string& chunk);
static std::size_t	get_pending_index(const std::string& s1, const std::string& base_cunk);
static void			safely_write(std::ofstream& ofs, std::string& output);

int	NotSed::write_replace_file(void)
{
	std::string	read_chunk;
	std::string	replaced;
	std::string	write_chunk;

	while (read_by_chunk(ifs_, read_chunk))
	{
		pending_ += read_chunk;
		if (pending_.length() < s1_.length())
			continue ;
		replaced = replace_chunk();
		write_chunk = trim_pending(replaced);
		safely_write(ofs_, write_chunk);
	}
	safely_write(ofs_, pending_);
	return (0);
}

static void	safely_write(std::ofstream& ofs, std::string& output)
{
	if (output.empty())
		return ;
	ofs.write(&output[0], output.size());
	if (ofs.fail())
		throw std::ios_base::failure("write failed");
	return ;
}

std::string	NotSed::trim_pending(std::string& base_chunk)
{
	std::size_t	pending_index = get_pending_index(s1_, base_chunk);

	pending_ = base_chunk.substr(pending_index);
	return (base_chunk.substr(0, pending_index));
}

static std::size_t	get_pending_index(const std::string& s1, const std::string& base_cunk)
{
	std::size_t	pending_len = s1.length() - 1;

	if (pending_len > base_cunk.length())
		return (0);
	return (base_cunk.length() - pending_len);
}

std::string	NotSed::replace_chunk(void)
{
	std::string	result("");
	std::size_t	find_pos;
	std::size_t	index(0);

	if (s1_ == s2_)
		return (pending_);
	while (1)
	{
		find_pos = pending_.find(s1_, index);
		if (find_pos == std::string::npos)
			break ;
		result.append(pending_, index, find_pos - index);
		result.append(s2_);
		index = find_pos + s1_.length();
	}
	result.append(pending_, index, pending_.length() - index);
	return (result);
}

static bool	read_by_chunk(std::ifstream& ifs, std::string& chunk)
{
	const std::size_t	BUF_SIZE = 1 << 10;
	char				buf[BUF_SIZE];
	std::size_t			read_size;

	ifs.read(buf, BUF_SIZE);
	read_size = ifs.gcount();
	if (ifs.bad())
		throw std::ios_base::failure("read failed");
	if (read_size == 0)
		return (false);
	chunk = std::string(buf, read_size);
	return (true);
}
