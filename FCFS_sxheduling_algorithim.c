#include <stdio.h>

void findWaitingTime(int p[],int bt[] , int wt[],int at[],int n){
    int service_time[n];
    service_time[0] = at[0] ;
    wt[0]= 0;
    for(int i=1;i<n;i++){
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i];
        if(wt[i]<0){
            wt[i] = 0;
        }
    }
}
void findWaitingTime(int p[],int bt[], int at[], int wt[],int n){
    int service_time[n] ;
    service_time[0] = at[0];
    wt[0] = 0 ;
    for(int i=1;i<n;i++){
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i] ;
        if (wt[i]<0){
            wt[i] = 0;
        }
    }
}
void findTurnAroundTime(int p[],int bt[] ,int wt[] , int tat[] ,int n){
    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
}
float mean(int arr[] , int n ){
    float sum = 0 ;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return (sum/(float)n);
}


void findAvgTime(int p[] , int bt[] ,int at[], int wt[] , int tat[] , int n){
        printf("Process  Arrival Time   Burst Time   Waiting Time  Turn Around Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }   
    printf("\nAverage Waiting Time : %f",mean(wt , n));
    printf("\nAverage Turn Around Time : %f",mean(tat , n));
}





int main(){
    int prs[] = {1, 2, 3};
    int bt[] = {5, 9, 6};
    int at[] = {0, 3, 6};
    int n = sizeof(prs)/sizeof(prs[0]);
    int wt[n] , tat[n];
    findWaitingTime(prs,bt,wt,at,n);
    findTurnAroundTime(prs,bt,wt,tat,n);
    findAvgTime(prs , bt ,at ,wt ,tat,n);
    return 0;
}
/*
OUTPUT
Process  Arrival Time   Burst Time   Waiting Time  Turn Around Time
P1              0               5               0               5
P2              3               9               2               11
P3              6               6               8               14

Average Waiting Time : 3.333333
Average Turn Around Time : 10.000000
*/