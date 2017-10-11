#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericlinkedList.h"

typedef struct listElementStruct{
    void* data;
    size_t size;
    struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size){
    listElement* e = malloc(sizeof(listElement));
    if(e == NULL){
        //malloc has had an error
        return NULL; //return NULL to indicate an error.
    }
    char* dataPointer = malloc(sizeof(char)*size);
    if(dataPointer == NULL){
        //malloc has had an error
        free(e); //release the previously allocated memory
        return NULL; //return NULL to indicate an error.
    }
    strcpy(dataPointer, data);
    e->data = dataPointer;
    e->size = size;
    e->next = NULL;
    return e;
}

//Prints out each element in the list
void traverse(listElement* start){
    listElement* current = start;
    while(current != NULL){
        //printf("%s\n", current->data); <---- im not sure how to get the print functionality in the code
        current = current->next;
    }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size){
    listElement* newEl = createEl(data, size);
    listElement* next = el->next;
    newEl->next = next;
    el->next = newEl;
    return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
    listElement* delete = after->next;
    listElement* newNext = delete->next;
    after->next = newNext;
    //need to free the memory because we used malloc
    free(delete->data);
    free(delete);
}

//My stuff ---------------------------------------------------------------------------------


int length(listElement* list){
    int count = 0;
    listElement* current = list;
    
    while (current != NULL) {
        current = current->next;
        count++;
    }
    
    return count;
    
}

void push(listElement** list, void* data, size_t size){
    
    
    
    listElement* temp = createEl(data, size);
    
    temp->next = *list;
    
    *list = temp;
    
}

listElement* pop(listElement** list){
    
    if(length(*list) == 0){
        return NULL;
    }
    
    listElement* head = *list;
    
    *list = head->next;
    
    return head;
    
}

void  enqueue(listElement** list, void* data, size_t size){
    
    push(list, data,size);
    
}

listElement* dequeue(listElement* list){
    
    listElement* position = list;
    int lLength = length(list);
    
    if(lLength == 0){
        return NULL;
    }
    else if(lLength == 1){
        list = NULL;
        return position;
    }
    else{
        
        while(position->next->next != NULL){
            position = position->next;
        }
        
        listElement* output = position->next;
        
        position->next = NULL;
        
        return output;
        
    }
    
}












































