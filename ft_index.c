/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:13:17 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 20:00:20 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En esta función necesitamos dos mallocs temporales para poder copiar la
información, realizar el algoritmo bubble, copiarlos y libterar los datos para
colocar los nuevos de manera ordenada.
*/
void	ft_index(t_stack *data)
{
	int	*temp;
	int	*aux;

	temp = malloc(sizeof(int) * data->max);
	aux = malloc(sizeof(int) * data->max);
	if (!temp || !aux)
	{
		ft_free_all(data);
		ft_error ();
	}
	ft_memcpy(temp, data->stack_a, sizeof(int) * data->max);
	ft_bubble_sort(temp, data);
	ft_cpystacks(data, temp, aux);
	free(data->stack_a);
	data->stack_a = aux;
	free(temp);
}

/*
Esta función vamos a crear el algoritmo bubble con dos contadores y un swap.
Creamos un bucle para el primer contador que sea la primera posición del bubble.
Creamos otro contador que será el que se mueva y vaya verificando la posición
y la siguiente. En el caso que sea mayor la anterior, se modifican con un swap.
Es necesario realizar doble while, para que el interior vaya modificando, y el 
otro va volviendo a revisar de 0 desde el principio, para que así todas se
revisen hasta que se haya hecho el número de veces del total de números que hay.
*/
void	ft_bubble_sort(int*temp, t_stack *data)
{
	int	swap;
	int	a;
	int	b;

	a = 0;
	while (a < data->max)
	{
		b = 0;
		while (b < data->max - 1)
		{
			if (temp[b] > temp[b + 1])
			{
				swap = temp[b];
				temp[b] = temp[b + 1];
				temp[b + 1] = swap;
			}
			b++;
		}
		a++;
	}
}

void	ft_radix(t_stack *data)
{
	int			i;
	uint32_t	check;

	i = 0;
	check = 0b1;
	while (!ft_check_sort(data))
	{
		while (i < data->total_size)
		{
			if (!(data->stack_a[0] & check))
				ft_push_b(data);
			else if (data->size_a > 1)
				ft_rot_a(data, 1);
			i++;
		}
		while (data->size_b)
			ft_push_a(data);
		i = 0;
		check <<= 1;
	}
//	if (!ft_check_sort(data))
//		ft_radix(data);
}

/*
void	ft_radix(t_stack *data)
{
	int	no_bit;
	int	sizebit;
	int	size_a;
	int	size_b;

	sizebit = 0;
	size_a = data->size_a;
	while (size_a > 1 && ++sizebit)
		size_a /= 2;
	no_bit = -1;
	while (++no_bit <= sizebit)
	{
		size_a = data->size_a;
		while (size_a-- && !ft_check_sort(data))
		{
			if (((data->stack_a[0] >> no_bit) & 1) == 0)
				ft_push_b(data);
			else
				ft_rot_a(data);
		}
		size_b = data->size_b;
		while (size_b-- && (no_bit + 1) <= sizebit && !ft_check_sort(data))
		{
			if (((data->stack_b[0] >> (no_bit + 1)) & 1) == 0)
				ft_rot_b(data);
			else
				ft_push_a(data);
		}
		if (ft_check_sort(data))
			while (data->size_b != 0)
				ft_push_a(data);
	}
	while (data->size_b != 0)
		ft_push_a(data);
}
*/
