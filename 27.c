#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// Execute ls -Rl
	// Using execl, execlp, execle, execv, execvp
	char *path = "/bin/ls";
	char *arg1 = "-Rl";
	int output;
	//output = execl(path,path,arg1,NULL);
	char *programName = "ls";
	//output = execlp (programName,programName,arg1,NULL);
	char *env[] = {"HOSTNAME=localhost","PORT=8080",NULL};
	output = execle(path,path,arg1,NULL,env);
	//char *args[] = {path , "-Rl" , NULL};
	//output = execv(path,args);
	//char *args[] = {programName,"-Rl",NULL};
	//output = execvp(programName,args);
	if(output == -1)
		printf("\n execl error!! \n");
	return 0;
}
