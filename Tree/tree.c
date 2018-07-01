#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *leftNode;
    int data;
    struct node *rightNode;
}node;
node *first=NULL;
//##################################### FUNCTION DECELARATION ##################################################################################
node *insert(node *root,int data);
node *display(node *start);
node *getnewNode(int data);
//##################################### FUNCTION DEFINITION #############################################################
void main()
{

    first=insert(first,10);
    first=insert(first,5);
    insert(first,41);
    insert(first,8);
    printf("Tree element : ");
    display(first);



}
node *insert(node *root,int data)
{
    if(root==NULL)
    {
        root=getnewNode(data);
    }
    else
    {
        if(data<=root->data)
        {
            root->leftNode=insert(root->leftNode,data);
        }
        else
        {
            root->rightNode=insert(root->rightNode,data);
        }
    }
    return(root);
}
node *display(node *start)
{
    node *addPointer;
    if(start==NULL)
    {
        return;
    }
    else
    {
        display(start->leftNode);
        printf("%d  ",start->data);
        display(start->rightNode);
    }
}
node *getnewNode(int data)
{
    node *newNode;
    newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->leftNode=NULL;
    newNode->rightNode=NULL;
    return(newNode);
}
