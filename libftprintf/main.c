/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:58 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:08:18 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("\n[?] - Tests structure : printf then ft_printf.\n\n");

	ft_printf("\n[!] - Beginning basic tests...\n\n");

	printf("");
	printf("%");
	printf("\n% \n");
	printf("wow wow\n");
	printf("wow\t\twow\n");
	printf("%%\n");
	printf("%%%wow\n");

	ft_printf("");
	ft_printf("%");
	ft_printf("\n% \n");
	ft_printf("wow wow\n");
	ft_printf("wow\t\twow\n");
	ft_printf("%%\n");
	ft_printf("%%%wow\n");

	ft_printf("\n[!] - c conversion tests...\n\n");

	printf("Printing c : %c\n", 'c');
	printf("Printing three times c : %c%c%c\n", 'c', 'c', 'c');
	printf("Printing abc : %c%c%c\n", 'a', 'b', 'c');
	printf("Printing a null character : %c\n", 0);
	printf("Printing 9 : %c\n", '9');

	ft_printf("Printing c : %c\n", 'c');
	ft_printf("Printing three times c : %c%c%c\n", 'c', 'c', 'c');
	ft_printf("Printing abc : %c%c%c\n", 'a', 'b', 'c');
	ft_printf("Printing a null character : %c\n", 0);
	ft_printf("Printing 9 : %c\n", '9');

	ft_printf("\n[!] - s conversion tests...\n\n");

	printf("String 0 : %s\n", NULL);
	printf("String 1 : %s\n", "");
	printf("String 2 : %s\n", "\nwow\nwow\n");
	printf("String 3 : %s\n", "Without the Lord, all is in vain.");
	printf("String 4 : %s%s%s%s\n", "Without ", "the ", "Lord, ", "all is in vain.");
	printf("String 5 : %s\n", "Time to mix drinks and change lives.");
	printf("String 6 : %s\n", "\n\t\b\t\n");
	printf("String 7 : %s\n", "%s");

	ft_printf("String 0 : %s\n", NULL);
	ft_printf("String 1 : %s\n", "");
	ft_printf("String 2 : %s\n", "\nwow\nwow\n");
	ft_printf("String 3 : %s\n", "Without the Lord, all is in vain.");
	ft_printf("String 4 : %s%s%s%s\n", "Without ", "the ", "Lord, ", "all is in vain.");
	ft_printf("String 5 : %s\n", "Time to mix drinks and change lives.");
	ft_printf("String 6 : %s\n", "\n\t\b\t\n");
	ft_printf("String 7 : %s\n", "%s");
	ft_printf("\n[!] - p conversion tests...\n\n");
	
	int		a = 10;
	char	*b = "I believe life is here for us to become kinder.";
	void	*c = malloc(10);

	printf("Printing address of NULL : %p\n", NULL);
	printf("Printing address of a number : %p\n", (void *)35);
	printf("Printing address of a string literal : %p\n", (void *)"wow wow");
	printf("Printing address of a : %p\n", &a);
	printf("Printing address of b : %p\n", b);
	printf("Printing address of c : %p\n", c);

	ft_printf("Printing address of NULL : %p\n", NULL);
	ft_printf("Printing address of a number : %p\n", (void *)35);
	ft_printf("Printing address of a string literal : %p\n", (void *)"wow wow");
	ft_printf("Printing address of a : %p\n", &a);
	ft_printf("Printing address of b : %p\n", b);
	ft_printf("Printing address of c : %p\n", c);

	free(c);
	ft_printf("\n[!] - d conversion tests...\n\n");

	printf("Printing 0 : %d\n", 0);
	printf("Printing NULL : %d\n", NULL);
	printf("Printing 99 : %d\n", 99);
	printf("Printing -99 : %d\n", -99);
	printf("Printing INT_MAX : %d\n", INT_MAX);
	printf("Printing INT_MIN : %d\n", INT_MIN);

	ft_printf("Printing 0 : %d\n", 0);
	ft_printf("Printing NULL : %d\n", NULL);
	ft_printf("Printing 99 : %d\n", 99);
	ft_printf("Printing -99 : %d\n", -99);
	ft_printf("Printing INT_MAX : %d\n", INT_MAX);
	ft_printf("Printing INT_MIN : %d\n", INT_MIN);

	ft_printf("\n[!] - i conversion tests...\n\n");

	printf("Printing 0 : %i\n", 0);
	printf("Printing NULL : %i\n", NULL);
	printf("Printing 99 : %i\n", 99);
	printf("Printing -99 : %i\n", -99);
	printf("Printing INT_MAX : %i\n", INT_MAX);
	printf("Printing INT_MIN : %i\n", INT_MIN);

	ft_printf("Printing 0 : %i\n", 0);
	ft_printf("Printing NULL : %i\n", NULL);
	ft_printf("Printing 99 : %i\n", 99);
	ft_printf("Printing -99 : %i\n", -99);
	ft_printf("Printing INT_MAX : %i\n", INT_MAX);
	ft_printf("Printing INT_MIN : %i\n", INT_MIN);

	ft_printf("\n[!] - u conversion tests...\n\n");

	printf("Printing 0 : %u\n", 0);
	printf("Printing NULL : %u\n", NULL);
	printf("Printing 99 : %u\n", 99);
	printf("Printing -99 : %u\n", -99);
	printf("Printing UINT_MAX : %u\n", UINT_MAX);
	printf("Printing UINTMAX_MAX : %u\n", UINTMAX_MAX);

	ft_printf("Printing 0 : %u\n", 0);
	ft_printf("Printing NULL : %u\n", NULL);
	ft_printf("Printing 99 : %u\n", 99);
	ft_printf("Printing -99 : %u\n", -99);
	ft_printf("Printing UINT_MAX : %u\n", UINT_MAX);
	ft_printf("Printing UINTMAX_MAX : %u\n", UINTMAX_MAX);

	ft_printf("\n[!] - x conversion tests...\n\n");

	printf("Printing 0 : %x\n", 0);
	printf("Printing NULL : %x\n", NULL);
	printf("Printing 99 : %x\n", 99);
	printf("(borken) Printing -39 : %x\n", -39);
	printf("Printing abcdef : %x\n", 0xabcdef);
	printf("Printing INT_MAX : %x\n", INT_MAX);
	printf("(borken) Printing INT_MIN : %x\n", INT_MIN);

	ft_printf("Printing 0 : %x\n", 0);
	ft_printf("Printing NULL : %x\n", NULL);
	ft_printf("Printing 99 : %x\n", 99);
	ft_printf("Printing -39 : %x\n", -39);
	ft_printf("Printing abcdef : %x\n", 0xabcdef);
	ft_printf("Printing INT_MAX : %x\n", INT_MAX);
	ft_printf("Printing INT_MIN : %x\n", INT_MIN);

	ft_printf("\n[!] - X conversion tests...\n\n");

	printf("Printing 0 : %X\n", 0);
	printf("Printing NULL : %X\n", NULL);
	printf("Printing 99 : %X\n", 99);
	printf("(borken) Printing -39 : %X\n", -39);
	printf("Printing ABCDEF : %X\n", 0xabcdef);
	printf("Printing INT_MAX : %X\n", INT_MAX);
	printf("(broken) Printing INT_MIN : %X\n", INT_MIN);

	ft_printf("Printing 0 : %X\n", 0);
	ft_printf("Printing NULL : %X\n", NULL);
	ft_printf("Printing 99 : %X\n", 99);
	ft_printf("Printing -39 : %X\n", -39);
	ft_printf("Printing ABCDEF : %X\n", 0xabcdef);
	ft_printf("Printing INT_MAX : %X\n", INT_MAX);
	ft_printf("Printing INT_MIN : %X\n", INT_MIN);
}
