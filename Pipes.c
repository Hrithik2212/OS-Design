#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 

int main(){
    char* str = "Hello World"; 
    int p[2] ,int ;
    pipe(p);
    char buff[25];
    if(fork()==1){
        printf("Child is executing\n");
        write(p[1],str,12);
    }
    else{
        printf("parent is executing\n");
        read(p[0],buff,12);
        printf("%s",buff);
    }
}

