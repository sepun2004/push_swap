/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:00:24 by sepun             #+#    #+#             */
/*   Updated: 2024/08/23 21:54:37 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>


// int number_of_arguments(int argc, t_list *top);
int	ft_check_string(char **argv);
int ft_check_chars(char **argv);
int ft_check_limits(char **argv);
int ft_check_duplicate(t_list *head_list, int num);
char **check_error(char **argv/*, int argc*/);
int main(int argc, char **argv);

//move
void	swap(t_list **top);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **top);
void reverse_rotate(t_list **top);
t_list *number_of_arguments(int argc, t_list *top);

#endif
