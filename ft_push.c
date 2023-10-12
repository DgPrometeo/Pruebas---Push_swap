/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:09:22 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 18:36:35 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack *data)
{
	int	i;

	if (data->size_b > 0)
	{
		i = data->size_a;
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[0] = data->stack_b[0];
		i = 0;
		while (i < data->size_b - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = 0;
		data->size_a++;
		data->size_b--;
		ft_printer(data, "pa\n");
	}
}

void	ft_push_b(t_stack *data)
{
	int	i;

	if (data->size_a > 0)
	{
		i = data->size_b + 1;
		while (--i > 0)
			data->stack_b[i] = data->stack_b[i - 1];
		data->stack_b[0] = data->stack_a[i + 1];
		i = -1;
		while (++i < data->size_a -1)
			data->stack_a[i] = data->stack_a[i + 1];
		data->stack_a[i] = 0;
		data->size_b++;
		data->size_a--;
		ft_printer(data, "pb\n");
	}
}
/*

 */