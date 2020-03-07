#include <unistd.h>
int					ft_strlen(const char *str)
{
	int			i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

void		decal(char *s, int start, int end)
{
	int 	i;

	i = start;
	while (i++ < end - 1)
	{
		s[i] = s[i - 1];
	}
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *s)
{
	int 			i;

	i = 0;
	while(s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	int			i;
	int			j;
	int			n2;
	int			n1;

	i = 0;
	j = 1;
	n1 = ft_strlen(argv[1]);
	n2 = ft_strlen(argv[2]);
	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[1][j])
			{
				if (argv[1][i] == argv[1][j])
					decal(argv[1], i, n1);
				j++;
			}
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[1][j])
					decal(argv[1], i, n2);
				j++;
			}
			i++;
		}
		while (argv[2][i])
		{
			while (argv[2][j])
			{
				if (argv[2][i] == argv[1][j])
					decal(argv[2], i, n1);
				j++;
			}
			j = 0;
			while (argv[2][j])
			{
				if (argv[2][i] == argv[1][j])
					decal(argv[2], i, n2);
				j++;
			}
			i++;
		}
		ft_putstr(argv[1]);
		ft_putstr(argv[2]);
	}

}