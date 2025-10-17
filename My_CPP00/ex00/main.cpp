void	megaphone(int arr_size, char *str_arr[]);

int	main(int argc, char *argv[])
{
	megaphone(argc - 1, argv + 1);
	return (0);
}
