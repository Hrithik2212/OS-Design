#include <stdio.h>

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

void RRS(int p[],int bt[] ,int n ,int tq ){
    int wt[n],tat[n] ,rem_bt[n] , flag , t = 0;
    for(int i=0;i<n;i++) rem_bt[i] = bt[i] ;

    while(1){
        flag = 1 ;
        for(int i=0;i<n;i++){
            if (rem_bt[i]>0){
                flag = 0;
                if (rem_bt[i]>tq){
                    t+=tq;
                    rem_bt[i] -= tq;
                }
                else{
                    t+=rem_bt[i];
                    wt[i] = t - bt[i] ;
                    tat[i] = t;
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag==1) break;
    }
    findAvgTime(p,bt,wt,tat,n);
}


int main(){
    int bt[5] = {3 ,5 ,7, 6 ,2};
    int p[5] = {1 ,2 ,3 ,4 ,5 };
    int at[5] = {0 ,1 ,3 ,4 ,5 };
    int n = 5 , tq = 2;;
    RRS(p,bt,n,tq);
    return 0;
}


/*
Process  Burst Time   Waiting Time  Turn Around Time
P1              3               8               11
P2              5               13              18
P3              7               16              23
P4              6               16              22
P5              2               8               10

Average Waiting Time : 12.200000
Average Turn Around Time : 16.799999
*/