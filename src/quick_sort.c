/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:30:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 02:08:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = partition(arr, start, end);
		quick_sort(arr, start, p - 1);
		quick_sort(arr, p + 1, end);
	}
}
