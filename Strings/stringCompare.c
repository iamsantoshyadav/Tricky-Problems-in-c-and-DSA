#include<stdio.h>
#include<conio.h>
void main()
{
    char *str1="y",*str2="s";
    int dif;
    //dif=str1[0]-str2[0];
    //printf("Difference is %d \n",dif);
    if(str1[0]<str2[0])
    {
        printf("%s is greater\n",str2);
    }
    else
    {
        printf("%s is greater\n",str1);
    }
}
