#include <stdio.h>
#include <stdlib.h>

struct node
{
int num;
struct node *leftchild;
struct node *rightchild;
};

struct node*createnode(int);
struct node*buildtree(struct node**,int);
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

struct node*buildtree(struct node**rptr,int data)
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
        printf("%d",current->num);
        inorder(current->rightchild);
    }
}

int treeheight(struct node*current)
{
    int leftheight,rightheight,maxheight;

    if(current==NULL)
    {
        puts("\n no tree");
        return;
    }
    leftheight=treeheight(current->leftchild);
    rightheight=treeheight(current->rightchild);
    if(leftheight>rightheight)
    {
        maxheight=leftheight+1;
    }
    else
    {
        maxheight=rightheight+1;
    }
    return maxheight;
}

int main()
{
    struct node *root=NULL;
    int num,choice,height;

    while(1)
    {
        printf("\n binary search tree operations:=");
        printf("\n 1]buildtree ");
        printf("\n 2]treeheight");
        printf("\n 3]inorder traversal");
        printf("\n 4]exit");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\n enter the data:=");
                   scanf("%d",&num);
                   buildtree(&root,num);
                   break;

            case 2:height=treeheight(root);
                   printf("tree height=%d",height);
                   break;

            case 3:inorder(root);
                   break;

            case 4:exit(0);

            default:printf("\n make proper selection");
        }
    }

}
