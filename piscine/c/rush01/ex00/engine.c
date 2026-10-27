/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:34 by doriani           #+#    #+#             */
/*   Updated: 2023/02/28 21:29:42 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int	**get_permutations(void);
int	get_next_matrix(int dim, int **matrix, int **permutations, int *rows);
int	is_correct(int dim, int **matrix, int *rules);

void init_puzzle(int dim, int ***permutations, int **rows, int ***matrix)
{
	*permutations = get_permutations();
	*rows = (int *) calloc(dim, sizeof(int));
	*matrix = (int **) malloc(dim * sizeof(int *));
}

void	quit_puzzle(int dim, int *rules, int **permutations, int *rows, int **matrix)
{
	free(rules);
	for(int i = 0; i < dim; i++)
		free(permutations[i]);
	free(permutations);
	if (matrix)
		free(matrix);
	free(rows);
}

void	print_matrix(int **matrix, int dim);

int	**find_solution(int dim, int **matrix, int **permutations, int *rows, int *rules)
{
	time_t	start;
	time_t	end;

	start = time(NULL);
	while(get_next_matrix(dim, matrix, permutations, rows)) 
	{
		if (is_correct(dim, matrix, rules))
		{
			end = time(NULL);
			printf("Solution found in %d seconds.\n", (int) (end - start));
			return (matrix);
		}
	}
	end = time(NULL);
	printf("Time elapsed: %d seconds.\n", (int) (end - start));
	free(matrix);
	return (0);
}
