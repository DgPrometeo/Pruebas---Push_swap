/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:13:17 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 19:52:33 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Hacemos un swap con un int temporal que será el que cambie la secuencia.
*/
void	ft_swap_a(t_stack *data, int flag)
{
	int	temp;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
	}
	if (flag == 1)
		ft_printer(data, "sa\n");
}

/*
Hacemos un swap con un int temporal que será el que cambie la secuencia.
*/
void	ft_swap_b(t_stack *data, int flag)
{
	int	temp;

	if (data->size_b > 1)
	{
		temp = data->stack_a[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
	}
	if (flag == 1)
		ft_printer(data, "sb\n");
}

/*
Realiza las dos funciones e imprime.
*/
void	ft_ss(t_stack *data)
{
	ft_swap_a(data, 0);
	ft_swap_b(data, 0);
	ft_printer(data, "ss\n");
}
