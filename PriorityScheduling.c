#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a ;
    *a = *b ; 
    *b = temp;
}

void PriorityOrder(int p[],int bt[] , int pri[],int n){
    int pos;
    for(int i=0;i<n;i++){
        pos = i ;
        for(int j=i+1;j<n;j++){
            if(pri[j]>pri[pos]){
                pos = j;
            }
            swap(&pri[i],&pri[pos]);
            swap(&p[i],&p[pos]);
            swap(&bt[i],&bt[pos]);
        }
    }
}

void findWaitingTime(int bt[],int wt[],int n){
    int service_time[n];
    service_time[0]=0;
    wt[0]=0;
    for(int i=1;i<n;i++){
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] ;
        if(wt[i] < 0 ){
            wt[i] = 0 ;
        }
    }
}

void findTurnAroundTime(int bt[] , int wt[] , int tat[] , int n){
    for(int i =0 ; i<n ;i++){
        tat[i] = wt[i] + bt[i] ; 
    }
}

float mean(int arr[],int n){
    float sum = 0;
    for(int i=0 ; i<n ;i++){
        sum += arr[i];
    }
    return (sum/n);
}

void findAvgTime(int p[] , int bt[] , int pri[] , int wt[] ,int tat[],int n){
    printf("Process  Burst Time  Priority  Waiting Time  Turn Around Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t %d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pri[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time : %f",mean(wt,n));
    printf("\nAverage Turn Around Time : %f",mean(tat,n));
}

int main(){
    int bt[5] = {3 ,5 ,7, 6 ,2};
    int p[5] = {1 ,2 ,3 ,4 ,5};
    int pri[5] = {2 ,0 ,1 , 1 ,2};
    int wt[5],tat[5],i,j,n = 5,total=0,pos,temp;
    PriorityOrder(p,bt,pri,n);
    findWaitingTime(bt,wt,n);
    findTurnAroundTime(bt,wt,tat,n);
    findAvgTime(p,bt,pri,wt,tat,n);
    return 0;
}

/*
OUTPUT
Process  Burst Time  Priority  Waiting Time  Turn Around Time
P1       3              2               0               3
P5       2              2               3               5
P4       6              1               5               11
P3       7              1               11              18
P2       5              0               18              23

Average Waiting Time : 7.400000
Average Turn Around Time : 12.000000
*/