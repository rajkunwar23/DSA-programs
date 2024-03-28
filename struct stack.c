#include <stdio.h>
struct stack
{
int arr[5];
int top;
};

void init(struct stack*);
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack);

void init(struct stack*s)
{
s->top=-1;
}

void push(struct stack*s,int data)
{
if(s->top==4)
{
puts("\n stack overflow");
}
else
{
s->top++;
s->arr[s->top]=data;
}
}

int pop(struct stack*s)
{
int val;

if(s->top==-1)
{
puts("\n stack underflow");
}
else
{
val=s->arr[s->top];
s->top--;
}
return val;
}

int peek(struct stack*s)
{
int val;

if(s->top==-1)
{
puts("\n stack underflow");
}
else
{
val=s->arr[s->top];
}
return val;
}

void display(struct stack s)
{
int i;

if(s.top==-1)
{
puts("\n stack underflow");
}
else
{
for(i=s.top;i>=0;--i)
{
printf("%d\t",s.arr[i]);
}
}
}

int main()
{
int num,choice=0;
struct stack s;
init(&s);

while(choice<5)
{
printf("\n queue operations:=");
printf("\n 1]push");
printf("\n 2]pop");
printf("\n 3]peek");
printf("\n 4]display");
printf("\n 5]close");

printf("\n enter your choice :=");
scanf("%d",&choice);

switch(choice)
{
case 1:printf("\n enter the num:=");
      scanf("%d",&num);
      push(&s,num);
      break;

case 2:printf("\n popped value:=%d",pop(&s));
      break;

case 3:printf("\n peek value:=%d",peek(&s));
      break;

case 4:display(s);
       break;

default:printf("\n make proper selection");
}
}
}
