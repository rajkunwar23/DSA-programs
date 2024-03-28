#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node*link;
};

struct node*createnode(int);
void push(struct node**,int);
int pop(struct node**);
int peek(struct node*);
void display(struct node*);

struct node*createnode(int data)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->num=data;
    newnode->link=NULL;

    return newnode;
};

void push(struct node**current,int data)
{
    struct node*temp;
    temp=createnode(data);

    if(temp==NULL)
    {
        puts("\n node not created");
        return;
    }
    else
    {
        if((*current)==NULL)
        {
            (*current)=temp;
        }
        else
        {
            temp->link=(*current);
            (*current)=temp;
        }
    }
}

int pop(struct node**current)
{
    struct node*temp;
    if((*current)==NULL)
    {
        puts("\n stack underflow");
        return;
    }
    else
    {
        temp=(*current);
        (*current)=temp->link;
        free(temp);
    }
}

int peek(struct node*current)
{
    int val;
    if(current==NULL)
    {
        puts("\n stack underflow");
        return;
    }
    else
    {
        val=(current)->num;
    }
    return val;
}

void display(struct node *current)
{
    if(current==NULL)
    {
        printf("\n stack underflow");
    }
    else
    {
        while(current!=NULL)
        {
            printf("%d\n",current->num);
            current=current->link;
        }
    }
}

int main()
{
    int data,choice;
    struct node*top=NULL;

    while(1)
    {
        printf("\n list of operations");
        printf("\n1]push");
        printf("\n2]pop");
        printf("\n3]peek");
        printf("\n4]display");
        printf("\n5]close");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\n enter the data:=");
                   scanf("%d",&data);
                   push(&top,data);
                   break;

            case 2:data=pop(&top);
                   printf("\n poped value:=%d",data);
                   break;

            case 3:peek(top);
                   printf("\n top value:=%d",data);
                   break;

            case 4:display(top);
                   break;

            case 5:exit(0);

            default:printf("\n make proper selection");
        }
    }
}
