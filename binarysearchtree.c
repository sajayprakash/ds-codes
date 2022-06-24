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
struct node{ 
struct node *left; 
int element; 
struct node *right; 
}; 
typedef struct node node; 
node *insert(node *tree, int e); 
node *find(node *tree, int e); 
node *findmin(node *tree); 
node *findmax(node *tree); 
node *delete(node *tree, int e);
void display(node *tree);
int main(){ 
node *tree = NULL; 
node *result = NULL; 
int e, ch; 
printf("1: Insert\n2: Find \n3: Find Minimum \n4: Find Maximum\n5: Delete\n6: Display\n7: Exit\n"); 
do{ 
 printf("\nEnter your choice : "); 
 scanf("%d", &ch); 
 switch (ch) 
 { 
 case 1:
 printf("Enter the element to insert: ");
 scanf("%d", &e); 
 tree = insert(tree, e); 
 break;
 case 2: 
 printf("Enter the element to find : "); 
 scanf("%d", &e); 
 result = find(tree, e); 
 if (result == NULL) 
 printf("Element is not found...!"); 
 else
 printf("Element is found...!"); 
 printf("\n"); 
 break;
 case 3: 
 result = findmin(tree); 
 if (result == NULL) 
 printf("tree is empty...!"); 
 else
 printf("%d\n", result->element); 
 break; 
 case 4: 
 result = findmax(tree); 
 if (result == NULL) 
 printf("tree is empty...!"); 
 else
 printf("%d\n", result->element); 
 break; 
 case 5:
 printf("Enter the element to be deleted:");
 scanf("%d",&e);
 delete(tree,e);
 break;
 case 6:
 display(tree);
 break;
 default:
 printf("EXIT");
 } 
 } while (ch <= 6); 
return 0; 
} 

node *insert(node *tree, int e) 
{ 
node *Newnode = malloc(sizeof(node)); 
if (tree == NULL) 
 { 
 Newnode->element = e; 
 Newnode->left = NULL; 
 Newnode->right = NULL; 
 tree = Newnode; 
 } 
else if (e < tree->element) 
 tree->left = insert(tree->left, e); 
else if (e > tree->element) 
 tree->right = insert(tree->right, e); 
return tree; 
} 

node *find(node *tree, int e) 
{ 
if (tree == NULL) 
 return NULL; 
else if (e < tree->element) 
 return find(tree->left, e); 
else if (e > tree->element) 
 return find(tree->right, e); 
else
 return tree; 
}

node *findmin(node *tree) 
{ 
if (tree == NULL) 
 return NULL; 
else if (tree->left == NULL) 
 return tree; 
else
 return findmin(tree->left); 
} 

node *findmax(node *tree) 
{ 
if (tree == NULL) 
 return NULL; 
else if (tree->right == NULL) 
 return tree; 
else
 return findmax(tree->right); 
}

node *delete(node *tree, int e) 
{ 
node *Tempnode = malloc(sizeof(node)); 
if (e < tree->element) 
 { 
 tree->left = delete(tree->left, e); 
 } 
else if (e > tree->element) 
 { 
 tree->right = delete(tree->right, e); 
 } 
else if (tree->left && tree->right) 
 { 
 Tempnode = findmin(tree->right); 
 tree->element = Tempnode->element; 
 tree->right = delete(tree->right, tree->element); 
 } 
else
 { 
 Tempnode = tree; 
 if(tree->left == NULL) 
 tree = tree->right; 
 else if (tree->right == NULL) 
 tree = tree->left;
 free(Tempnode); 
 } 
return tree; 
}

void display(node *tree) 
{ 
if (tree != NULL) 
 { 
 display(tree->left); 
 printf("%d\t", tree->element); 
 display(tree->right); 
 } 
}
