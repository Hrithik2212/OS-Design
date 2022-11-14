#include <stdio.h>
const int n = 5 , m= 3; 
int main(){
    int  i ,j ,k;
    int alloc[5][3] = { { 0, 1, 0 }, 
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 },
                        { 0, 0, 2 } };
    int max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 },
                      { 4, 3, 3 } };

    int avail[3] = { 3, 3, 2};
    int f[n] , ans[n] , ind ;
    for (k=0;k<n;k++){
        f[k] = 0;
    }
    // Need Matrix 
    int need[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j] ;
        }
    }
    int y = 0 ;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if (f[i] == 0){
                int flag = 0 ;
                for(j=0 ; j<m ; j++){
                    if(need[i][j]>avail[j]){
                        flag = 1;
                        break; 
                    }
                }
                if (flag == 0){
                    ans[ind++] = i;
                    for(y=0;y<m;y++){
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag = 0;
            printf("The following sequence is not a safe sequence\n");
            break ;
        }
    }
    if(flag==1){
            printf("The following sequence is the SAFE Sequenece :\n");
            for(int i=0;i<n;i++){
                printf("P%d->",ans[i]);
            }
        }
    return 0;
}

/*
OUTPUT
The following sequenece is the safe sequence
P1-> P3-> P4-> P0-> P2-> 
*/