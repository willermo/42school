/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:47:31 by doriani           #+#    #+#             */
/*   Updated: 2023/02/16 13:46:36 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *tab, int l, int r)
{
	int	v;
	int	i;
	int	j;

	if (r > l)
	{
		v = tab[r];
		i = l - 1;
		j = r;
		while (1)
		{
			while (tab[++i] < v)
				;
			while (tab[--j] > v)
				;
			if (i >= j)
				break ;
			swap_int(&tab[i], &tab[j]);
		}
		swap_int(&tab[i], &tab[r]);
		quicksort(tab, l, i - 1);
		quicksort(tab, i + 1, r);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (size > 1)
		quicksort(tab, 0, size - 1);
}
