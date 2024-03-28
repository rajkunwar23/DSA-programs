#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void startenqueue(int);
void endenqueue(int);
int startdequeue();
int enddequeue();
void display();

void endenqueue(int data)
{
    if(rear==MAX-1)
    {
        puts("\n queue overflow");
    }
    else
    {
        queue[++rear]=data;
        if(front==-1)
        {
            front=0;
        }
    }
}

void startenqueue(int data)
{
    int i;
    if(rear==MAX-1)
    {
        puts("\n queue overflow");
    }
    else
    {
        if(front==-1&&rear==-1)
        {
            front=rear=0;
            queue[front]=data;
        }
        else
        {
            for(i=rear;i>=0;i--)
            {
                queue[i+1]=queue[i];
            }
            queue[0]=data;
            rear++;
        }
    }
}

int startdequeue()
{
    int val;
    if(rear==-1&&front==-1)
    {
        puts("\n queue underflow");
    }
    else
    {
        val=queue[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
}

int enddequeue()
{
    int val;
    if(rear==-1&&front==-1)
    {
        puts("\n queue underflow");
    }
    else
    {
        val=queue[rear];
        if(rear==front)
        {
            rear=front=-1;
        }
        else
        {
            rear--;
        }
    }
}

void display()
{
    int i;
    if(rear==-1&&front==-1)
    {
        puts("\n queue overflow");
    }
    else
        {
            for(i=front;i<=rear;i++)
            {
                printf("%d\t",queue[i]);
            }
        }
}

int main()
{
int num,choice=0;

while(choice<6)
{
printf("\n queue operations:=");
printf("\n 1]startenqueue");
printf("\n 2]endenqueue");
printf("\n 3]startdequeue");
printf("\n 4]enddequeue");
printf("\n 5]display");
printf("\n 6]close");

printf("\n enter your choice :=");
scanf("%d",&choice);

switch(choice)
{
case 1:printf("\n enter the num:=");
      scanf("%d",&num);
      startenqueue(num);
      break;

case 2:printf("\n enter the num:=");
      scanf("%d",&num);
      endenqueue(num);
      break;

case 3:printf("%d",startdequeue());
      break;

case 4:printf("%d",enddequeue());
       break;

case 5:display();
       break;

default:printf("\n make proper selection");
}
}
}


