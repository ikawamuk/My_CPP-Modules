#include <iostream>
#include <cctype>
#include <string>

static void	string_toupper(std::string& text);

void	megaphone(int arr_size, char *message_arr[])
{
	if (arr_size == 0 || !message_arr)
	{
		std::string message("* loud and unbearable feedback noise *");
		string_toupper(message);
		std::cout << message << std::endl;
		return ;
	}
	for (int i = 0; i < arr_size; i++)
	{
		std::string message(message_arr[i]);
		string_toupper(message);
		std::cout << message;
	}
	std::cout << std::endl;
	return ;
}

static void	string_toupper(std::string& text)
{
	for (std::string::size_type si = 0; si < text.length(); si++)
		text[si] = std::toupper(static_cast<unsigned char>(text[si]));
	return ;
}
