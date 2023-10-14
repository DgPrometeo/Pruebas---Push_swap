/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:50:36 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 20:07:52 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Para girarlo al revés, revisamos que haya elementos, y comenzamos a decir que 
el elemento ahora es su posición -1, habiendo guardado en un temporal la última 
posición para colocarla en la primera.
*/
void	ft_revrot_a(t_stack *data, int flag)
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
	}
	if (flag == 1)
		ft_printer(data, "rra\n");
}

/*
Para girarlo al revés, revisamos que haya elementos, y comenzamos a decir que 
el elemento ahora es su posición -1, habiendo guardado en un temporal la última 
posición para colocarla en la primera.
*/
void	ft_revrot_b(t_stack *data, int flag)
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
	}
	if (flag == 1)
		ft_printer(data, "rrb\n");
}

/*
Para más facilidad, ejecutamos las dos funciones pero con las flag en 0 para que
no imprima que ha realizado ese comando, salvo el indicado en este.
*/
void	ft_rrr(t_stack *data)
{
	ft_revrot_a(data, 0);
	ft_revrot_b(data, 0);
	ft_printer(data, "rrr\n");
}
