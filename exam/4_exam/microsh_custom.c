#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define CB "error: cd: bad arguments\n"
#define CN "error: cd: cannot change directory to "
#define FA "error: fatal\n"
#define EX "error: cannot execute "

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

//./microshell /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";"

int	main(int ac, char **av, char **ev)
{
	char	*cmd[500];
	pid_t	child[500];
	int		prev_in = 0;
	int		in = 0;
	int		out = 1;
	int		fd[2];
	int		cc = 0;
	int		pc = 0;
	int		i = 0;

// ./microshell /bin/ls "|" /usr/bin/grep microshell

	while (++i < ac)
	{
		cc = 0;
		//strcmp : 문자열이 동일하면 0 반환. 아니면 + or - 중 하나.

		//ac를 전부 돌지 않았고, 문자열 내에 ; 혹은 |이 존재하지 않는다면.
		// ; 혹은 | 이 존재한다면 반복문을 나가고서도, av[i]는 두 값중 하나일것.
		while (i < ac && (strcmp(av[i], ";") && strcmp(av[i], "|")))
		{
			// ; 과 | 이전의 값들을 cmd에 저장한다.
			cmd[cc] = av[i];
			cc++;
			i++;
			cmd[cc] = 0;
		}
		// cc = 0인 경우는 ; 혹은 | 이므로, 다음 문자열을 검사한다.
		if (cc == 0)
			continue ;
	
		// Pipe ( | ) 문자열 내 존재한다면. 첫번째부터 입력되진 않을듯
		if (i < ac && strcmp(av[i], "|") == 0)
		{
			if (pipe(fd) < 0)
			{
				write(2, FA, ft_strlen(FA));
				exit(1);
			}
			// 이전의 pipe의 값을 따로 저장..
			prev_in = fd[0];
			out = fd[1];
		}
		//cd인 경우
		if (strcmp(cmd[0], "cd") == 0)
		{
			if  ((cc != 2))
				write(2, CB, ft_strlen(CB));
			//chdir 실패시/
			if (chdir(cmd[1]) < 0 && cc == 2)
			{
				write(2, CN, ft_strlen(CN));
				write(2, cmd[1], ft_strlen(cmd[1]));
				write(2, "\n", 1);
			}
		}
		//실제 실행부.
		else
		{
			//child 배열에 각 process의 pid를 저장
			child[pc] = fork();
			if (child[pc] < 0)
			{
				write(2, FA, ft_strlen(FA));
				exit(0);
			}
			//자식 프로세스의 경우
			if (child[pc] == 0)
			{
				dup2(in, 0); // = dup2(in, STDIN_FILENO). stdin_fileno 가 in에서 읽어오도록 연결. 123줄 참고
				dup2(out, 1); // = dup2(out, STDOUT_FILENO). stdout_fileno 가 out에 쓰이도록 연결
				//선언시, in = 0, out = 1이었다.

				//처음 반복시 in =0.
				if (in != 0)
					close(in);
				if (prev_in != 0)
					close(prev_in);
				if (out != 1)
					close(out);
				//실행
				execve(cmd[0], cmd, ev);
				//실행 오류시.
				write(2, EX, ft_strlen(EX));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
			//부모프로세스의 경우
			// prev_in = fd[0];
			// out = fd[1];
			else
			{
				if (in != 0)
					close(in);
				if (out != 1)
					close(out);
				in = prev_in; // 기존의 데이터가 쓰여진 fd값을 in에 저장.
				pc++;
			}
			if (i >= ac || (i < ac && strcmp(av[i], ";") == 0))
			{
				while(pc)
				{
					waitpid(-1, 0, 0);
					pc--;
				}
				in = 0;
				prev_in = 0;
				out = 1;
			}
		}
	}
}
