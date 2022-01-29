#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
	{
		write (fd, "-", 1);
		i = (unsigned int)n * -1;
	}
	else
		i = (unsigned int)n;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(((i % 10) + 48), fd);
}
