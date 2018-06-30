#include<stdio.h>
#include<conio.h>
void main()
{
    unsigned int array[4000];
    unsigned int queries[3][3]={{1,5,3},
                        {4,8,7},
                        {6,9,1}
                        };
    int i,j,row=3,col=3,n=4000,k;
    for(i=0;i<n;i++)
    {
        array[i]=0;
    }

    for(i=0;i<row;i++)
    {
        for(j=(queries[i][0]-1);j<=(queries[i][col-2]-1);j++)
        {
            array[j]=array[j]+queries[i][col-1];
        }
        for(k=0;k<n;k++)
        {
            printf("%d  ",array[k]);
        }
        printf("\n");

    }
    unsigned int max=0;
    for(i=0;i<n;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    printf("Maximum is %d \n",max);
}
