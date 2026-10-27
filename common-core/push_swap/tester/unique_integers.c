/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_integers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 07:58:32 by doriani           #+#    #+#             */
/*   Updated: 2023/06/05 08:07:50 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define RANGE 5000

int	is_duplicate(int *array, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	init(int ac, char **av, int **numbers, int *n)
{
	if (ac != 2)
	{
		printf("Usage: ./unique_integers N\n");
		exit(EXIT_FAILURE);
	}
	*n = atoi(av[1]);
	if (*n <= 0)
	{
		printf("N must be a positive integer\n");
		exit(EXIT_FAILURE);
	}
	*numbers = (int *)malloc(*n * sizeof(int));
	if (*numbers == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	srand((unsigned)time(NULL));
}

int	main(int argc, char *argv[])
{
	int	count;
	int	num;
	int	i;
	int	n;
	int	*numbers;

	init(argc, argv, &numbers, &n);
	count = 0;
	while (count < n)
	{
		num = (rand() % RANGE) - RANGE / 2;
		if (!is_duplicate(numbers, num, count))
			numbers[count++] = num;
	}
	i = 0;
	while (i < n)
		printf("%d ", numbers[i++]);
	printf("\n");
	free(numbers);
	return (0);
}
