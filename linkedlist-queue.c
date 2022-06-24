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
#include <stdlib.h>
struct node
{
int element;
struct node *next;
}*front = NULL, *rear = NULL;
typedef struct node queue;
int isempty(queue *list);
void enqueue(int e);
void dequeue();
void display();
int main()
{
int ch, e;
do
{
printf("1: Enqueue\n2: Dequeue\n3: Display\n4.Exit\n");
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
int isempty(queue *list)
{
if(list == NULL)
return 1;
else
return 0;
}
void enqueue(int e)
{
queue *NewNode = malloc(sizeof(queue));
NewNode->element = e;
NewNode->next = NULL;
if(rear == NULL)
front = rear = NewNode;
else
{
rear->next = NewNode;
rear = NewNode;
}
}
void dequeue()
{
if(isempty(front))
printf("Queue is Underflow...!\n");
else
{
queue *tempnode;
tempnode = front;
if(front == rear)
front = rear = NULL;
else
front = front->next;
printf("%d\n", tempnode->element);
free(tempnode);
}
}
void display()
{
if(isempty(front))
printf("Queue is Underflow...!\n");
else
{
queue *position;
position = front;
while(position != NULL)
{
printf("%d\t", position->element);
position = position->next;
}
printf("\n");
}
}