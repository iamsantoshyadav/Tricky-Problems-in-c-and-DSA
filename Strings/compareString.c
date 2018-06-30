#include<stdio.h>
#include<conio.h>
void main()
{
    char *str1,*str2,*temp;
    int dif;
    str1="yadav";
    str2="santosh";

    printf("ASCI value of String 1  %d\n",str1);
    printf("ASCI value of String 2  %d\n",str2);
    dif=str1-str2;
    printf("Before sorted : %s %s\n",str1,str2);
    if(dif<0)
    {
        temp=str2;
        str2=str1;
        str1=temp;
    }
    printf("Afterrted %s %s",str1,str2);
}
