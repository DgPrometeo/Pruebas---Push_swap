/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithmics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:34 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 13:38:24 by danielga         ###   ########.fr       */
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
		ft_sa(data);
}

void	ft_sort3(t_stack *data)
{
	
}

void	ft_sort4(t_stack *data)
{
	
}

void	ft_sort5(t_stack *data)
{
	
}
