#include <iostream>

int	main(int argc, char **argv)
{
	std::string ret;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int x = 1; argv[x] != NULL; x++)
		{
			for (int y = 0; argv[x][y] != '\0'; y++)
			{
				ret += toupper(argv[x][y]);
			}
		}
		std::cout << ret << std::endl;
	}
}
