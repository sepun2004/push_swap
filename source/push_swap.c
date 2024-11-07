/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:08:48 by sepun             #+#    #+#             */
/*   Updated: 2024/07/10 13:08:48 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void  index_num(t_list **top)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = (*top);
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while(tmp2)
		{
			if (tmp1->content > tmp2->content)
				tmp1->index++;
			else
				tmp2->index++;
			tmp2 = tmp2->next;	
		}
		tmp1 = tmp1->next;
	}
	
}


char **check_error(char **argv)
{
	if (ft_check_chars(argv) == -1)
	{
		write(1, "Error\n", 6);
		return(NULL);
	}
	if (ft_check_string(argv) == -1)
	{
		write(1, "Error\n", 6);
		return(NULL);
	}
	if (ft_check_limits(argv) == -1)
	{
		write(1, "Error\n", 6);
		return(NULL);
	}
	return(argv);
} 

int main(int argc, char **argv)
{
	char **result;
	t_list *head_list_A = NULL;
	t_list *tmp_list = NULL;
	t_list *head_list_B = NULL;
	int i;
	int num;
	int j;

	i = 1;
	num = 0;
	if (argc < 2)
		return 0;
	while(argc)
	{
		j = 0;
		if (check_error(argv) == NULL)
			return 0;
		result = ft_split(argv[i], ' '); // "4  7  84" 4 "74 5 1"
		while (result[j] != NULL)
		{
			num = ft_atoi(result[j]);
			if (ft_check_duplicate(head_list_A, num) == -1)
				return 0;
			tmp_list = ft_lstnew(num);
			ft_lstadd_back(&head_list_A, tmp_list);
			if (tmp_list == NULL)
				free(tmp_list);
			j++;
		}
		i++;
		argc--;
		free_array(result);
	}
	index_num(&head_list_A);
	movement_the_list(&head_list_A, &head_list_B);
	free_list(head_list_A, head_list_B);
	return (0);
}


