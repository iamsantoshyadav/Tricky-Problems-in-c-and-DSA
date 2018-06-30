#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char mainstr[50],pattern[30];
    int i,j,lengthMain,lengthPatt;
    printf("Enter main string : ");
    gets(mainstr);
    printf("Enter Pattern which you have to match : ");
    scanf("%s",pattern);
    //printf("\nmain string = %d\tpattern = %d",strlen(mainstr),strlen(pattern));
    lengthMain=strlen(mainstr);
    lengthPatt=strlen(pattern);
    for(i=0;i<lengthMain;i++)
    {
        for(j=0;j<lengthPatt;j++)
        {
            if(mainstr[i+j]!=pattern[j])
            {
                break;
            }
        }
        if(j==lengthPatt)
        {
            printf("Pattern found at %d Index\n",i);
        }
    }


}
