/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_modulo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 12:50:18 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/10/24 12:50:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_modulo(int x, int mod)
{
	if (mod < 0)
	{
		x *= -1;
		mod *= -1;
	}
	else if (mod == 0)
		return (x);
	while (x < 0)
		x += mod;
	return (x % mod);
}
