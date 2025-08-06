#include "../cub3d.h"

int	cub_extension(char *file)
{
	int	index;

	index = 0;
	while (file[index])
		index++;
	index--;
	if (file[index] == 'b' && file[index - 1] == 'u'
		&& file[index - 2] == 'c' && file[index - 3] == '.')
		return (TRUE);
	return (FALSE);
}

int	prestructure_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (p_print(EARGC));
	if (cub_extension(argv[1]) == FALSE)
		return (p_print(ECUB));
	return (TRUE);
}
