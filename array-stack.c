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
#include<stdio.h>
#include<stdlib.h>
#define max 10
int isempty();
int isfull();
void push(int element);
void pop();
void Top();
void display();
int stack[max],top=-1;
int main()
{
 int choice,element;
 while(1)
 {
 printf("1: Push\n2: Pop\n3: Top\n4: Display\n5: Exit\n");
 printf("Enter your choice:\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("Enter the element you want to insert: ");
 scanf("%d",&element);
 push(element);
 break;
 case 2:
 pop();
 break;
 case 3:
 Top();
 break;
 case 4:
 display();
 break;
 case 5:
 exit(0);
 break;
 }
}
}
int isempty()
{
 if(top==-1)
 return 1;
 else
 return 0;
}
int isfull()
{
 if(top==max-1)
 return 1;
 else
 return 0;
}
void push(int element)
{
 if(isfull())
 printf("stack overflows\n");
 else
 {
 top=top+1;
 stack[top]=element;
 }
}
void pop()
{
 if(isempty())
 printf("stack underflow\n");
 else
 {
 printf("The deleted item is %d\n",stack[top]);
 top=top-1;
 }
}
void display()
{
 int i;
 if(isempty())
 printf("stack underflow\n");
 else
 {
 for(i=top;i>=0;i--)
 {
 printf("%d ",stack[i]);
 }
 printf("\n");
 }
}
void Top()
{
 if(isempty())
 printf("stack underflow\n");
 else
 printf("%d\n",stack[top]);
}