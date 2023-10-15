/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:47:54 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 10:32:14 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_a(t_stack *data)
{
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		i = 0;
		while (i < data->size_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = temp;
		ft_printer(data, "ra\n");
	}
}

void	ft_rot_b(t_stack *data)
{
	int	temp;
	int	i;

	if (data->size_b > 1)
	{
		temp = data->stack_b[0];
		i = 0;
		while (i < data->size_b - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = temp;
		ft_printer(data, "rb\n");
	}
}

void	ft_rr(t_stack *data)
{
	ft_rot_a(data);
	ft_rot_b(data);
	ft_printer(data, "rr\n");
}
