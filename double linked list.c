#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node*next;
    int num;
    struct node*previous;
};

struct node *createnode(int);
void add_at_begin(struct node **);
void add_at_end(struct node **);
void add_at_mid(struct node **,int);
void del_at_begin(struct node **);
void del_at_end(struct node **);
void del_at_mid(struct node **,int);
void node_traversal(struct node*);
void node_count(struct node*);

struct node*createnode(int data)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));


    if(newnode==NULL)
    {
        return NULL;
    }
    else
    {
        newnode->previous=NULL;
        newnode->num=data;
        newnode->next=NULL;
    }
    return newnode;
};

void add_at_begin(struct node **start)
{
    struct node*temp;
    int num;

    printf("\n enter the element:=");
    scanf("%d",&num);
    temp=createnode(num);
    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {

        temp->next=(*start);
        (*start)->previous=temp;
        (*start)=temp;
    }
}

void add_at_end(struct node **start)
{
    struct node*temp,*current;
    int num;

    printf("\n enter the element:=");
    scanf("%d",&num);
    temp=createnode(num);

    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {
        current=(*start);

        while(current->next!=NULL)
        {
            current=current->next;
        }


            temp->previous=current;
            current->next=temp;
        }

}

void add_at_mid(struct node**start,int position)
{
    struct node*temp,*current;
    int data,count;

    printf("\n enter the element:=");
    scanf("%d",&data);
    temp=createnode(data);
    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {
        current=(*start);
        for(count=0;count<position-1;++count)
        {
            if(current->next==NULL)
            {
                puts("\n insufficient nodes");
                return;
            }
            else
            {
                current=current->next;
            }
        }
            temp->previous=current;
            temp->next=current->next;
            current->next->previous=temp;
            current->next=temp;

    }

}

void node_traversal(struct node*start)
{
    struct node*current;

    if(start==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=start;
        while(current!=NULL)
        {
            printf("\n list of values:=%d",current->num);
            current=current->next;
        }
    }
}

void reverse(struct node*start)
{
    struct node*current;

    if(start==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=start;
        while(current!=NULL)
        {
            current=current->next;
        }
    }

    while(current->previous!=NULL)
    {
        printf("%d\n",current->num);
        current=current->previous;
    }
}

void node_count(struct node *start)
{
     struct node*current;
     int count=0;

    if((start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=start;
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
        printf("\n total number of nodes:=%d",count);
    }
}

void del_at_begin(struct node**start)
{
    struct node *temp;
     if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        temp=(*start);
        (*start)->next->previous==NULL;
        (*start)=temp->next;
        free(temp);
    }
}

void del_at_end(struct node**start)
{
    struct node *current;

     if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=(*start);
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->previous->next=NULL;
        free(current);
    }
}

void del_at_mid(struct node**start,int position)
{
     struct node*current;
    int count;

     if((*start)==NULL)
    {
        puts("\n list is empty");
        return;
    }
    else
    {
        current=(*start);
        for(count=0;count<position-1;++count)
        {
            if(current->next==NULL)
            {
                puts("\n insufficient nodes");
                return;
            }
            else
            {
                current=current->next;
            }
        }
        current->previous->next=current->next;
        current->next->previous=current->previous;
        free(current);
    }

}

int main()
{
    struct node*head=NULL;
    int choice,position;

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
        printf("\n8]node count");
        printf("\n9]reverse");
        printf("\n 10]close");

        printf("\n enter your choice:=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:add_at_begin(&head);
                   break;

            case 2:add_at_end(&head);
                   break;

            case 3:printf("\n enter the position:=");
                   scanf("%d",&position);
                   add_at_mid(&head,position);
                   break;

            case 4:del_at_begin(&head);
                   break;

            case 5:del_at_end(&head);
                   break;

            case 6:printf("\n enter the position:=");
                   scanf("%d",&position);
                   del_at_mid(&head,position);
                   break;

            case 7:node_traversal(head);
                   break;

            case 8:node_count(head);
                   break;

            case 9:reverse(head);
                   break;

            case 10:exit(0);

            default:printf("\n make proper selection");
        }
    }
}
1
