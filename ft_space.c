#include "my_flags.h"

void	ft_space(int i, int b)
{
	int 	a;

	a = 0;
	while(a < (b - i))
	{
		ft_putchar(' ');
		a++;
	}
}

int	ft_count_nbr(int i)
{
	int 	a;

	a = 0;
	while(i /= 10)
		a++;
	return (a);
}
