#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

    
int main(){
    int i = 9;
    List* list = initlist();
    Node *a = addnode(list, (void*)8);
    Node *b = addnode(list, (void*)9);
    addnode(list, (void*)10);
    addnode(list, (void*)11);
    addnode(list, (void*)12);
    addnode(list, (void*)13);
    addnode(list, (void*)14);
    addnode(list, (void*)15);
    Node *c = addnode(list, (void*)20);
    Node *d = addnode(list, (void*)16);
    removeHead(list);  
    
    
    showlist(list);
    clearlist(list);
    showlist(list);
}
