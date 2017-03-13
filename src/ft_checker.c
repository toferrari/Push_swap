/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:42:21 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/13 17:02:15 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

char			*ft_check_end(t_check check)
{
	int i;

	i = 0;
	if (check.taille2 > 0)
		return ("KO");
	while (i < check.taille1 - 1)
	{
		if (check.tab1[i] > check.tab1[i + 1])
			return ("KO");
		i++;
	}
	return ("\nOK");
}

void			ft_checker(char *order, t_check *check)
{
	if (ft_strcmp(order, "sa") == 0)
		ft_swap(&check->tab1, check->taille1);
	else if (ft_strcmp(order, "ss") == 0)
		ft_swap2(check);
	else if (ft_strcmp(order, "pb") == 0)
		ft_push(check, 'b');
	else if (ft_strcmp(order, "pa") == 0)
		ft_push(check, 'a');
	else if (ft_strcmp(order, "ra") == 0)
		ft_rotate(&check->tab1, check->taille1);
	else if (ft_strcmp(order, "rr") == 0)
		ft_rotate2(check);
	else if (ft_strcmp(order, "rra") == 0)
		ft_rotate_reverse(&check->tab1, check->taille1);
	else if (ft_strcmp(order, "rrr") == 0)
		ft_rotate_reverse2(check);
}