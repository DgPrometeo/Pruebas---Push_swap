/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithmics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:34 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 17:49:32 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Según la cantidad de números, le asignará el sistema de ordenamiento, desde 2
hasta más de 5 usando radix
*/
void	ft_algorithmics(t_stack *data)
{
	if (data->size_a == 2)
		ft_sort2(data);
	else if (data->size_a == 3)
		ft_sort3(data);
	else if (data->size_a == 4)
		ft_sort4(data);
	else if (data->size_a == 5)
		ft_sort5(data);
	else if (data->size_a > 5)
		ft_radix(data);
}

void	ft_sort2(t_stack *data)
{
	if (data->stack_a[0] > data->stack_a[1])
	{
		ft_swap_a(data);
	}
}

void	ft_sort3(t_stack *data)
{
	if (data->stack_a[0] == 1 && data->stack_a[1] == 3 && data->stack_a[2] == 2)
	{
		ft_swap_a(data);
		ft_ra(data);
	}
	if (data->stack_a[0] == 2)
	{
		if (data->stack_a[1] == 1)
			ft_swap_a(data);
		else
			ft_rra(data);
	}
	if (data->stack_a[0] == 3)
	{
		if (data->stack_a[1] == 1 || data->stack_a[1] == 2)
			ft_ra(data);
		if (data->stack_a[1] == 1)
			ft_swap_a(data);
	}
}

void	ft_sort4(t_stack *data)
{
	if (data->stack_a[1] == 4)
		ft_ra(data);
	else if (data->stack_a[2] == 4)
	{
		ft_ra(data);
		ft_ra(data);
	}
	else if (data->stack_a[3] == 4)
		ft_rra(data);
	ft_push_b(data);
	ft_sort3(data);
	ft_push_a(data);
	ft_ra(data);
}

void	ft_sort5(t_stack *data)
{
	if (data->stack_a[0] == 5)
		ft_push_b(data);
	else if (data->stack_a[1] == 5)
	{
		ft_ra(data);
		ft_push_b(data);
	}
	else if (data->stack_a[2] == 5)
	{
		ft_ra(data);
		ft_ra(data);
		ft_push_b(data);
	}
	else if (data->stack_a[3] == 5)
	{
		ft_rra(data);
		ft_rra(data);
		ft_push_b(data);
	}
	else if (data->stack_a[4] == 5)
	{
		ft_rra(data);
		ft_push_b(data);
	}
	ft_sort4(data);
	ft_push_a(data);
	ft_ra(data);
}
