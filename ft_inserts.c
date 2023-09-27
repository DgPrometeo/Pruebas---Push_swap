/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inserts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:49:47 by danielga          #+#    #+#             */
/*   Updated: 2023/09/27 21:02:11 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_str(t_stack *data, char **argv)
{
	int		i;
	char	**tmp;
	int		n;

	n = -1;
	argv = ft_split(argv[1], 32);
	i = 0;
	while (argv[i])
		i++;
	tmp = ft_calloc(i + 1, sizeof(char *));
}

void	ft_make_atoi(t_stack *data, char **argv)
{
	int	i;

	i == 0;
	while (i < data->total_size + 1)
	{
		data->stack_a[i] == ft_atoi(argv[i]);
		i++;
	}
}

void	ft_insert(t_stack *data, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_free_all(data);
		ft_error();
	}
	if (argc == 2)
	{
		ft_insert_str(data, argv);
		return ;
	}
	while (argv[i])
	{
		if (!ft_check_digit(argv[i]))
		{
			ft_free_all(data);
			ft_error();
		}
		i++;
	}
	ft_make_atoi(data, argv);
}