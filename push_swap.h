/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:10:30 by danielga          #+#    #+#             */
/*   Updated: 2023/10/12 00:24:01 by danielga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

/**
 * @brief Estructura básica con toda la información de los stacks.
 * 
 * @param stack_a Puntero al Stack A.
 * @param stack_b Puntero al Stack B.
 * @param size_a Tamaño del Stack A.
 * @param size_b Tamaño del Stack B.
 * @param str Alberga el listado de operaciones realizadas.
 * @param total_size Tamaño total del Stack.
 * 
*/
typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	*str;
	int		total_size;
}			t_stack;

// 					MAIN.C

/**
 * @brief Función principal que recogerá los argumentos dados.
 * 
 * @param argc Cantidad de argumentos que ha dado.
 * @param argv Argumentos dados.
*/
int			main(int argc, char **argv);

/**
 * @brief Libera todos los elementos de los stacks.
 * 
 * @param info struct a liberar.
 * 
 * @return Destruye toda la memoria reservada.
*/
static void	ft_free_all(t_stack info);

// 					CHECK.C

/**
 * @brief Revisa todo los elementos del stack para verificar que no haya ninguno 
 * repetido.
 * 
 * @param data El struck donde se almacenan los stacks.
 * 
 * @return Devolverá la lista si todo está correctamente sin repeticiones.
 * @return Enviará a liberar los stacks y salir del programa si hay repetidos.
*/
void		ft_repet_numbers(t_stack *data);

/**
 * @brief Revisa que todos los argumentos sean dígitos.
 * 
 * @param str String donde se encuentran todos los elementos.
 * 
 * @return Devuelve 0 si hay algún elemento que no sea dígito.
 * @return Devuelve 1 si todos son dígitos.
*/
int			ft_check_digit(char *str);

/**
 * @brief Función que muestra el error y sale del programa.
*/
void		ft_error(void);

//					FT_UTILS.C

/**
 * @brief Cuenta todas los elementos separados por un caracter.
 * 
 * @param s String a revisar y contar.
 * @param c Caracter delimitador.
 * 
 * @return La cantidad de elementos delimitados por el caracter indicado.
*/
size_t		ft_wordcounter(char const *s, char c);

//					FT_INSERTS.C

/**
 * @brief Zona de insertar los números y de control de revisiones.
 * 
 * @param data El Struck donde se almancenan los Stacks
 * @param argc Número de argumentos dados.
 * @param argv Argumentos dados.
 * 
 * @return Fallará si ha ocurrido algún error al revisar, liberando todo.
*/
void		ft_insert(t_stack *data, int argc, char **argv);

#endif

//unistd - Write Read
//stdlib - Malloc Free Exit