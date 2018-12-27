#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

typedef struct Linkedlist {
    struct Node *head;
    struct Node *tail;
} List;

void* initlist(){
    List *list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> tail = NULL;
    return list;
}

void* addnode(List *list, void* data){
    Node *node = CreateNode(data); 
    if(list -> head == NULL){
        list -> head = node;
        list -> tail = node;
    }
    else{

        list -> tail -> next = node;
        list -> tail = node;
    }
    return node;
}
void showlist(List *list){
    Node* temp = list -> head;
    printf("[");
    while(temp != NULL){
        printf("%p, ",temp -> data);
        temp = temp -> next;
    }
    printf("]\n");
}
void removeHead(List *list){
    Node *node = list -> head;
    list -> head = list -> head ->next;
    free(node);
}
void* findMtolast(List *list, int m){
    //마지막부터 M번째요소를 찾아 리턴한다.
    Node *cur = list -> head;
    Node *tgr = list -> head;
    int c = 0;
    for(int i = 0; i < m; i++){
        if(cur == NULL) return NULL;
        cur = cur -> next;
    }
    while(cur != list ->tail){
        c++;
        if(cur == NULL) return NULL;
        cur = cur -> next;
        tgr = tgr -> next;
    }
    
    return tgr -> data;
   // else return NULL;
}
bool determineTermination(Node *head){
    //머리포인터를 인자로 받아서 리스트가 순환형인지 여부를 결정한다.
    Node *slow = head;
    Node *fast = head -> next;

    while(1){
        if(fast == NULL || fast -> next == NULL) return false;
        else if(fast == slow || fast -> next == slow) return true;
        else {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
    }
}

void clearlist(List *list){
    while(list -> head){
        Node *temp = list -> head;
        list -> head = list -> head -> next;
        free(temp);
    }
}   
