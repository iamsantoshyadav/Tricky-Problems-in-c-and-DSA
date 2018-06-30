#include<stdio.h>
#include<conio.h>
int swap(char *str1,char *str2,char *temp);
void main()
{
    char *str1,*str2,*temp;
    str1="santosh";
    str2="Yadav";
    printf("Before swap : ");
    printf("\n 1st string : %s\n",str1);
    printf("2nd string %s\n",str2);
    swap(str1,str2,temp);

}
int swap(char *str1,char *str2,char *temp)
{
    temp=str1;
    str1=str2;
    str2=temp;
    printf("\n\nAfter swap : \n");
    printf("1st string %s\n",str1);
    printf("2nd string %s",str2);
}
