#include "customlib.h"

static int	custom_printf_switch(const char *str, int i, va_list args)
{
	int	output;

	if (str[i] == 'i' || str[i] == 'd')
		output = custom_display_int(args);
	else if (str[i] == 'u')
		output = custom_display_unsigned(args);
	else if (str[i] == 'x')
		output = custom_display_hex(args, 0);
	else if (str[i] == 'X')
		output = custom_display_hex(args, 1);
	else if (str[i] == 'p')
		output = custom_display_address(args);
	else if (str[i] == 'c')
		output = custom_display_char(args);
	else if (str[i] == 's')
		output = custom_display_string(args);
	else if (str[i] == '%')
		output = custom_putchar_fd(str[i], 1);
	else if (!str[i])
		return (-1);
	else
		output = write(1, &str[i - 1], 2);
	return (output);
}

int	custom_printf(const char *str, ...)
{
	va_list	args;
	int		char_count;
	int		output;
	int		i;

	char_count = 0;
	if (!str)
		return (char_count);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			output = custom_printf_switch(str, ++i, args);
			char_count += output;
			if (output == -1)
				return (-1);
		}
		else
			char_count += custom_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (char_count);
}
