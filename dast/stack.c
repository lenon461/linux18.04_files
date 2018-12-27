#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(){
    Node* a = CreateNode((int*)9);
    Node* b = CreateNode((int*)8);

    Stack *stack = CreateStack();

    push(stack, a);
    push(stack, b);

    printf("%p\n", pop(stack));
    printf("%p\n", pop(stack));
    printf("%p\n", pop(stack));
}
