#include <stdio.h>
int queue[5];
int front=-1,rear=-1;

void enqueue(int);
int dequeue();
void display();

void enqueue(int data)
{
if(rear==4)
{
puts("\n queue overflow");
}
else
{
queue[++rear]=data;
}
if(front==-1)
{
front=0;
}
}

int dequeue()
{
int val;

if(front==-1)
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
return val;
}
}

void display()
{
int i;

if(front==-1)
{
puts("\n queue underflow");
}
else
{
for(i=front;i<=rear;++i)
{
printf("%d\t",queue[i]);
}
}
}

int main()
{
int num,choice=0;

while(choice<4)
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

default:printf("\n make proper selection");
}
}
}
