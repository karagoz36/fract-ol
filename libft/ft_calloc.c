/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:44 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/05/24 18:12:42 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*allocated;

	if (n * size != 0 && n * size < size)
		return (NULL);
	allocated = (void *)malloc (n * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, n * size);
	return (allocated);
}
/*
int main(void)
{
//    int i = -1;
    char *array;
    char *array2;
    array2 = calloc (1, -3);
    array = ft_calloc (1, -3);
//    while (++i < 10)
//        printf("%d - %d\n", i, array[i]);
    free(array);
    free(array2);
    return (0);
}
*/
