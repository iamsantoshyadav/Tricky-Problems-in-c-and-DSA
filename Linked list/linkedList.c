#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *add;
}node;
node *start=NULL;
int insertFront(int data);
int display();
void main()
{
    int n,data;
    while(1)
    {
        printf("1. Front\n");
        printf("2. display\n");
        printf("3> EXit\n");
        printf("4> Reverse\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&data);
                insertFront(data);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
                break;
            case 4:
                reverse();
                break;

            default :
                printf("Wrong Choice\n");


        }

    }

}
insertFront(int data)
{
    node *newNode;
    int i;
    newNode=(node*)malloc(sizeof(node));
    if(start==NULL)
    {
        newNode->data=data;
        newNode->add=NULL;
        start=newNode;

    }
    else
    {
        printf("\n");
        newNode->data=data;
        newNode->add=start;
        start=newNode;
    }
}
int display()
{
    int i;
    node *p;
    printf("\n");
    if(start==NULL)
    {
        printf("Linked List is Empty \n\n");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d  ",p->data);
            p=p->add;
        }
    }
}
int reverse()
{
    node *pre,*next,*current;
    if(start==NULL)
    {
        printf("Empety Linked list \n");
    }
    else
    {
        pre=NULL;
        next=NULL;
        current=start;
        while(current!=NULL)
        {
            next=current->add;
            current->add=pre;
            pre=current;
            current=next;
        }
        start=pre;
    }
    display();
}

