/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
/*fork_exec_wait.c*/
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char * argv[]){
  //arguments for ls, will run: ls  -l /bin                                                                                                                                  
  char * ls_args[3] = { "ls", "-l", NULL} ;
  pid_t c_pid, pid;
  int status;

  c_pid = fork();

  if (c_pid == 0){
    /* CHILD */

    printf("Child: executing ls\n");

    //execute ls                                                                                                                                                               
    execvp( ls_args[0], ls_args);
    //only get here if exec failed                                                                                                                                             
    perror("execve failed");
  }else if (c_pid > 0){
    /* PARENT */

    if( (pid = wait(&status)) < 0){
      perror("wait");
      _exit(1);
    }

    printf("Parent: finished\n");

  }else{
    perror("fork failed");
    _exit(1);
  }

  return 0; //return success
}