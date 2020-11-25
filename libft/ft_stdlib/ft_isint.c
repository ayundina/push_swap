/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 15:28:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/10/14 15:28:47 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int edge_case_check(char *s, int minus)
{
	int i;

	i = 0;
	if (!minus)
	{
		while (s[i] <= "2147483647"[i] && i <= 10)
			i++;
		if (i < 10)
			return (0);
	}
	else
	{
		while (s[i] <= "2147483648"[i] && i <= 10)
			i++;
		if (i < 10)
			return (0);
	}
	return (1);
}

static int main_check(char *s)
{
	int i;
	char minus;

	minus = 0;
	if (s[0] == '-' && '0' <= s[1] && s[1] <= '9')
	{
		s++;
		minus = 1;
	}
	else if (s[0] == '+' && '0' <= s[1] && s[1] <= '9')
		s++;
	while (s[0] == '0')
		s++;
	i = 0;
	while ('0' <= s[i] && s[i] <= '9' && i <= 10)
		i++;
	if (s[i] != '\0' || i > 10)
		return (0);
	else if (i < 10)
		return (1);
	else
		return (edge_case_check(s, minus));
}

int ft_isint(char *s, int len)
{
	int i;
	int ret;
	char *cpy;

	if (!s)
		return (0);
	if (len == -1)
		return (main_check(s));
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy || len <= 0)
		return (-1);
	i = 0;
	while (s[i] && i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	ret = main_check(cpy);
	free(cpy);
	return (ret);
}
