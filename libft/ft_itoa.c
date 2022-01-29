#include "libft.h"

static char	*ft_strdup_ft(const char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	s2[i] = '\0';
	i--;
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}

static char	*ft_min_int_zero(int	n)
{
	if (n == -2147483648)
		return (ft_strdup_ft("-2147483648"));
	if (n == 0)
		return (ft_strdup_ft("0"));
	return (0);
}

static int	ft_numlen(int	n)
{
	int		l;

	l = 0;
	while (n > 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	if (n == -2147483648 || n == 0)
		return (ft_min_int_zero(n));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_numlen(n) + neg;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	str[len] = '\0';
	while (n)
	{
		str[--len] = n % 10 +48;
		n /= 10;
	}
	return (str);
}
