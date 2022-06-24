/*
 *  ____  ____  
 * / ___||  _ \ 
 * \___ \| |_) | 
 *  ___) |  __/ 
 * |____/|_| 
 * 
 * SAJAY PRAKASH <sajay.p@pm.me>
 * 
 */
#include <stdio.h>
#define max 5
int queue[max], front = -1, rear = -1;
int isfull();
int isempty();
void enqueue(int ele);
void dequeue();
void display();
int main()
{
int ch, e;
do
{
printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
printf("Enter your choice:\n ");
scanf("%d", &ch);
switch(ch)
{
case 1:
printf("Enter the element : ");
scanf("%d", &e);
enqueue(e);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
}
} while(ch <= 3);
return 0;
}
int isfull()
{
if(rear == max - 1)
return 1;
else
return 0;
}
int isempty()
{
if(front == -1)
return 1;
else
return 0;
}
void enqueue(int ele)
{
if(isfull())
printf("queue is Overflow...!\n");
else
{
rear = rear + 1;
queue[rear] = ele;
if(front == -1)
front = 0;
}
}
void dequeue()
{
if(isempty())
printf("queue is Underflow...!\n");
else
{
printf("%d\n", queue[front]);
if(front == rear)
front = rear = -1;
else
front = front + 1;
}
}
void display()
{
int i;
if(isempty())
printf("queue is Underflow...!\n");
else
{
for(i = front; i <= rear; i++)
printf("%d\t", queue[i]);
printf("\n");
}
}
