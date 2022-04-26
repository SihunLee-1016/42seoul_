#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 
int main(void)
{
    int fd[2];
	int pid;
	int *staticloc;
	int i = 0;
	char buffer[30];

    pipe(fd);
	pid = fork();
	wait(staticloc);
	if (staticloc > 0)
		printf("SUCCEXIT\n");
	if (pid == 0)
	{
		printf ("bf child fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
		close(fd[0]);
		// close(fd[1]);
		write(fd[1],"hello",5);
		// read(fd[0],buffer,30);
		// printf("buffer : %s\n",buffer);
		// printf ("af child fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
		return(1);
	}
	else
	{
		printf ("parent fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
		// write(fd[1],"world",5);
		read(fd[0],buffer,30);
		printf("buffer : %s\n",buffer);

	}

}
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h> 
// int main(void)
// {
//     int fd[2];
// 	int pid;
// 	int *staticloc;
// 	int i = 0;
// 	char buffer[30];

//     pipe(fd);
// 	pid = fork();
// 	wait(staticloc);
// 	if (staticloc > 0)
// 		printf("SUCCEXIT\n");
// 	if (pid == 0)
// 	{
// 		printf ("bf child fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
// 		close(fd[0]);
// 		// close(fd[1]);
// 		write(fd[1],"hello",5);
// 		// read(fd[0],buffer,30);
// 		// printf("buffer : %s\n",buffer);
// 		// printf ("af child fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
// 		return(1);
// 	}
// 	else
// 	{
// 		printf ("parent fd[0] :%d  fd[1] : %d\n",fd[0],fd[1]);
// 		// write(fd[1],"world",5);
// 		read(fd[0],buffer,30);
// 		printf("buffer : %s\n",buffer);

// 	}

// }