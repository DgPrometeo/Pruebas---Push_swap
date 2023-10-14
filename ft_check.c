/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:13:26 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 14:19:08 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Recorre el string con un contador hasta que sea nulo, si localiza un carácter
que no sea dígito devolverá 0. En el caso que haya un + o un -, pasará a la 
siguiente posición para verificar el número, pero si hay más de un + o un -
en un mísmo dígito dará error por lo que saldrá también. Si todos son números
dará 1.
*/
int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
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
	while (i < data->total_size)
	{
		j = i;
		while (j < data->total_size)
		{
			if (data->stack_a[i] == data->stack_a[j] && i != j)
			{
				ft_free_all(data);
				ft_error();
			}
			j++;
		}
		i++;
	}
}

/*
Recorrerá la secuencia de enteros en el stack 1 revisando que todos estén
ordenador, si encuentra uno que el siguiente sea superior al anterior devuelve 0
Si todos están ordenadors secuancialmente dara 1.
*/
int	ft_check_sort(t_stack *data)
{
	int	i;

	i = 0;
	while (i < data->total_size - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_limits(t_stack *data)
{
	int		i;
	long	min_int;

	i = 0;
	min_int = -2147483648;
	while (data->stack_a[i])
	{
		if (data->stack_a[i] < min_int || data->stack_a[i] > 2147483647)
		{
			ft_printf("error\n");
			ft_free_all(data);
			ft_error();
		}
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
