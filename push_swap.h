/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:10:30 by danielga          #+#    #+#             */
/*   Updated: 2023/09/16 19:12:00 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

/**
 * @brief Estructura básica con la información de los stacks.
 * 
 * @param stack_a Puntero al Stack A.
 * @param stack_b Puntero al Stack B.
 * @param size_a Tamaño del Stack A.
 * @param size_b Tamaño del Stack B.
 * @param total_size Tamaño total del Stack.
 * 
*/
typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
//	char	*str;
//	int		max;
	int		total_size;
}			t_stack;

int			main(int argc, char **argv);
int			ft_check_dig(char **str);
void		ft_error(void);
static void	ft_free_all(t_stack info);

#endif

//unistd - Write Read
//stdlib - Malloc Free Exit