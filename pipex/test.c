#include <stdio.h>
#include <unistd.h>    
#include <stdlib.h>

#define BUFSIZE 30
int main(void)
{
    int fd[2];
    char buffer[BUFSIZE];
    int pid;
    int state;

    state = pipe(fd);
    if (state == -1)
    {
        puts("error");
        exit(1);
    }
    printf("get pid : %d\n",(int)getpid());
    printf("pid : %d\n",pid);

    pid = fork();
    //부모 프로세스에서 fork를 뜨게되면 0이 아닌 값이 들어감.
    //추후에 자식 프로세스로 들어갔을 때 pid값은 0이되게된다.
    printf("get pid : %d\n",(int)getpid());
    printf("pid : %d\n",pid);

    if (pid == -1)
    {
        puts("erorr");
        exit (1);
    }
    
    else if(pid == 0)
    {
        printf("자식\n");
        write(fd[1],"Success\n",9);
        //fd[1]에 쓴다. 부모 프로세스에서 fd[0](출력)을 통해 버퍼에 저장시킨다.
        // 부0 - 자1 or 부1 - 자0 로 파이프 통신이 가능. 
        //1에 쓰고 0으로 읽는다.
        printf("자식프로세서에서 출력됨");
    }

    else{

        printf("부모\n\n");
        //버퍼에 읽어옴.
        read(fd[0], buffer, BUFSIZE);
        //read에서 fd[0]을 통해 자식프로세스로 넘어감?
        puts("buffer is :\n");
        puts("result:");
        puts(buffer);
    }
    return (0);
}

//fork 이후 자식 프로세스 시작. 
// 자식 ->부모인가?