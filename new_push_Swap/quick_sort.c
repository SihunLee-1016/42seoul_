/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   quick_sort.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/08 16:48:13 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/11 13:22:25 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int dataset[], int left, int right)
{
	int	first;
	int	pivot;

	first = left;
	pivot = dataset[first];
	left += 1;
	while (left <= right)
	{
		while (dataset[left] <= pivot && left < right)
			left++;
		while (dataset[right] > pivot && left <= right)
			right--;
		if (left < right)
			swap (&dataset[left], &dataset[right]);
		else
			break ;
	}
	swap (&dataset[first], &dataset[right]);
	return (right);
}

void	quick_sort(int dataset[], int left, int right)
{
	int	idx;

	if (left < right)
	{
		idx = partition (dataset, left, right);
		quick_sort (dataset, left, idx - 1);
		quick_sort (dataset, idx + 1, right);
	}
}
