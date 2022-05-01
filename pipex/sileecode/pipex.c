/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/26 16:38:42 by sihunlee		  #+#	#+#			 */
/*   Updated: 2022/05/01 17:42:37 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

int	cmd_start(char *cmd, char **envp)
{
	char	**commands;
	char	*path;

	commands = ft_split (cmd, ' ');
	path = find_path (cmd, envp);
	execve (path, commands, envp);
	exit (127);
}

void	pipe_n_fork(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe (fd_pipe);
	pid = fork();
	if (pid > 0)
	{
		close (fd_pipe[1]);
		dup2 (fd_pipe[0], STDIN_FILENO);
		waitpid (pid, NULL, 0);
	}
	else if (pid == 0)
	{
		close (fd_pipe[0]);
		dup2 (fd_pipe[1], STDOUT_FILENO);
		cmd_start (cmd, envp);
	}
	else
		return ;
}

int	ft_file_1(char *file1)
{
	if (access(file1, F_OK) == -1)
	{
		write (2, "No such file or directory\n", 28);
		ft_make_exit (2, "ERROR");
	}
	return (open (file1, O_RDONLY));
}

int	ft_file_2(char *file2)
{
	int	ret;

	ret = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ret == -1)
		ft_make_exit (2, "ERROR");
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	int	read_fd;
	int	write_fd;

	if (argc == 5)
	{
		read_fd = ft_file_1 (argv[1]);
		write_fd = ft_file_2 (argv[4]);
		dup2 (read_fd, STDIN_FILENO);
		dup2 (write_fd, STDOUT_FILENO);
		pipe_n_fork (argv[2], envp);
		cmd_start(argv[3],envp);
	}
	else
		ft_make_exit (2, "number of Arguments are not valid");
	return (0);
}
