/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:09:22 by danielga          #+#    #+#             */
/*   Updated: 2023/09/27 20:50:20 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_all(t_stack *info)
{
	free(info->stack_a);
	free(info->stack_b);
	free(info);
}


/*
Función inicial que procederá a crear la struc con las dimensiones correctas.
Verifica que se haya creado bien, indicamos que el tamaño total de números.
Los introducimos al Stack_a y b las dimensiones del tamaño total.
Le indicamos que tamaño tiene cada stack, siendo el máximo en A y 0 en B.
*/

int	main(int argc, char **argv)
{
	t_stack	*data;
	int		i;

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
	data->size_a = data->total_size;
	data->size_b = 0;
	ft_insert(data, argc, argv);
	return (0);
}
	/*if (argc < 2)
		return (0);
	if (argc == 2)
		stack_argv = ft_split(argv[1], 32);
	if (argc > 2)
	{
		i = 0;
		stack_argv = malloc(sizeof(char *) * argc);
		if (!stack_argv)
			return (NULL);
		while (i < (argc - 1))
		{
			stack_argv[i] = ft_strdup(argv[1 + i]);
			i++;
		}
		stack_argv[i] = NULL;
	}
	i = 0;
	while (stack_argv[i] != '\0')
	{
		if (ft_isdigit(stack_argv[i]) == 0)
			return (0);
		i++;
	}*/

/*
- Tenemos que revisar que nos dé los elementos a ordenar y que no se encuentren
repetidos. 
- Los indexamos para simplificar todo el programa dando la posición correcta
que debería de tener.

/si son dos argumentos. eso quiere decir que vienen comillados, por lo que 
lo enviamos a un split, con el delimitador de un espacio.
si son más de dos argumentos, tenemos que establecer un malloc del tamaño de argc
y enviarlo a un strdup para que vaya metiendo cada argumento en una celda del
mismo.
 */
/*
La el programa push_swap debe de contener:
- Creación de pilas A y B.
- 
*/