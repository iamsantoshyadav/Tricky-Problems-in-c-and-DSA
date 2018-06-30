#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    int noString,maxlength,i,j,k;
    char *temp,*large;
    printf("No. of String : ");
    scanf("%d",&noString);
    char **str=(char **)malloc(noString*sizeof(char *));
    printf("\nMaximum Length of the string :  ");
    scanf("%d",&maxlength);
    for(i=0;i<noString;i++)
    {
        str[i]=(char*)malloc(maxlength*sizeof(char));
    }

    for(i=0;i<noString;i++)
    {
        printf("Enter %d Name : ",i+1);
        scanf("%s",str[i]);
        printf("\n");
    }
    for(i=0;i<noString;i++)
    {
        large=str[0];
        for(j=1;j<noString;j++)
        {
            if(str[j][0]>large[0])
            {
               large=str[j];
            }
            else
            {
                if(str[j][0]==large[0]&&i!=j)
                {
                    k=1;
                    HERE :if((str[j][k]>=large[k])&&(str[j][k]!=NULL||large[k]))
                    {
                        if(str[j][k]==large[k])
                        {
                            k++;
                            goto HERE;
                        }
                        else
                        {
                           large=str[j];
                        }
                    }
                    else
                    {
                        str[j-1]=str[j];
                        str[j]=large;
                    }
                }
                else
                {
                    str[j-1]=str[j];
                    str[j]=large;
                }
            }
        }
    }
    printf("========SORTED DATA========\n\n");
    for(i=0;i<noString;i++)
    {
        puts(str[i]);
    }
}
