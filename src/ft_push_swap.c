/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:47:17 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/22 22:33:24 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define TAB1 (check->tab1)
#define TAB2 (check->tab2)
#define TAI1 (check->taille1)
#define TAI2 (check->taille2)

static int		ft_mediane(int *tab, int len)
{
	int *tmp;
	int i;

	i = 0;
	if (!(tmp = ft_intmal(len)))
		return (0);
	while (i < len)
	{
		tmp[i] = tab[i];
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			ft_swap(&tmp[i], &tmp[i + 1]);
			i = -1;
		}
		i++;
	}
	i = tmp[len / 2];
	//ft_memdel((void **)tmp);
	return (i);
}

static void		ft_push_swap(t_check *check, int len)
{
	int	mediane;
	int	i;
	int	count;

	mediane = ft_mediane(check->tab1, len);
	i = 0;
	count = 0;
	while (i < len)
	{
		if (check->tab1[0] < mediane)
			ft_write_order(check, "pb");
		else
		{
			ft_write_order(check, "ra");
			count++;
		}
		i++;
	}
	while (0 < count)
	{
		ft_write_order(check, "rra");
		count--;
	}
}

static void		ft_sort_b(t_check *check, int len)
{
	int i;

	i = 0;
	if (len <= 2)
	{
		if (TAB2[0] < TAB2[1] && len == 2)
			ft_write_order(check, "sb");
		if (len == 2)
			ft_write_order(check, "pa");
		ft_write_order(check, "pa");
	}
	else
	{
		while (i < len)
		{
			ft_write_order(check, "pa");
			i++;
		}
		ft_sort_a(check, len);
	}
}

void			ft_sort_a(t_check *check, int len)
{
	if (len == 2 && TAB1[0] > TAB1[1])
		ft_write_order(check, "sa");
	else if (len > 2)
	{
		ft_push_swap(check, len);
		ft_sort_a(check, len / 2 + len % 2);
		ft_sort_b(check, len / 2);
	}
}