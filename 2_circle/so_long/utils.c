/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/02 16:56:30 by silee			 #+#	#+#			 */
/*   Updated: 2022/06/02 19:52:51 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(int flag)
{
	if (flag == 1)
		write (2, "ERROR\nInvalid Argument.", 23);
	else if (flag == 2)
		write (2, "ERROR\nFile open failed.", 24);
	else if (flag == 3)
		write (2, "ERROR\nInvalid map.", 19);
	else if (flag == 4)
		write (2, "ERROR\nMap does not surrounded by wall.", 39);
	else if (flag == 5)
		write (2, "ERROR\nThere is no collectible in map.", 38);
	else if (flag == 6)
		write (2, "ERROR\nThere is no exit in map.", 31);
	else if (flag == 7)
		write (2, "ERROR\nThere is (no/multi) player in map.", 33);
	else
		write(2, "ERROR\nMalloc Failed.", 21);
	exit (1);
}

int	ft_strlen_wo_nl(char *str)
{
	int	len;

	if (str == 0)
		return (0);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}
