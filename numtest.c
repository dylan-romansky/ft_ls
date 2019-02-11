#include "printf.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		b;
	
	b = ft_atoi(av[1]);
	ft_printf("%b\n", b);
	return (0);
}
