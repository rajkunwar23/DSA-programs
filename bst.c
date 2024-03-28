#include <stdio.h>
#include <stdlib.h>

struct node
{
int num;
struct node *leftchild;
struct node *rightchild;
};

struct node* createnode(int);
struct node* buildtree(struct node**,int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);

struct node*createnode(int data)
{
    struct node*newnode;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->num=data;
    newnode->rightchild=NULL;
    newnode->leftchild=NULL;

    return newnode;
};

struct node *buildtree(struct node**rptr,int data)
{
    struct node*current,*newnode;
    newnode=createnode(data);

    current=(*rptr);
    if((*rptr)==NULL)
    {
        (*rptr)=newnode;
    }
    else
    {
        if((*rptr)->num>data)
        {
            current->leftchild=buildtree(&(current->leftchild),data);
        }
        else
        {
            current->rightchild=buildtree(&(current->rightchild),data);
        }
    }
    return (*rptr);
};

void preorder(struct node*current)
{
    if(current==NULL)
    {
        puts("\n no tree");
        return;
    }
    else
    {
        printf("%d\t",current->num);
        preorder(current->leftchild);
        preorder(current->rightchild);
    }
}

void inorder(struct node*current)
{
    if(current==NULL)
    {
        puts("\n no tree");
        return;
    }
    else
    {
        inorder(current->leftchild);
        printf("%d\t",current->num);
        inorder(current->rightchild);
    }
}

void postorder(struct node*current)
{
    if(current==NULL)
    {
        puts("\n no tree");
        return;
    }
    else
    {
        postorder(current->leftchild);
        postorder(current->rightchild);
        printf("%d\t",current->num);
    }
}

int main()
{
    struct node *root=NULL;
    int num,choice;

    while(1)
    {
        printf("\n binary search tree operations:=");
        printf("\n 1]buildtree ");
        printf("\n 2] preorder traversal");
        printf("\n 3]inorder traversal");
        printf("\n 4]postorder traversal");
        printf("\n 5]exit");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\n enter the data:=");
                   scanf("%d",&num);
                   buildtree(&root,num);
                   break;

            case 2:preorder(root);
                   break;

            case 3:inorder(root);
                   break;

            case 4:postorder(root);
                   break;

            case 5:exit(0);

            default:printf("\n make proper selection");
        }
    }

}
