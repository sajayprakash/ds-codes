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
int isempty();
void push(int);
void pop();
void display();
struct stack{
int element;
struct stack *next;
}*list=NULL;

typedef struct stack stack;
int main(){
  int ch,e;
  while (1){
    printf("Enter your choice:\n1: Display Stack\n2: Push\n3: Pop\n4: Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        display();
        break;
      case 2:
        printf("Enter element:\n");
        scanf("%d",&e);
        push(e);
        break;
      case 3:
        pop();
        break;
      case 4:
        return 0;
    }
  }
}

int isempty(){
if (list==NULL)
  return 1;
else
  return 0;
}
void push(int e){
  stack *newnode=malloc(sizeof(stack));
  newnode->element=e; 
  if (isempty())
    newnode->next=NULL;
  else{
  newnode->next=list;
  }
  list=newnode;
}
void pop(){
if (isempty())
  printf("Stack Underflow!\n");
else{
stack *tempnode;
tempnode=list;
list=list->next;
printf("The deleted element is: %d\n",tempnode->element);
free(tempnode);
}
}
void display(){
if (isempty())
  printf("Empty stack!\n");
else{
  stack *pos;
  pos=list;
  while (pos!=NULL){
    printf("%d\t",pos->element);
    pos=pos->next;
  }
  printf("\n");
}
}
