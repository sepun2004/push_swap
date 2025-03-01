/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:38:16 by sepun             #+#    #+#             */
/*   Updated: 2025/01/09 19:53:33 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_list **top)
{
	if (((*top)->content) > ((*top)->next->content))
		swap(top, 'a');
}

void	sort_3(t_list **top)
{
	int	firt_number;
	int	second_number;
	int	last_number;

	firt_number = (*top)->content;
	second_number = (*top)->next->content;
	last_number = (*top)->next->next->content;
	if ((firt_number > second_number) && (second_number < last_number)
		&& (firt_number < last_number))
		swap(top, 'a');
	else if ((firt_number < second_number) && (second_number > last_number)
		&& (firt_number > last_number))
		reverse_rotate(top, 'a');
	else if ((firt_number > second_number) && (second_number > last_number)
		&& (firt_number > last_number))
		rotate_and_swap(top, 'a');
	else if ((firt_number > second_number) && (second_number < last_number)
		&& (firt_number > last_number))
		rotate(top, 'a');
	else if ((firt_number < second_number) && (second_number > last_number)
		&& (firt_number < last_number))
		swap_and_rotate(top, 'a');
}

void	sort_4(t_list **top, t_list **topB)
{
	t_list	*aux;

	aux = smallest_number(top);
	while ((*top)->content != aux->content)
		rotate(top, 'a');
	push(top, topB, 'a');
	sort_3(top);
	push(topB, top, 'b');
}

void	sort_5(t_list **top, t_list **topB)
{
	t_list	*aux;
	int		shearch;

	aux = smallest_number(top);
	shearch = count_r(*top, aux->index);
	if (shearch > (ft_lstsize(*top) / 2))
		while ((*top)->content != aux->content)
			reverse_rotate(top, 'a');
	else
		while ((*top)->content != aux->content)
			rotate(top, 'a');
	push(top, topB, 'a');
	sort_4(top, topB);
	push(topB, top, 'b');
}

void	movement_the_list(t_list **head_list_a, t_list **head_list_b)
{
	if (is_ordered(*head_list_a) == -1)
	{
		if (ft_lstsize((*head_list_a)) == 2)
			sort_2(head_list_a);
		else if (ft_lstsize((*head_list_a)) == 3)
			sort_3(head_list_a);
		else if (ft_lstsize((*head_list_a)) == 4)
			sort_4(head_list_a, head_list_b);
		else if (ft_lstsize((*head_list_a)) == 5)
			sort_5(head_list_a, head_list_b);
		else if (ft_lstsize(*head_list_a) >= 6)
		{
			k_sort1(head_list_a, head_list_b, ft_lstsize(*head_list_a));
			k_sort2(head_list_a, head_list_b, ft_lstsize(*head_list_b));
		}
	}
}
