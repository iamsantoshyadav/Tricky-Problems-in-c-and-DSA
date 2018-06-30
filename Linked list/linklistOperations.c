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
int *compareLinLists(node *firstNode,node *secondNode);


//###################################################################FUNCTION DEFINECTION PART###################################################################
void main()
{
    node *first=NULL,*second=NULL;
    first=insert(first,1);
    insert(first,2);
    insert(first,3);
    insert(first,4);
    second=insert(second,1);
    insert(second,2);
    insert(second,3);
    insert(second,4);
    printf("First Node :");
    display(first);
    printf("\nSecond Node : ");
    display(second);
    compareLinLists(first,second);
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
int *compareLinLists(node *firstNode,node *secondNode)
{
    while(firstNode!=NULL&&secondNode!=NULL)
    {
        if(firstNode->data!=secondNode->data)
        {
            printf("\nList is Note Identical \n\n");
            break;
        }
        firstNode=firstNode->add;
        secondNode=secondNode->add;
    }
    if(firstNode==NULL&&secondNode==NULL)
    {
        printf("\nList is Identical\n\n");
    }
}

