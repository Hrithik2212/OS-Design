#include <stdio.h>

void swap(int* a , int* b){
    int temp ;
    temp = *a;
    *a = *b ;
    *b = temp;
}

void findWaitingTime(int processes[],int bt[] , int wt[], int n){
        int service_time[n];
        service_time[0] = 0 ;
        wt[0] = 0 ;
        for(int i=1;i<n;i++){
            service_time[i] = service_time[i-1] + bt[i-1];
            wt[i] = service_time[i] ;
            if (wt[i]<0){
                wt[i] = 0;
            }
        }
}

void findTurnAroundTime(int processes[],int bt[],int wt[] ,int tat[]  , int n ){
        for(int i=0;i<n;i++){
            tat[i] = wt[i] + bt[i];
        }
}

float mean(int arr[],int n){
    int sum =0 ;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return ((float)sum/n);
}

void findAvgTime(int processes[] ,int bt[]  , int wt[] , int tat[] , int n ){
    printf("Process  Burst Time   Waiting Time  Turn Around Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n",processes[i],bt[i],wt[i],tat[i]);
    }
    printf("\n");
    printf("Average Waiting Time : %f\n",mean(wt,n));
    printf("Average Turn Around Time : %f\n",mean(tat,n));
}

void SJForder(int p[] , int bt[] , int n ){
    int pos , temp;
    for(int i=0;i<n;i++){
        pos = i;
        for(int j=i+1;j<n;j++){
            if(bt[j] < bt[pos]){
                pos = j;
            }
        swap(&bt[i],&bt[pos]);
        swap(&p[i],&p[pos]);
        }
    }
}

int main(){
    int bt[5] = {3 ,5 ,7, 6 ,2};
    int p[5] = {1 ,2,3,4,5};
    int wt[5],tat[5],i,j,n = 5,total=0,pos,temp;
    SJForder(p , bt ,n);
    findWaitingTime(p , bt , wt , n);
    findTurnAroundTime(p , bt ,wt ,tat ,n);
    findAvgTime(p , bt ,wt , tat , n );
    return 0;
}

/*
OUTPUT
Process  Burst Time   Waiting Time  Turn Around Time
P5              2               0               2
P1              3               2               5
P2              5               5               10
P4              6               10              16
P3              7               16              23

Average Waiting Time : 6.600000
Average Turn Around Time : 11.200000
*/