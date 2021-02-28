#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t ret;
	printf("welcome...pid=%d\n",getpid());
    char p[100]="ls",q[100],r[100]="-l",s[100],t[100];
     printf("enter one command\n");
       gets(p);
       gets(r);
	   gets(s);
	   gets(t);
	   	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		printf("child-1-hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		int k=execlp(strcpy(q,p), strcpy(q,p),NULL);
		if(k<0)
		{
            printf("\nerror\n");
			perror("execv");
			exit(1);
		}
	}
	else		//ret>0
	{
		printf("parent--hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
				int ret1=fork();
		if(ret1==0)
		{
		printf("child-2-hello,pid=%d,ppid=%d\n",
				getpid(),getppid());
		int k=execlp(strcpy(q,r), strcpy(q,r),NULL);
		if(k<0)
		{
            printf("\nerror\n");
			perror("execv");
			exit(1);
			}
		}
		else
		{
			if(fork()==0)
			{
				int k=execlp(strcpy(q,s), strcpy(q,s),NULL);
				if(k<0)
				{
            		printf("\nerror\n");
					perror("execv");
					exit(1);
				}
			}
			else{
				if(fork()==0)
				{
					int k=execlp(strcpy(q,t), strcpy(q,t),NULL);
				if(k<0)
				{
            		printf("\nerror\n");
					perror("execv");
					exit(1);
				}
				}
				else{
					printf("\n4th ccommand\n");
				}
				printf("\n3rd command\n");
			}
		}
		}
	printf("Thank you..pid=%d\n",getpid());
	return 0;
}
