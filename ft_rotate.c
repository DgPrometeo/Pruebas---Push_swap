/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:47:54 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 20:06:39 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Para girarlo, revisamos que haya elementos, y comenzamos a decir que el elemento
ahora es su posición +1, habiendo guardado en un temporal la primera posición
para colocarla en la última.
*/
void	ft_rot_a(t_stack *data, int flag)
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
	}
	if (flag == 1)
		ft_printer(data, "ra\n");
}

/*
Para girarlo, revisamos que haya elementos, y comenzamos a decir que el elemento
ahora es su posición +1, habiendo guardado en un temporal la primera posición
para colocarla en la última.
*/
void	ft_rot_b(t_stack *data, int flag)
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
	}
	if (flag == 1)
		ft_printer(data, "rb\n");
}

/*
Para más facilidad, ejecutamos las dos funciones pero con las flag en 0 para que
no imprima que ha realizado ese comando, salvo el indicado en este.
*/
void	ft_rr(t_stack *data)
{
	ft_rot_a(data, 0);
	ft_rot_b(data, 0);
	ft_printer(data, "rr\n");
}
