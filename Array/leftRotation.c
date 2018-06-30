#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int rotateLeft(int *array,int noElements);
void main()
{
    int array[5]={4,5,2,6,8},noElement=5,rotation=2,i;
    printf("BEFORE Rotation\n");
    for(i=0;i<noElement;i++)
    {
        printf("%d ",array[i]);
    }
    for(i=0;i<rotation;i++)
    {
        rotateLeft(array,noElement);
    }
    printf("\nAfter Rotation\n");
    for(i=0;i<noElement;i++)
    {
        printf("%d ",array[i]);
    }

}
int rotateLeft(int *array,int noElement)
{
    int temp,i;
    temp=array[0];
    for(i=0;i<noElement-1;i++)
    {
        array[i]=array[i+1];
    }
    array[noElement-1]=temp;

}
