#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
struct msg_buffer{
    long type ;
    char text[100];
} message ;

int main(){
    key_t key ;
    key = ftok("progfile",65);
    
    int msgid = msgget(key , 0666 | IPC_CREAT);
    message.type =1 ;
   
    msgrcv(msgid , &message ,sizeof(message) , 1,0);
    printf("Data recieved is %s",message.text);
    msgctl(msgid , IPC_RMID ,NULL);
    return 0;
}