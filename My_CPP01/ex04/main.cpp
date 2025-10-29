#include "NotSed.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

static int	validate(int argc, char *argv[]);
static int	create_replace_file(char *argv[]);
static int	try_to_write_replace_file(std::ifstream& ifs,std::ofstream& ofs, const std::string& s1, const std::string& s2);

int	main(int argc, char *argv[])
{
	if (validate(argc, argv) == 1)
		return (EXIT_FAILURE);
	if (create_replace_file(argv) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	create_replace_file(char *argv[])
{
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	std::ifstream		ifs;
	std::ofstream		ofs;

	ifs.open(argv[1]);
	if (ifs.fail())
	{	
		std::cerr << "failed to open the file" << std::endl;
		return (1);
	}
	ofs.open((std::string(argv[1]) + ".replace").c_str());
	if (ofs.fail())
	{	
		std::cerr << "failed to open the file" << std::endl;
		return (1);
	}
	return (try_to_write_replace_file(ifs, ofs, s1, s2));
}

static int	try_to_write_replace_file(std::ifstream& ifs,std::ofstream& ofs, const std::string& s1, const std::string& s2)
{
	NotSed	not_sed(ifs, ofs, s1, s2);

	try
	{
		not_sed.write_replace_file();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

static int	validate(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << argv[0] << " <file name> <string1> <string2>" << std::endl;
		return (1);
	}
	if (!*argv[1] || !*argv[2])
	{
		std::cerr << "Invalid arguments" << std::endl;
		return (1);
	}
	return (0);
}
