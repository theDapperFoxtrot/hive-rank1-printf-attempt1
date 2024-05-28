#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	char str[] = "The code!";	
	int size = ft_printf("String: %s\n", str);
	printf("bytes: %d\nStandard: %s\n", size, str);
	printf("Standard bytes: %d\n\n", printf("String: %s\n", str));

	size = ft_printf("String");
	printf("\nbytes: %d\nStandard: %s\n", size, "String");
	printf("\nStandard bytes: %d\n\n", printf("String"));

	size = ft_printf("Number = %d\n", 598291);
	printf("bytes: %d\nStandard: %d\n", size, 598291);
	printf("Standard bytes: %d\n\n", printf("Number = %d\n", 598291));


	size = ft_printf("Number = %x\n", 455);
	printf("bytes: %d\nStandard: %x\n", size, 455);
	printf("Standard bytes: %d\n\n", printf("Number = %x\n", 455));

	size = ft_printf("Number = %X\n", 211);
	printf("bytes: %d\nStandard: %X\n", size, 211);
	printf("Standard bytes: %d\n\n", printf("Number = %X\n", 211));

	const char *str2 = "String";
	printf("\nVoid * argument: %p\n", str);
	ft_printf("\nMy Void * argument: %p\n", str);
	int s = 1100000000, w = 1100000000;
	int *p = malloc(sizeof(int) * 30);
	printf("Another one %%p: %p\n", 1100000000);
	printf("Another one %%p: %p\n", &s);
	printf("Another one %%p: %p\n", &w);
	printf("Another one %%p: %p\n", p);

	ft_printf("My Another one %%p: %p\n", 1100000000);
	ft_printf("My Another one %%p: %p\n", &s);
	ft_printf("My Another one %%p: %p\n", &w);
	ft_printf("My Another one %%p: %p\n", p);

	free(p);

	ft_printf("My %%p %%p 0 and 0: %p %p \n", 0, 0);
	printf("Original %%p %%p 0 and 0: %p %p \n\n", 0, 0);

	ft_printf("My %%p %%p -69375981295 and -69375981295: %p %p \n", -69375981295, -69375981295);
	printf("Original %%p %%p -69375981295 and -69375981295: %p %p \n\n", -69375981295, -69375981295);
	ft_printf("My %%p %%p -255 and 879544351315: %p %p \n", -255, 879544351315);
	printf("Original %%p %%p -255 and 879544351315: %p %p \n\n", -255, 879544351315);
	ft_printf("My %%p %%p INT_MAX and INT_MIN: %p %p \n", INT_MAX, INT_MIN);
	printf("Original %%p %%p INT_MAX and INT_MIN: %p %p \n\n", INT_MAX, INT_MIN);
	ft_printf("My %%p %%p LONG_MAX and LONG_MIN: %p %p \n", LONG_MAX, LONG_MIN);
	printf("Original %%p %%p LONG_MAX and LONG_MIN: %p %p \n\n", LONG_MAX, LONG_MIN);
	ft_printf("My %%p ULONG_MAX: %p \n", ULONG_MAX);
	printf("Original %%p ULONG_MAX: %p \n\n", ULONG_MAX);
	ft_printf("My 7 %% marks: %%%%%%% \n");
	printf("Original 7 %% marks: %%%%%%% \n\n");
	ft_printf("My %%u %%u LONG_MAX and LONG_MIN: %u %u \n", LONG_MAX, LONG_MIN);
	printf("Original %%u %%u LONG_MAX and LONG_MIN: %u %u \n\n", LONG_MAX, LONG_MIN);
	ft_printf("My %%u ULONG_MAX: %u \n", ULONG_MAX);
	printf("Original %%u ULONG_MAX: %u \n\n", ULONG_MAX);
}
