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
int main(){
  
   pid_t pid;
   int x=1;
   pid=fork();
   if(pid !=0)
   {
       printf("parent:x=%d\n",--x);
       exit(0);
       
   }else
   {
      printf("child:x=%d\n",++x);
       exit(0); 
   }

  return 0; //return success
}