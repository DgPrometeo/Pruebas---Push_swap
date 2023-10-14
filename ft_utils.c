/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:30:02 by danielga          #+#    #+#             */
/*   Updated: 2023/10/14 11:08:07 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Tenemos dos contadores, uno para recorra el string y otro para que cuente
cada vez que encontramos una palabra. Recorremos el string hasta que sea nulo
si encontramos que no hay caracter delimitador entramos en un bucle hasta
que encontremos o el final o el delimitador, una vez lo localizemos se sumará
una palabra, y seguirá recorriendo el string hasta que encuentre otra.
Finalmente devuelve el contador de palabras delimadas por el char c.
*/
size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

/*
Para la función utilizamos dos contadores para el doble while, comparándolo
con el número total de elementos reiteradamente hasta que el contador exterior 
lo haga. 
*/
void	ft_cpystacks(t_stack *data, int *temp, int *aux)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->total_size)
	{
		j = 0;
		while (j < data->total_size)
		{
			if (temp[i] == data->stack_a[j])
			{
				aux[j] = i + 1;
			}
			j++;
		}
		i++;
	}
}

/*
Creamos una secuencia de strings en la estructura que almacena con 
ft_strjoin secuencialmente las operaciones de movimiento que se han
realizado, almacenando la temporal con el nuevo movimiento, y 
liberando el antiguo para sustituirlo por el nuevo.
*/
void	ft_printer(t_stack *data, char *str)
{
	char	*temp;

	temp = ft_strjoin(data->str, str);
	free(data->str);
	data->str = temp;
}
