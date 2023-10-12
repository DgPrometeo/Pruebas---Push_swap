/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:13:17 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 12:49:09 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
En esta función necesitamos dos mallocs temporales para poder copiar la
información, realizar el algoritmo bubble, copiarlos y libterar los datos para
colocar los nuevos de manera ordenada.
*/
char	*ft_index(t_stack *data)
{
	int	*temp;
	int	*aux;

	temp = malloc(sizeof(int) * data->total_size);
	aux = malloc(sizeof(int) * data->total_size);
	if (!temp || !aux)
	{
		ft_free_all(data);
		ft_error ();
	}
	ft_memcpy(temp, data->stack_a, sizeof(int) * data->total_size);
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
	while (a < data->total_size)
	{
		b = 0;
		while (b < data->total_size - 1)
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
