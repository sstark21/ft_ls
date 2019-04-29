#include <string.h>
int     *check_flags(int argc, char **argv)
{
    int     flags[5] = {0};
    int	    i = 1;
	int	    b = 1;

	while (b < argc)
	{
		while (argv[b][i])
		{
			if (argv[b][0] == '-' && argv[b][i] != 'l' && argv[b][i] != 'R'
                    && argv[b][i] != 'a'
                    && argv[b][i] != 'r' && argv[b][i] != 't')
			{
				write(1, "options: lRart\n", 15);
				return (NULL);
			}
			else if (argv[b][0] == '-' && argv[b][i] == 'l')		
				flags[0] = 1;
			else if (argv[b][0] == '-' && argv[b][i] == 'R')		
				flags[1] = 1;
            else if (argv[b][0] == '-' && argv[b][i] == 'a')		
				flags[2] = 1;
            else if (argv[b][0] == '-' && argv[b][i] == 'r')		
				flags[3] = 1;
            else if (argv[b][0] == '-' && argv[b][i] == 'l')		
				flags[4] = 1;
			i++;
		}
		b++;
		i = 1;
	}
	return (flags);
}