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
#define arrsize 20 // Size of the array
void createarray(int array[]);
void traverse(int array[]);
void insert(int array[],int p, int e);
void delete (int array[], int p);
int menu();
int n,p,e,array[arrsize]; //Global Variables

int main(){
    menu();
    return 0;
}

void createarray(int array[]){
    printf("Enter the no. of terms:\n");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        printf("Enter the %d term:\n",i);
        scanf("%d",&array[i]);
    }
}

void traverse(int array[]){
    printf("Array: ");
    for (int i=1;i<=n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    }

void insert(int array[],int p,int e){
    for (int i=n;i<=p;i--){
        array[i+1]=array[i];
    }
    array[p]=e;
    n+=1;
}

void delete(int array[],int p){
    for (int i=p;i<n;i++){
        array[i]=array[i+1];
    }
    n-=1;
}

int menu(){
    int uchoice;
    while (1){
        printf("Do you want to:\n1: Create an Array\n2: Traverse the Array\n3: Insert into Array\n4: Delete from Array\n5: Exit\n");
        scanf("%d",&uchoice);
        switch (uchoice){
            case 1:
            createarray(array);
            break;
            case 2:
            traverse(array);
            break;
            case 3:
            printf("Enter the position:\n");
            scanf("%d",&p);
            printf("Enter the element:\n");
            scanf("%d",&e);
            insert(array,p,e);
            break;
            case 4:
            printf("Enter the position to delete:\n");
            scanf("%d",&p);
            delete(array,p);
            break;
            case 5:
            printf("Program exiting...\n");
            return 0;
        }

    }

}
