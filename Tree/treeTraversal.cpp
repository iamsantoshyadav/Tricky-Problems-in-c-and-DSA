#include<iostream>
#include<queue>
using namespace std ;

typedef struct node
{
    struct node *leftChild;
    int data;
    struct node *rightChild;
}node;
//##################################################### FUNCTION DECLERATION ####################################################
node *insertNode(node *root,int data);
node *getNewNoode(int data);
node *display(node *root);
node *levelOrderTraversal(node *root);
int main()
{
    node *first=NULL;
    first=insertNode(first,10);
    insertNode(first,5);
    insertNode(first,41);
    insertNode(first,5);
    insertNode(first,8);
    insertNode(first,87);
    insertNode(first,50);
    insertNode(first,90);
    insertNode(first,1);
    insertNode(first,6);
    cout<<"Inorder Traversal : ";
    display(first);
    cout<<"\nLevel Order Trversal : ";
    levelOrderTraversal(first);

}
node *insertNode(node *root,int data)
{
    if(root==NULL)
    {
        root=getNewNoode(data);
    }
    else
    {
        if(data<=root->data)
        {
            root->leftChild=insertNode(root->leftChild,data);
        }
        else if(data>root->data)
        {
            root->rightChild=insertNode(root->rightChild,data);
        }
    }
    return(root);

}
node *getNewNoode(int data)
{
    node *newNode;
    newNode=new node;
    newNode->leftChild=NULL;
    newNode->data=data;
    newNode->rightChild=NULL;
    return(newNode);
}
node *display(node *root)
{
    if(root==NULL)
    {
        return(0);
    }
    else
    {
        display(root->leftChild);
        cout<<root->data<<" ";
        display(root->rightChild);
    }
}
node *levelOrderTraversal(node *root)
{
    if(root==NULL)
    {
        return(0);
    }
    else
    {
        queue<node*> q;
        q.push(root);
        node *current;
        while(!q.empty())
        {
            current=q.front();
            cout<<current->data<<" ";
            if(current->leftChild!=NULL)
            {
                q.push(current->leftChild);
            }
            if(current->rightChild!=NULL)
            {
                q.push(current->rightChild);
            }
            q.pop();


        }

    }
}
