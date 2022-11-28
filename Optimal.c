// #include <stdio.h>


// int main() { 
//     int m , n ,  pages ,frames , pf ,flag1 , flag2 , flag3 , pos ,max; 
//     int img[15] ;
//     int rs[] = {7,6,4,3,4,5,3,4,3,4,2,1};
//     pages  = sizeof(rs) / sizeof(rs[0]) ;
//     frames = 3; 
//     int temp[frames] ;
//     for(n=0;n<frames;n++){
//         temp[n] = -1 ;
//     }

//     for(m =0 ; m< pages ; m ++ ){
//         flag1 = flag2 = 0;
//         for(n=0;n<frames ; n ++){
//             if(temp[n] == rs[m]){
//                 flag1 = flag2 = 1 ;
//                 break ;
//             }
//         }

//         if(flag1==0){
//             for(n=0;n<frames;n++){
//                 if (temp[n]==-1){
//                     pf++;
//                     temp[n] = rs[m];
//                     flag2=1;
//                     break; 
//                 }
//             }
//         }

//         if( flag2 == 0){
//             flag3 = 0 ; 
//             for(n=0;n<frames;++n){
//                 img[n] = -1;
//                 for(int k=n+1 ; k<pages;k++){
//                     if(img[n] == rs[k]){
//                         img[n] = k;
//                         break;
//                     }
//                 }
//             }

//             for(n=0;n<frames;n++){
//                 if (img[n]==-1){
//                     pos = n;
//                     flag3 =1 ;
//                     break;
//                 }
//             }
//             if(flag3==0){
//                 max = img[0];
//                 pos =0;
//                 for(n=1;n<frames;n++){
//                     if(img[j]>max){
//                         max = tem
//                     }
//                 }
//             }
//         }
//     }



//     return 0 ;
// }


#include<stdio.h>

void optimal(int string[20],int n,int size)
{
    //Creating array for block storage
    int frames[n];
    //Initializing each block with -1
    for (int i=0;i<n;i++)
        frames[i]=-1;

    //Index to insert element
    int index=-1;

    //Counters
    int page_miss=0;
    int page_hits=0;

    //Pointer to indicate initially frames filled or not
    int full=0;

    //Traversing each symbol in fifo
    for (int i=0;i<size;i++)
    {
        int symbol=string[i];
        int flag=0;

        for(int j=0;j<n;j++)
        {
            if (symbol==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            printf("\nSymbol: %d  Frame: ",symbol);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
            page_hits+=1;
        }
        else
        {
            //Frames are still empty
            if (full==0)
            {
                index=(index+1)%n;
                frames[index]=symbol;
                page_miss+=1;
                printf("\nSymbol: %d  Frame: ",symbol);
                for (int j=0;j<n;j++)
                    printf("%d ",frames[j]);

                //Frames filled or not
                if (i==n-1)
                    full=1;
            }

            //Frames are full, now we can apply optimal page replacement
            else
            {
                //First find the index to replace with
                int pos=-1;
                int index=-1;

                //Traversing each symbol and checking their optimal possibility
                for(int j=0;j<n;j++)
                {
                    //Whether symbol in frame found or not in future cached frame
                    int found=0;
                    for (int k=i+1;k<size;k++)
                    {
                        //If symbol exists in cached string
                        if (frames[j]==string[k])
                        {
                            found=1;
                            if (pos<k)
                            {
                                pos=k;
                                index=j;
                            }
                            break;
                        } 
                    }
                    //Symbol does not exist in cached frame
                    if (found==0)
                    {
                        pos=size;
                        index=j;
                    }
                }

                //Now assign symbol in lru position
                frames[index]=symbol;

                printf("\nSymbol: %d  Frame: ",symbol);
                for (int j=0;j<n;j++)
                    printf("%d ",frames[j]);
            }
        }
    }
    printf("\nPage hits: %d",page_hits);
    printf("\nPage misses: %d",page_miss);
}

//Main function
int main(void)
{
    int string[]={2, 3, 4, 2, 1, 3, 7, 5, 4, 3};
    int no_frames=3;
    int size=sizeof(string)/sizeof(int);
    optimal(string,no_frames,size);
    return 0;
}