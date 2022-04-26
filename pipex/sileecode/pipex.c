/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:38:42 by sihunlee          #+#    #+#             */
/*   Updated: 2022/04/26 17:34:07 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main(int argc, char **argv, char **envp)
{
    int read_fd;
    int write_fd;
    int cmd1_fd[2];
    int cmd2_fd[2];
    if (argc == 5)
    {
        read_fd = ft_file_1(argv[1]);
        write_fd = ft_file_2(argv[4]);

    }
    else
        ft_make_exit(2,"number of Arguments are not valid");

}

int ft_file_1(char *file1)
{
    if (access(file1, F_OK) == -1)
    {
        write(2, "No such file or directory\n",28);
        ft_make_exit(2, "ERROR");
    }
    else
        return (open(file1,O_RDONLY));
}

int ft_file_2(char *file2)
{
    int ret;

    ret = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (ret == -1)
        ft_make_exit(2, "ERROR");
    return (ret);
}


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
    write(fd,"\n",1);
}

void ft_make_exit(int status, char *message)
{
    if (message)
        ft_putstr(message, status);
    exit(status);
}