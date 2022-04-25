/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:46:17 by heom              #+#    #+#             */
/*   Updated: 2022/04/25 15:49:03 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_all
{
	int		**fd;
	long	proc_num;
	char	**env;
	char	**argv;
	// file1의 fd.
	int		rfd;
	// file2의 fd. 0이상의 값이므로 write로 봐야할듯
	int		wfd;
	char	**paths;
	char	**new_argv;
	pid_t	*pid;
}				t_all;

#endif
