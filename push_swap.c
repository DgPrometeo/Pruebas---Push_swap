/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:09:22 by danielga          #+#    #+#             */
/*   Updated: 2023/05/17 19:44:27 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	long	stack_a;
	long	stack_b;

	if (argc < 2)
		return (0);
	else
	{
		stack_a = argv[2];
		stack_b = 0;
	}
	return (0);
}

/*
- Tenemos que revisar que nos dé los elementos a ordenar y que no se encuentren
repetidos. 
- Los indexamos para simplificar todo el programa dando la posición correcta
que debería de tener.

 */