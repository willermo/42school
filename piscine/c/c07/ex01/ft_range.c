/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:58 by doriani           #+#    #+#             */
/*   Updated: 2023/03/07 16:50:01 by doriani          ###   ########.fr       */
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
