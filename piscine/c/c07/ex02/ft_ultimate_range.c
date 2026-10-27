/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:21:39 by doriani           #+#    #+#             */
/*   Updated: 2023/03/08 13:32:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;

	if (min >= max)
		return (0);
	range = (int *) malloc((max - min) * sizeof(int));
	while (min <= --max)
		range[max - min] = max;
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (!*range)
		return (0);
	return (max - min);
}
