#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int wait(int s)
{
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer Produces the item %d",x);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    x--;
    printf("\nConsumer consumes the item %d",x);
    mutex=signal(mutex);
}
int main()
{
    int n;
    printf("\n1.producer\n2.consumer\n3.exit");
    while(1)
    {
        printf("\nEnter your choice :");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            if((mutex==1)&&(empty!=0))
            producer();
            else
            printf("\nBuffer is full! :");
            break;

            case 2:
            if((mutex==1)&&(full!=0))
            consumer();
            else 
            printf("\nBuffer is empty! :");
            break;

            case 3:
            exit(0);
            break;

        }
    }
    return 0;
}

