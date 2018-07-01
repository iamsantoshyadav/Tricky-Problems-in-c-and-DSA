#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *add;
}node;
//################################################################FNCTION DECLEARATION PART############################################################################
int *display(node *start);
int *insert(node *start,int data);
int *partition(int *start,int *end);
int *quickSort(int *start,int *end);

//###########################################################################################################################################################################

void main()
{
    node *list=NULL,*last;
    list=insert(list,5);
    insert(list,3);
    insert(list,16);
    insert(list,4);
    insert(list,7);
    printf("Befor sort : ");
    display(list);
    printf("\n");
    last=list;
    while(last->add!=NULL)
    {
        last=last->add;
    }
    quickSort(list,last);
    printf("After Sorting : ");
    display(list);
}
//################################################################################################################################################################################
int *insert(node *start,int data)
{
    node *newNode,*pre;
    newNode=(node*)malloc(sizeof(node));
    if(start==NULL)
    {
        newNode->data=data;
        newNode->add=NULL;
        start=newNode;
        return(start);
    }
    else
    {
        pre=start;
        while(pre->add!=NULL)
        {
            pre=pre->add;
        }
        newNode->data=data;
        newNode->add=NULL;
        pre->add=newNode;
    }
    return(start);
}
//#######################################################################################################################################################################################
int *display(node *start)
{
    node *adpointer;
    if(start==NULL)
    {
        printf("Empety List \n\n");
    }
    else
    {
        adpointer=start;
        while(adpointer!=NULL)
        {
            printf("%d  ",adpointer->data);
            adpointer=adpointer->add;
        }
    }
}
//#############################################################################################################################################################################################

int *partition(int *start,int *end)
{

    node *pivot=end,*first=start,*secLast;
    node *pindex=start;
    int temp;
    printf("start = %d\tEnd data = %d\n",first->data,pivot->data);
    while(first!=pivot&&pivot!=NULL)
    {
        if(first->data<=pivot->data)
        {
            temp=pindex->data;
            pindex->data=first->data;
            first->data=temp;
            secLast=pindex;
            pindex=pindex->add;
        }
        first=first->add;
    }
    temp=pindex->data;
    pindex->data=first->data;
    first->data=temp;

    return(secLast);
}
int *quickSort(int *start,int *last)
{
    node *seLast,*first=start,*end=last;
    node *nxt;
    if(first!=end)
    {
        seLast=partition(start,last);
        printf("Pindex Data = %d\n",seLast->data);
        quickSort(first,seLast);
        quickSort(seLast->add->add,end);

    }
    else
    {

        //quickSort(pindex->add->add,last);
    }


}
