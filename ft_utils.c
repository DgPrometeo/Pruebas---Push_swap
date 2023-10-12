/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:30:02 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 17:57:20 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_printer(t_stack *data, char *str)
{
	char	*temp;

	temp = ft_strjoin(data->str, str);
	free(data->str);
	data->str = temp;
}
