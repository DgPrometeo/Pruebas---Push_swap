/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:13:17 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 18:14:50 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *data)
{
	int	temp;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
		ft_printer(data, "sa\n");
	}
}

void	ft_swap_b(t_stack *data)
{
	int	temp;

	if (data->size_b > 1)
	{
		temp = data->stack_a[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
		ft_printer(data, "sb\n");
	}
}

void	ft_ss(t_stack *data)
{
	ft_swap_a(data);
	ft_swap_b(data);
	ft_printer(data, "ss\n");
}
