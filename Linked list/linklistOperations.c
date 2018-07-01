#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *add;
}node;
//################################################################FNCTION DECLEARATION PART############################################################################

node *display(node *start);
node *insert(node *start,int data);
node *compareLinLists(node *firstNode,node *secondNode);
node *mergeTwoLinkedList(node *first,node *second,int data);
node *findmergePoint(node *first,node *second);
node *makeCycle();
node *detectLoop(node *loopNode);
node *getLoopAdress(node *loopNode);


//###################################################################FUNCTION DEFINECTION PART###################################################################
void main()
{
    node *first=NULL,*second=NULL;
    first=insert(first,1);
    insert(first,2);
    insert(first,3);
    insert(first,4);
    second=insert(second,7);
    insert(second,5);
    insert(second,4);
    insert(second,5);
    printf("First Node :");
    display(first);
    printf("\nSecond Node : ");
    display(second);
    compareLinLists(first,second);
    mergeTwoLinkedList(first,second,4);
    printf("After Merging \n");
    display(first);
    printf("\n");
    display(second);
    findmergePoint(first,second);
    makeCycle();
}
//################################################################################################################################################################################
node *insert(node *start,int data)
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
node *display(node *start)
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
node *compareLinLists(node *firstNode,node *secondNode)
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
node *mergeTwoLinkedList(node *first,node *second,int data)
{
    node *last,*sec;
    last=first;
    sec=second;
    while(last->add!=NULL)
    {
        last=last->add;
    }
    while(sec->add!=NULL)
    {
        if(sec->data==data)
        {
            printf("Found\n");
            last->add=sec;
            break;
        }
        sec=sec->add;
    }
}
//#########################################################################################################################################################################

node *findmergePoint(node *first,node *second)
{

    node *fir,*sec;
    int position=0;
    fir=first;
    sec=second;
    printf("\n");
    while(fir!=NULL)
    {
        position++;
        sec=second;
        while(sec!=NULL)
        {

            if(sec->add==fir->add)
            {
                printf("Found at %d position\n",position);
                goto HOME;
            }
            sec=sec->add;
        }
        fir=fir->add;
    }
   HOME: return;
}
node *makeCycle()
{
    node *cycle=NULL;
    node *position;
   cycle=insert(cycle,1);
    insert(cycle,2);
    insert(cycle,3);
    insert(cycle,4);
    insert(cycle,5);
    insert(cycle,6);
    insert(cycle,7);
    insert(cycle,8);
    printf("Before list is looped : ");
    display(cycle);
    position=cycle;
    while(cycle->add!=NULL)
    {
        if(cycle->data==3)
        {
            position=cycle->add;
        }
        cycle=cycle->add;
    }
    cycle->add=position;//<<<<<<<<<<----------Loop is created at 3 position
    detectLoop(cycle);
}
node *detectLoop(node *loopeNode)
{
    node *trot,*here,*loopAdd;
    trot=loopeNode;
    here=loopeNode;
    while(trot!=NULL&&here!=NULL)
    {
        if(trot==here)
        {
            printf("Loop Found\n");
            loopAdd=trot;
            break;
        }
        trot=trot->add;
        here=here->add->add;
    }
    trot=loopeNode;
    here=loopAdd;
    while(trot!=NULL&&here!=NULL)
    {
        if(trot==here)
        {
            printf("Loop found at key %d \n\n",trot->data);
            loopAdd=trot;
            break;
        }
        trot=trot->add;
        here=here->add;
    }
}
