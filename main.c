
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int ft_ret = ft_printf("Hello, %s\n", "world");
	int ret = printf("Hello, %s", "world");

	printf("\nft_ret: %d\n ret: %d\n", ft_ret, ret);
}