#include "customlib.h"

static int	custom_num_len(long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	custom_display_int(va_list arg)
{
	int	value;

	value = va_arg(arg, int);
	custom_putnbr_fd(value, 1);
	return (custom_num_len(value));
}

int	custom_display_unsigned(va_list arg)
{
	unsigned int	value;

	value = (unsigned int)va_arg(arg, unsigned int);
	custom_putnbr_fd(value, 1);
	return (custom_num_len(value));
}

int	custom_display_char(va_list arg)
{
	char	value;

	value = va_arg(arg, int);
	custom_putchar_fd(value, 1);
	return (1);
}

int	custom_display_string(va_list arg)
{
	char	*value;

	value = va_arg(arg, char *);
	if (!value)
		return (custom_putstr_fd("(null)", 1));
	return (custom_putstr_fd(value, 1));
}
