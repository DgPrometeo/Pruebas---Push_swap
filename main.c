/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:09:22 by danielga          #+#    #+#             */
/*   Updated: 2023/10/15 12:24:07 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
Libera la memoria del Stack A, del Stack B, del string donde se guarda
la secuencia de movimientos, y finalmente libera la structura.
*/
void	ft_free_all(t_stack *info)
{
	free(info->stack_a);
	free(info->stack_b);
	free(info->str);
	free(info);
}

/*
Función inicial que procederá a crear la struc con las dimensiones correctas.
Verifica que se haya creado bien, indicamos que el tamaño total de números.
Los introducimos al Stack_a y b las dimensiones del tamaño total.
Le indicamos que tamaño tiene cada stack, siendo el máximo en A y 0 en B.
*/
t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*data;

	data = (t_stack *)malloc(sizeof(t_stack));
	if (!data)
		exit(0);
	if (argc == 2)
		data->total_size = ft_wordcounter(argv[1], 32);
	else
		data->total_size = argc - 1;
	data->stack_a = ft_calloc(data->total_size, sizeof(int));
	if (!data->stack_a)
		ft_free_all(data);
	data->stack_b = ft_calloc(data->total_size, sizeof(int));
	if (!data->stack_b)
		ft_free_all(data);
	data->str = ft_strdup("");
	data->max = data->total_size;
	data->size_a = data->total_size;
	data->size_b = 0;
	return (data);
}

/*
Primero creamos la estructura con el formato correspondiente, después
insertamos los números según como nos lo den en los argumentos.
Revisamos la repetición de números, indexamos los números para simplificar
procedemos a llevarla a la selección de algoritmos para ejecute la forma
correcta de ordenamiento. Terminamos imprimiendo en pantalla la secuencia de 
movimientos y liberando la memoria de la estructura completa.
*/
int	main(int argc, char **argv)
{
	t_stack	*data;

	data = ft_init_stack(argc, argv);
	ft_insert(data, argc, argv);
	ft_repet_numbers(data);
//	ft_check_limits(data);
	ft_index(data);
	ft_algorithmics(data);
	ft_printf("%s", data->str);
	ft_free_all(data);
	return (0);
}
