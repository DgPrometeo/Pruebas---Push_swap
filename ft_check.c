/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:13:26 by danielga          #+#    #+#             */
/*   Updated: 2023/09/27 20:42:20 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(char *str)
{
	int	i;

	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_repet_numbers(t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->total_size - 1)
	{
		j = i;
		while (j < data->total_size - 1)
		{
			if (data->stack_a[i] == data->stack_a[j] && i != j)
			{
				ft_free_all(data);
				ft_error();
			}
		}
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}


/*int	ft_check_dig(t_stack *data)
{
	int	i;
	int	c;

	c = 0;
	while (str[c] != NULL)
	{
		i = 0;
		while (str[c][i] != NULL)
		{
			if (str[c][i] == '-' || str[c][i] == '+')
			{
				if ((str[c][i + 1] < 48) && (str[c][i + 1] > 57))
					ft_error();
			i++;
			}
			if ((str[c][i] < 48) && (str[c][i] > 57))
				ft_error();
			i++;
		}
		c++;
	}
}
*/
