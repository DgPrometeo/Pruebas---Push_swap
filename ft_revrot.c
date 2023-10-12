/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:50:36 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 18:16:02 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrot_a(t_stack *data)
{
	ft_printer(data, "rra\n");
}

void	ft_revrot_b(t_stack *data)
{
	ft_printer(data, "rrb\n");
}

void	ft_rrr(t_stack *data)
{
	ft_revrot_a(data);
	ft_revrot_b(data);
	ft_printer(data, "rrr\n");
}
