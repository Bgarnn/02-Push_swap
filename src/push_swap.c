/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:48 by kburalek          #+#    #+#             */
/*   Updated: 2023/08/03 14:49:49 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_clear(t_data *data)
{
	lst_clear(&data->a_top);
	lst_clear(&data->b_top);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	dup_check(t_data *data)
{
	t_node	*current;
	t_node	*loop;

	loop = data->a_top;
	while (loop)
	{
		current = loop->next;
		while (current)
		{
			if (current->value == loop->value)
				error_clear(data);
			current = current->next;
		}
		loop = loop->next;
	}
}

static void	ranking(t_data *data)
{
	int		i;
	t_node	*loop;
	t_node	*current;

	loop = data->a_top;
	while (loop)
	{
		current = data->a_top;
		i = 1;
		while (current)
		{
			if (current->value < loop->value)
				i++;
			current = current->next;
		}
		loop->rank = i;
		loop = loop->next;
	}
}

static void	var_init(t_data *data)
{
	data->a_top = NULL;
	data->b_top = NULL;
	data->size_a = 0;
	data->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit(0);
	var_init(&data);
	input_get(&data, argv);
	dup_check(&data);
	ranking(&data);
	if (!lst_sorted(&data))
		sort_check(&data);
	lst_clear(&data.a_top);
	lst_clear(&data.b_top);
	return (0);
}
