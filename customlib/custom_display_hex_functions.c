#include "customlib.h"

int	custom_puthex_fd(long unsigned int nb, int caps, int fd)
{
	char	*set;
	char	c;
	int		count;

	count = 0;
	if (nb >= 16)
		count = custom_puthex_fd((nb / 16), caps, fd);
	if (caps)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	c = set[nb % 16];
	custom_putchar_fd(c, fd);
	return (count + 1);
}

int	custom_display_hex(va_list arg, int caps)
{
	unsigned int	value;

	value = va_arg(arg, unsigned int);
	return (custom_puthex_fd(value, caps, 1));
}

int	custom_display_address(va_list arg)
{
	long unsigned int	value;

	value = va_arg(arg, long unsigned int);
	if (!value)
		return (custom_putstr_fd("(nil)", 1));
	custom_putstr_fd("0x", 1);
	return (custom_puthex_fd(value, 0, 1) + 2);
}
