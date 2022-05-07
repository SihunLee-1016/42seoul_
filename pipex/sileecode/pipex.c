/* ************************************************************************** */
/*																			*/
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*														:::	  ::::::::   */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/26 16:38:42 by sihunlee		  #+#	#+#			 */
/*   Updated: 2022/05/01 17:42:37 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

void	cmd_start(char *cmd, char **envp)
{
	char	**commands;
	char	*path;

	commands = ft_split (cmd, ' ');
	if (idx_of_c(commands[0], '/') > -1)
		path = commands[0];
	else
		path = find_path (commands[0], envp);
	if (path != 0)
		execve (path, commands, envp);
	exit (127);
}

void	pipe_n_fork(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe (fd_pipe);
	pid = fork();
	if (pid)
	{
		close (fd_pipe[1]);
		dup2 (fd_pipe[0], STDIN);
		waitpid (pid, NULL, 0);
	}
	else
	{
		close (fd_pipe[0]);
		dup2 (fd_pipe[1], STDOUT);
		cmd_start (cmd, envp);
	}
}

int	ft_file_1(char *file1)
{
	if (access(file1, F_OK) == -1)
	{
		write (2, "No such file or directory: ", 27);
		ft_putstr_fd (file1, 1);
		write (1, "\n", 1);
		exit (1);
	}
	return (open (file1, O_RDONLY));
}

int	ft_file_2(char *file2)
{
	int	ret;

	ret = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ret == -1)
		exit (1);
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
		//STDIN으로 읽어오면 read_fd가 가르키고 있는 파일의 내용을 읽어옴
		dup2 (read_fd, STDIN);
		//STDOUT으로 write하면 write_fd가 가르키고 있는 파일에 출력함.
		dup2 (write_fd, STDOUT);
		pipe_n_fork (argv[2], envp);
		cmd_start(argv[3], envp);
		system("leaks pipex");
	}
	else
		write (STDERR, "number of Arguments are not valid\n", 35);
	return (0);
}
