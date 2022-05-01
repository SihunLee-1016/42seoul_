/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:00:26 by heom              #+#    #+#             */
/*   Updated: 2022/04/27 17:41:08 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char
	**get_paths(void)
{
	int		i;
	char	*s;

	i = 0;
	while (all()->env[i])
	{
		s = all()->env[i];
		if (s[0] == 'P' && s[1] == 'A' &&
			s[2] == 'T' && s[3] == 'H' &&
			s[4] == '=')
			return (px_split(&s[5], ':'));
		i++;
	}
	return (NULL);
}

int
	check_cmd(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (0);
		cmd++;
	}
	return (1);
}

char
	*try_execve_loop(char *raw_cmd)
{
	int		ret;
	char	*exec_path;
	int		i;

	ret = -1;
	all()->new_argv = px_split(raw_cmd, ' ');
	if (!(check_cmd(all()->new_argv[0])))
		return ("Invalid command");
	if (!(all()->paths = get_paths()))
		return ("PATH not specified");
	i = 0;
	while (ret == -1 && all()->paths[i])
	{
		exec_path = px_strjoin(all()->paths[i], "/", all()->new_argv[0]);
		ret = execve(exec_path, all()->new_argv, all()->env);
		i++;
	}
	return ("Invalid command");
}

//0과 cmd1, 1과 cmd2. "자식프로세스에서 돌아가는 함수"
void
	do_child(int id, char *raw_cmd)
{
	int		i;
	char	*msg;

	//0보다 크거나 같고 1보다 작을 때
	if (id >= 0 && id < all()->proc_num - 1)
	{
		//fd 0 0 -> read. STDIN이 fd 00이 가르키는 파일을 참조.
		dup2(all()->fd[id][0], STDIN_FILENO);
		// fd 1 1 -> write. STDOUT이 fd 11이 가르키는 파일 참조.
		dup2(all()->fd[id + 1][1], STDOUT_FILENO);
	}
	//두번째 커맨드의 경우.
	else
	{
		//fd 10, read 
		dup2(all()->fd[id][0], STDIN_FILENO);
		// file2의 fd. write.  
		dup2(all()->wfd, STDOUT_FILENO);
	}
	i = 0;
	while (i < all()->proc_num)
	{
		// STDIN_FILENO가 첫번 째 fd와 같은 파일을 참조할 수 있으므로
		// 이미 열려져 있는 것을 삭제해준다.
		// 00, 01, 10, 11
		close(all()->fd[i][0]);
		close(all()->fd[i][1]);
		i++;
	}
	msg = try_execve_loop(raw_cmd);
	write(1, "", 1);
	safe_exit(1, msg);
}

void
	fork_loop(void)
{
	int		i;

	i = 0;
	while (i < all()->proc_num)
	{
		//파이프는 이미 만들어진 상태.
		all()->pid[i] = fork();
		if (all()->pid[i] == -1)
			safe_exit(1, "fork error!\n");
		// "자식"프로세서에서 command 1부터 시작. 
		if (all()->pid[i] == 0)
			do_child(i, all()->argv[i + 2]);
		i++;
	}
}
