/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:55:33 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/21 13:49:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "get_next_line.h"

#define TAB1 (check.tab1)
#define TAB2 (check.tab2)
#define TAI1 (check.taille1)
#define TAI2 (check.taille2)

static int	ft_error(char *error, t_check check)
{
	if (TAB1)
		ft_memdel((void **)&TAB1);
	if (TAB2)
		ft_memdel((void **)&TAB2);
	ft_putendl(error);
	return (0);
}

static char	*checkdouble(t_check check)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < check.taille1)
	{
		while (j < check.taille1)
		{
			if (check.tab1[i] == check.tab1[j])
				return ("Error");
			j++;
		}
		j = ++i + 1;
	}
	return ("OK");
}

int			main(int argc, char **argv)
{
	t_check		check;
	int			ret;
	char		*order;

	check.taille2 = 0;
	if (argc == 1 || ft_strcmp(ft_check(argv, argc, &check), "OK") != 0 ||
	ft_strcmp(checkdouble(check), "OK") != 0)
		return (ft_error("Error", check));
	while ((ret = get_next_line(0, &order)) == 1)
	{
		ft_checker(order, &check);
		if (order[0] == 0)
			return (ft_error("error", check));
		ft_memdel((void **)&order);
	}
	if (order)
		ft_memdel((void **)&order);
	return (ft_error(ft_check_end(check), check));
}
