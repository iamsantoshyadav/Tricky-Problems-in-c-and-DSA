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
node *deleteNode(node *root,int data);
node *findMin(node *root);
node *preOrder(node *root);
node *postOrder(node *root);
node *levelOrder(node *root);
//##################################### FUNCTION DEFINITION #############################################################
void main()
{
    node *max;

    first=insert(first,10);
    first=insert(first,5);
    insert(first,41);
    insert(first,8);
    insert(first,6);
    insert(first,5);
    insert(first,87);
    insert(first,1);
    insert(first,50);
    insert(first,90);
    insert(first,89);
    insert(first,95);
    printf("Tree element : ");
    display(first);
    /*deleteNode(first,6);
    printf("\nafter deletion 6 : ");
    display(first);
    deleteNode(first,8);
    printf("\nafter deletion 8 : ");
    display(first);
    deleteNode(first,41);
    printf("\nafter deletion 41 : ");
    display(first);
   // printf("\nright of 87 is %d ",first->rightNode->rightNode->leftNode->data);
    *///deleteNode(first,87);
   // printf("\nafter deletion 87 : ");
    //display(first);
    //printf("\nright = %d left = %d",first->rightNode->rightNode->rightNode->data,first->rightNode->rightNode->leftNode->data);
    //deleteNode(first,87);
    //printf("\nAfter Deletion of 87 : ");
    printf("\nPre Order Traversl : ");
    preOrder(first);
    printf("\nPost Order Traversl : ");
    postOrder(first);




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
//##############################################################################################################################################
node *deleteNode(node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        root->leftNode=deleteNode(root->leftNode,data);
    }
    else if(data>root->data)
    {
        root->rightNode=deleteNode(root->rightNode,data);
    }
    else
    {
        if(root->leftNode==NULL&&root->rightNode==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->leftNode==NULL)
        {
            node *temp;
            temp=root->rightNode;
            free(root);
            root=temp;

        }
        else if(root->rightNode==NULL)
        {
            node *temp;
            temp=root->leftNode;
            free(root);
            root=temp;

        }
        else
        {
            node *minNode;
            minNode=findMin(root->rightNode);
            root->data=minNode->data;
            root->rightNode=deleteNode(root->rightNode,root->data);
        }
    }
    return(root);
}
node *findMin(node *root)
{

    node *min;
    min=root;
    printf("\n Root Data =  %d ",min->data);
    while(min->leftNode!=NULL)
    {
        min=min->leftNode;
    }
    return(min);
}
node *preOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}
node *postOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postOrder(root->leftNode);
        postOrder(root->rightNode);
        printf("%d ",root->data);
    }
}
node *levelOrder(node *root,node *left,node *right)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        printf("%d ",left->data);
        printf("%d ",right-data);
        levelOrder()
    }
}
