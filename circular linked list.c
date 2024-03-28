#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node*next;
};

struct node *createnode(int);
void add_at_begin(struct node **,struct node**,int);
void add_at_end(struct node **,struct node**,int);
void add_at_mid(struct node **,struct node **,int,int);
void del_at_begin(struct node **,struct node **);
void del_at_end(struct node **,struct node **);
void del_at_mid(struct node **,struct node **,int);
void node_traversal(struct node*);

struct node*createnode(int data)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

        newnode->num=data;
        newnode->next=NULL;

    return newnode;
};

void add_at_begin(struct node **start,struct node **end,int data)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=createnode(data);
    if((*start)==NULL)
    {
        (*start)=temp;
        (*end)=temp;
        (*end)->next=(*start);
    }
    else
        {
            temp->next=(*start);
            (*start)=temp;
            (*end)->next=(*start);
        }
}

void add_at_end(struct node**start,struct node **end,int data)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=createnode(data);
    if((*start)==NULL)
    {
        (*start)=temp;
        (*end)=temp;
        (*end)->next=(*start);
    }
    else
        {
            (*end)->next=temp;
            (*end)=temp;
            (*end)->next=(*start);
        }
}

void add_at_mid(struct node **start,struct node **end,int data,int position)
{
    struct node*temp,*current;
    int cnt;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=createnode(data);
    if((*start)==NULL)
    {
        (*start)=temp;
        (*end)=temp;
        (*end)->next=(*start);
    }
    else
    {
        current=(*start);
        for(cnt=0;cnt<position-1;cnt++)
        {
            if((*start)->next==NULL)
            {
                puts("\n insufficient nodes");
                return;
            }
            else
            {
                current=current->next;
            }
            temp->next=current->next;
            current->next=temp;
        }
    }
}

void del_at_begin(struct node **start,struct node **end)
{
    struct node*temp;

    if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        temp=(*start);
        (*start)=temp->next;
        (*end)->next=(*start);
        free(temp);
    }
}

void del_at_end(struct node**start,struct node**end)
{
    struct node*temp,*current;

    if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=(*start);
        while(current->next!=(*end))
        {
            current=current->next;
        }
        temp=current->next;
        (*end)=current;
        (*end)->next=(*start);
        free(temp);
    }
}

void del_at_mid(struct node**start,struct node **end,int position)
{
    struct node*previous,*current;
    int cnt;

    if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
        {
            current=(*start);
    for(cnt=0;cnt<position-1;++cnt)
    {
        if(current==(*end))
        {
            puts("\n insufficient nodes");
            return;
        }
        else
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        free(current);
    }
        }
}

int main()
{
    int data,choice,position;
    struct node*start=NULL;
    struct node*end=NULL;

    while(1)
    {
        printf("\n list of operations:=");
        printf("\n1]add at begin");
        printf("\n2]add at end");
        printf("\n3]add at mid");
        printf("\n4]del at begin");
        printf("\n5]del at end");
        printf("\n6]del at mid");
        printf("\n7]node traversal");
        printf("\n8]close");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("\n enter the data:=");
                   scanf("%d",&data);
                   add_at_begin(&start,&end,data);
                   break;

            case 2:printf("\n enter the data:=");
                   scanf("%d",&data);
                   add_at_end(&start,&end,data);
                   break;

            case 3:printf("\n enter the data:=");
                   scanf("%d",&data);
                   printf("\n enter the position:=");
                   scanf("%d",&position);
                   add_at_mid(&start,&end,data,position);
                   break;

            case 4:del_at_begin(&start,&end);
                   break;

            case 5:del_at_end(&start,&end);
                   break;

            case 6:printf("\n enter the position:=");
                   scanf("%d",&position);
                   del_at_mid(&start,&end,position);
                   break;

            case 7:node_traversal(start,end);
                   break;

            case 8:exit(0);

            default:printf("\n make proper selection");
        }
    }
}


