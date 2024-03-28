#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node*link;
};

struct node*createnode(int);
void enqueue(struct node**,struct node**,int);
int dequeue(struct node**,struct node**);
void display(struct node*,struct node*);

struct node*createnode(int data)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->num=data;
    newnode->link=NULL;

    return newnode;
};

void enqueue(struct node**front,struct node**rear,int data)
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
        if((*front)==NULL&&(*rear)==NULL)
        {
            (*front)=temp;
            (*rear)=temp;
        }
        else
        {
            (*rear)->link=temp;
            (*rear)=temp;
        }
    }
}

int dequeue(struct node**front,struct node**rear)
{
    struct node*temp;
    int val;
    if((*front)==NULL||(*rear)==NULL)
    {
        puts("\n queue underflow");
        return;
    }
    else
    {
        temp=(*front);
        val=(*front)->num;

        if((*front)==(*rear))
        {
            (*front)=NULL;
            (*rear)=NULL;
        }
        else
        {
            (*front)=temp->link;
            free(temp);
        }
        return val;

    }
}

void display(struct node *front,struct node*rear)
{
    struct node *current;
    if(front==NULL||rear==NULL)
    {
        printf("\n queue underflow");
    }
    else
    {
        current=front;
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
    struct node*front=NULL;
    struct node*rear=NULL;

    while(1)
    {
        printf("\n list of operations");
        printf("\n1]enqueue");
        printf("\n2]dequeue");
        printf("\n3]display");
        printf("\n4]close");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\n enter the data:=");
                   scanf("%d",&data);
                   enqueue(&front,&rear,data);
                   break;

            case 2:data=dequeue(&front,&rear);
                   printf("\n deleted value:=%d",data);
                   break;

            case 3:display(front,rear);
                   break;

            case 4:exit(0);

            default:printf("\n make proper selection");
        }
    }
}
