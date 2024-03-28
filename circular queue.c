#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
void display();

void enqueue(int data)
{
    if((front==rear+1)||(front==0&&rear==MAX-1))
    {
        puts("\n queue overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
            rear=(rear+1)%MAX;
            queue[rear]=data;
            printf("queue value:=%d",data);
    }
}

int dequeue()
{
    int val;
    if((front==-1)&&(rear==-1))
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
            front=(front+1)%MAX;
        }
        return val;
    }
}
void display()
{
    int i;
    if((front==-1)&&(rear==-1))
    {
        puts("\n queue underflow");
    }
    else
        {
            for(i=front;i!=rear; )
            {
                printf("%d\t",queue[i]);
                i=(i+1)%MAX;
                printf("%d",queue[front]);
            }
        }

}
int main()
{
int num,choice;

while(1)
{
printf("\n queue operations:=");
printf("\n 1]enqueue");
printf("\n 2]dequeue");
printf("\n 3]display");
printf("\n 4]close");

printf("\n enter your choice :=");
scanf("%d",&choice);

switch(choice)
{
case 1:printf("\n enter the num:=");
      scanf("%d",&num);
      enqueue(num);
      break;

case 2:printf("\n value:=%d",dequeue());
      break;

case 3:display();
       break;
case 4:exit(0);

default:printf("\n make proper selection");
}
}
}
