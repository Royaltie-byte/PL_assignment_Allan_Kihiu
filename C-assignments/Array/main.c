#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct ArrayList {
    int data[MAX_SIZE];
    int size;
};
//function prototypes
void insertAt(struct ArrayList *list , int index , int value);
void deleteAt(struct ArrayList *list , int index);
void traverse(struct ArrayList list);

//function definitions
void insertAt(struct ArrayList *list , int index , int value){
    //first we check if the list is full
    //
    if(list->size== MAX_SIZE){
        printf("The list is full!!\n");
        return;
    }
    if(index>list->size){
        printf("The input index is invalid.\n");
        return ;
    }
    //Now we move elements to the right to create space
    for(int i=list->size;i>=index;i--){
        list->data[i+1]=list->data[i];
    }
    list->data[index]=value;
    list->size++;
}
//traverse function definition.
void traverse(struct ArrayList list){
    if(list.size==0){
        printf("The list is empty\n");
        return;
    }
    for(int i=0 ; i<list.size;i++){
            printf("The value at index %d is :",i);
        printf("The data at %d is %d\n",i, list.data[i]);
    }
}

//Now the delete function definition.
void deleteAt(struct ArrayList *list , int index){
    //we check if the list is empty.
    if(list->size==0){
        printf("The list is empty!\n");
        return;
    }
    //we shift elements to the left from the index that we are
    //supposed to delete,, overwriting on it
    for(int i=index;i<list->size;i++){
        list->data[i]=list->data[i+1];
    }
    list->size--;
}
int main()
{
    struct ArrayList list;
    list.size=0;
    insertAt(&list , 0 , 12);
    insertAt(&list , 0 , 20);
    insertAt(&list , 0 , 90);
    insertAt(&list , 0 , 120);
    insertAt(&list , 4 , 1000);
    traverse(list);
    printf("The size of the new array after insertions is : %d\n",list.size);
    //testing the delete function
    deleteAt(&list,0);
    deleteAt(&list,3);
    printf("Array after deletion \n");
    traverse(list);
    printf("Size of array after two deletions is :%d",list.size);



    return 0;
}
