#include <stdio.h>
#include <stdlib.h>
struct node
{
int element;
struct node *next;
};
typedef struct node node;
int isempty(node *list);
int islast(node *position, node *list);
node *find(node *list, int x);
node *findPrevious(node *list, int x);
node *findnext(node *list, int x);
void insertbeginning(node *list, int e);
void insertlast(node *list, int e);
void insertmid(node *list, int p, int e);
void deletebeginning(node *list);
void deleteend(node *list);
void deletemid(node *list, int e);
void traverse(node *list);
int main()
{
node *list = malloc(sizeof(node));
list->next = list;
node *position;
int ch, e, p;
printf("1: Insert Beginning\n2: Insert Middle\n3: Insert End\n4: Delete Beginning\n5: Delete Middle\n6: Delete End\n7: Find\n8: Traverse\n9: Exit\n");
do
{
printf("Enter your choice : ");
scanf("%d", &ch);
switch(ch)
{
case 1:
printf("Enter the element : ");
scanf("%d", &e);
insertbeginning(list, e);
break;
case 2:
printf("Enter the position element : ");
scanf("%d", &p);
printf("Enter the element : ");
scanf("%d", &e);
insertmid(list, p, e);
break;
case 3:
printf("Enter the element : ");
scanf("%d", &e);
insertlast(list, e);
break;
case 4:
deletebeginning(list);
break;
case 5:
printf("Enter the element : ");
scanf("%d", &e);
deletemid(list, e);
break;
case 6:
deleteend(list);
break;
case 7:
printf("Enter the element : ");
scanf("%d", &e);
position = find(list, e);
if(position != list)
printf("element found...!\n");
else
printf("element not found...!\n");
break;
case 8:
traverse(list);
break;
}
} while(ch <= 8);
return 0;
}
int isempty(node *list)
{
if(list->next == list)
return 1;
else
return 0;
}
int islast(node *position, node *list)
{
if(position->next == list)
return 1;
else
return 0;
}
node *find(node *list, int x)
{
node *position;
position = list->next;
while(position != list && position->element != x)
position = position->next;
return position;
}
node *findPrevious(node *list, int x)
{
node *position;
position = list;
while(position->next != list && position->next->element != x)
position = position->next;
return position;
}
node *findnext(node *list, int x)
{
node *position;
position = find(list, x);
return position->next;
}
void insertbeginning(node *list, int e)
{
node *Newnode = malloc(sizeof(node));
Newnode->element = e;
Newnode->next = list->next;
list->next = Newnode;
}
void insertlast(node *list, int e)
{
node *Newnode = malloc(sizeof(node));
node *position;
Newnode->element = e;
if(isempty(list))
{
Newnode->next = list;
list->next = Newnode;
}
else
{
position = list;
while(position->next != list)
position = position->next;
position->next = Newnode;
Newnode->next = list;
}
}
void insertmid(node *list, int p, int e)
{
node *Newnode = malloc(sizeof(node));
node *position;
position = find(list, p);
Newnode->element = e;
Newnode->next = position->next;
position->next = Newnode;
}
void deletebeginning(node *list)
{
if(!isempty(list))
{
    node *Tempnode;
Tempnode = list->next;
list->next = Tempnode->next;
printf("The deleted item is %d\n", Tempnode->element);
free(Tempnode);
}
else
printf("list is empty...!\n");
}
void deleteend(node *list)
{
if(!isempty(list))
{
node *position;
node *Tempnode;
position = list;
while(position->next->next != list)
position = position->next;
Tempnode = position->next;
position->next = list;
printf("The deleted item is %d\n", Tempnode->element);
free(Tempnode);
}
else
printf("list is empty...!\n");
}
void deletemid(node *list, int e)
{
if(!isempty(list))
{
node *position;
node *Tempnode;
position = findPrevious(list, e);
if(!islast(position, list))
{
Tempnode = position->next;
position->next = Tempnode->next;
printf("The deleted item is %d\n", Tempnode->element);
free(Tempnode);
}
}
else
printf("list is empty...!\n");
}
void traverse(node *list)
{
if(!isempty(list))
{
node *position;
position = list;
while(position->next != list)
{
position = position->next;
printf("%d\t", position->element);
}
printf("\n");
}
else
printf("list is empty...!\n");
}