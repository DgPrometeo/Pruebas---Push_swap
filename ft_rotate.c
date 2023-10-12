/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:47:54 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 18:15:38 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_a(t_stack *data)
{
	ft_printer(data, "ra\n");
}

void	ft_rot_b(t_stack *data)
{
	ft_printer(data, "rb\n");
}

void	ft_rr(t_stack *data)
{
	ft_rot_a(data);
	ft_rot_b(data);
	ft_printer(data, "rr\n");
}
