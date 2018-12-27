#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct Stack {
    struct Node *top;
} Stack;

void* CreateStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack -> top = NULL;
    
    return stack;
}
void* push(Stack *stack, Node *node){
    if(stack -> top == NULL){
        stack -> top = node;
    }
    else{
        node -> next = stack -> top;
        stack -> top = node;
    }
}
void* pop(Stack *stack){
    if(stack -> top == NULL) return -1;
    else{
        void* data = stack -> top -> data;
        stack -> top = stack -> top -> next;
        return data;
    }
}
