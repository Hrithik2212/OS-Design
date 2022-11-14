#include <stdio.h>

int main(){
    int n , m , s, pages ,frames ,pf=0;
    pages = 5;
    int refStr[] = {5,4,3,2,1};
    frames = 3 ;
    int temp[frames];
    for(m=0;m<frames;m++){
        temp[m] = -1 ;
    }
    for(m=0;m<pages;m++){
        s = 0; 
        for(n = 0;n<frames;n++){
            if (refStr[m]==temp[n]){
                s++;
                pf--;
            }
        }
        pf++;
        if(pf<=frames && s==0){
            temp[m] = refStr[m] ;
        }
        else if(s==0){
            temp[(pf-1)%frames] = refStr[m];
        }
        printf("\n");
        for(n=0;n<frames;n++){
            printf("%d\t",temp[n]);
        }
    }
    printf("\nTotal Page Faults :\t%d\n",pf);
    return 0;
}

/*
OUTPUT

5       -1      -1
5       4       -1
5       4       3
2       4       3
2       4       3
Total Page Faults :     4
*/