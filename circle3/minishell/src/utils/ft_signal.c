/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:29:04 by heha              #+#    #+#             */
/*   Updated: 2022/07/08 14:40:27 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <sys/errno.h>
#include <string.h>
#include <signal.h>
#include "ft_utils.h"

static void	ft_sig_handler(int sig)
{
	if (SIGINT == sig)
	{
		ft_putendl_fd("minishell$ ", STDOUT_FILENO);
		if (rl_on_new_line() < 0)
			exit(EXIT_FAILURE);
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	ft_signal(int sig, void (*func)(int))
{
	extern int	errno;
	int			ret;

	if (SIG_ERR == signal(sig, func))
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putstr_fd("signal", STDERR_FILENO);
		ret = EXIT_FAILURE;
		if (errno)
		{
			ret = errno;
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(ret);
	}
}

void	ft_set_signal(t_signal mode)
{
	// 입력받을때
	if (SIG_IN_SHELL_READLINE == mode)
	{
		//ctrl c -> 다음줄로 넘긴다
		ft_signal(SIGINT, ft_sig_handler);
		// ctrl / -> 무시
		ft_signal(SIGQUIT, SIG_IGN);
	}
	//자식 생성하고, shell이 자식을 기다릴때
	else if (SIG_IN_SHELL_WAITING == mode)
	{
		//둘다 무시
		ft_signal(SIGINT, SIG_IGN);
		ft_signal(SIGQUIT, SIG_IGN);
	}
	//자식프로세스에서
	else if (SIG_IN_PROCESS == mode)
	{
		// 둘다 받아서 처리.
		ft_signal(SIGINT, SIG_DFL);
		ft_signal(SIGQUIT, SIG_DFL);
	}
	//히어독
	else
	{
		//ctrl c만 처리.
		ft_signal(SIGINT, SIG_DFL);
		ft_signal(SIGQUIT, SIG_IGN);
	}
}
