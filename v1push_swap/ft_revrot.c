/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:50:36 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 10:44:10 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrot_a(t_stack *data)
{
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_a[data->size_a - 1];
		i = data->size_a - 1;
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[i] = temp;
		ft_printer(data, "rra\n");
	}
}

void	ft_revrot_b(t_stack *data)
{
	int	temp;
	int	i;

	if (data->size_b > 1)
	{
		temp = data->stack_b[data->size_b - 1];
		i = data->size_b - 1;
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[i] = temp;
		ft_printer(data, "rrb\n");
	}
}

void	ft_rrr(t_stack *data)
{
	ft_revrot_a(data);
	ft_revrot_b(data);
	ft_printer(data, "rrr\n");
}
