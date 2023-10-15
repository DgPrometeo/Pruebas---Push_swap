/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:13:17 by danielga          #+#    #+#             */
/*   Updated: 2023/10/15 13:56:44 by danielga         ###   ########.fr       */
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

//				RADIX

//				RADIX DE ARRAY ADAPTADO
void	counting_sort(t_stack *data, int place)
{
	int	count[data->max + 1];
	int	i;
	int output;

	i = 0;
	while (i <= data->max)
	{
		count[i] = 0;
		i++;
	}
	i = 0;
	while (i <= data->max)
	{
		count[i] += count[i-1];
		i++;
	}
	output[data->size_a];
	i = data->size_a - 1;
	while (i >= 0)
	{
		output[count[(data->stack_a[i] / place) % 10] - 1] = data->stack_a[i];
		count[(data->stack_a[i] / place) % 10]--;
		i--;
	}
	i = 0;
	while (i < data->size_a)
	{
		data->stack_a[i] = output[i];
		i++;
	}
}

void	ft_radix(t_stack *data)
{
	int	place;

	place = 1;
	while (data->max / place > 0)
	{
		counting_sort(data, place);
		place *= 10;
	}
}
//---------------------------------------------------------------------
	/*
	for (int i = 0; i < max; ++i)
		do_something
	----
	int	i;
	i = 0;
	while (i < max)
	{
		i++;
		do_something
	}
	*/

// void	ft_radix(t_stack *data)
// {
// 	int			i;
// 	uint32_t	check;

// 	i = 0;
// 	check = 0b1;
// 	while (!ft_check_sort(data))
// 	{
// 		while (i < data->total_size)
// 		{
// 			if (!(data->stack_a[0] & check))
// 				ft_push_b(data);
// 			else if (data->size_a > 1)
// 				ft_rot_a(data, 1);
// 			i++;
// 		}
// 		while (data->size_b)
// 			ft_push_a(data);
// 		i = 0;
// 		check <<= 1;
// 	}
// }
	/*
	Calculates the number of bits required to represent the
	largest element in a stack of integers. It takes a pointer
	to a pointer to a t_list structure as input and returns
	the number of bits as an integer.
	*/
/* prueba 4
size_t	ft_get_max_bits(t_stack *stacks)
{
	size_t	max_value;
	size_t	max_bits;

	max_value = stacks->max - 1;
	max_bits = 0;
	while ((max_value >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}
*/
	/*
	Function takes two pointers to t_list structures as input and
	sorts the stack using the radix sort algorithm. It first determines
	the maximum number of bits needed to represent the largest element
	in the stack, then iterates through each bit position and performs
	bucket sorting based on that position. Finally, it assembles the
	sorted stack by repeatedly pushing the elements back onto stack A.
	*/
/* prueba 4
void	ft_radix(t_stack *data)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = data->size_a;
	max_bits = ft_get_max_bits(data);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((data->stack_a[0] >> i) & 1) == 1)
				ft_rot_a(data, 1);
			else
				ft_push_b(data);
		}
		while (data->size_b != 0)
			ft_push_a(data);
		i++;
	}
}
*/
/*size_t	ft_get_max_bits(t_stack *stacks)
{ prueba 3
	size_t	max_value;
	size_t	max_bits;

	max_value = stacks->max - 1;
	max_bits = 0;
	while ((max_value >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix(t_stack *data)
{   prueba 3
	size_t		max_bits;
	size_t		bit_idx;
	int			stack_idx;

	max_bits = ft_get_max_bits(data);
	bit_idx = 0;
	while (bit_idx < max_bits)
	{
		stack_idx = 0;
		while (stack_idx < data->max)
		{
			if ((((data->stack_a[0]) >> bit_idx) & 1) == 1)
				ft_rot_a(data, 1);
			else
				ft_push_b(data);
			stack_idx++;
		}
		while ((data->size_b) > 0)
			ft_push_a(data);
		bit_idx++;
	}
}*/
// --------------------------------------------------------------------


/* pprueba 2
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
