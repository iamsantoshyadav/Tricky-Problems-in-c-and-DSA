#include<stdio.h>
#include<conio.h>
void main()
{
    int length,temp,i=0,j;
    char str[7]="Santosh";
    char *ss="santosh",*sa="santosh";
    length=(sizeof(str)/sizeof(str[0]));
    printf("Length is %d \n",length);
    j=length-1;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    printf("%s",str);
    if(ss==sa)
    {
        printf("Found");
    }
    else{
        printf("\nNotfound");
    }

}
