/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:52:34 by heha              #+#    #+#             */
/*   Updated: 2022/07/08 13:07:02 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	ft_getflag(t_token tokentype)
{
	if (TK_IRD == tokentype)
		return (OPEN_READ);
	else if (TK_HRD == tokentype)
		return (OPEN_HEREDOC);
	else if (TK_ORD == tokentype)
		return (OPEN_WRITE_TRUNC);
	else
		return (OPEN_WRITE_APPEND);
}

static void	ft_fileopen(const t_redir *redir, int *backupfd)
{
	int		tmp;

	if (redir->type != TK_HRD)
	{
		tmp = ft_open(redir->filename, ft_getflag(redir->type));
		// 기존의 것이 존재하지 않으면 (fdout== -1이면 현재의 것이 최신으 ㅣ것이니.)
		if (*backupfd != STDIN_FILENO && *backupfd != -1)
			close(*backupfd);
		*backupfd = tmp;
		free(redir->filename);
		if (tmp < 0)
			exit(EXIT_FAILURE);
	}
	else
		free(redir->filename);
}

void	ft_process_redir(t_queue *redirs, int pipein, int pipeout)
{
	t_redir	*redir;
	int		fdout;
	int		fdin;

	fdout = -1;
	fdin = pipein;
	if (redirs)
	{
		while (!ft_queue_empty(redirs))
		{
			redir = (t_redir *)ft_queue_front(redirs);
			if (TK_ORD == redir->type || TK_ARD == redir->type)
				ft_fileopen(redir, &fdout);
			else
				ft_fileopen(redir, &fdin);
			ft_queue_pop(redirs);
		}
	}
	// ORD가 존재한다면 next pipe로 넘겨주지 않고 파일에 직접적으로 쏴줘야 하므로 닫아준다.
	if (-1 != fdout && STDOUT_FILENO != pipeout)
		close(pipeout);
	if (-1 == fdout)
		ft_dup2(pipeout, STDOUT_FILENO);
	else
		ft_dup2(fdout, STDOUT_FILENO);
	ft_dup2(fdin, STDIN_FILENO);
}
