#include "customlib.h"

void	custom_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		num;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		custom_putchar_fd('-', fd);
	}
	if (ln >= 10)
		custom_putnbr_fd((ln / 10), fd);
	num = ln % 10 + '0';
	custom_putchar_fd(num, fd);
}

/* int	main()
{
	custom_putnbr_fd(123456, 1);
} */
