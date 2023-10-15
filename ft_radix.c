/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:44:57 by danielga          #+#    #+#             */
/*   Updated: 2023/10/15 12:53:25 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack *data, int bit)
{
	int		i;
	int		shift;
	int		mask;
	int		bucket[2];

	i = -1;
	shift = bit;
	mask = (1 << shift);
	bucket[0] = 0;
	bucket[1] = 0;
	while (++i < data->size_a)
	{
		if ((data->stack_a[i] & mask) == 0)
		{
			ft_push_b(data);
			bucket[0]++;
		}
		else
		{
			ft_rot_a(data, 1);
			bucket[1]++;
		}
	}
	i = -1;
	while (++i < bucket[0])
		ft_push_a(data);
	i = -1;
	while (++i < bucket[1])
		ft_revrot_a(data, 1);
	if (bit > 0)
		ft_radix_sort(data, bit - 1);
}

void	ft_radix(t_stack *data)
{
	int	max_bit;

	max_bit = ft_max_bit(data->stack_a, data->size_a);
	ft_radix_sort(data, max_bit);
}

int	ft_max_bit(int *arr, int size)
{
	int	max;
	int	bit;
	int	i;
	int	num;

	if (size <= 0)
		return (0);
	max = ft_abs(arr[0]);
	bit = 0;
	i = 0;
	while (++i < size)
	{
		num = ft_abs(arr[i]);
		if (num > max)
			max = num;
	}
	while (max > 0)
	{
		max >>= 1;
		bit++;
	}
	return (bit);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
