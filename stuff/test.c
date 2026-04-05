#include <stdio.h>
#include "../src/minirt.h"

static char	*skip_zeroes(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

int	ft_str_numcmp(char *s1, char *s2)
{
	int	len;

	if (!s1 || !s2)
		return (-2);
	if (s1[0] == '-')
	{
		if (s2[0] == '-')
			return (ft_str_numcmp(s2 + 1, s1 + 1));
		return (-1);
	}
	else if (s2[0] == '-')
		return (1);
	if (strlen(skip_zeroes(s1)) == strlen(skip_zeroes(s2)))
	{
		len = strcmp(s1, s2);
		if (len == 0)
			return (0);
		else if (len < 0)
			return (-1);
		return (1);
	}
	else if (strlen(skip_zeroes(s1)) < strlen(skip_zeroes(s2)))
		return (-1);
	return (1);
}

int main()
{
	printf("%d\n", ft_str_numcmp("-0000000099", "-199"));
	return (0);
}