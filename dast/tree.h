#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
typedef struct Tree{
    struct tNode *root;
} Tree;

void* initTree(tNode *root){
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree -> root = root;
    return tree;
}
void* addchild(tNode *temp, void* value){
    tNode *tnode = CreatetNode(value);
    if(temp -> lchild == NULL){
        temp -> lchild = tnode;
        tnode -> parent = temp;
    } else if(temp -> rchild == NULL){
        temp -> rchild = tnode;
        tnode -> parent = temp;
    } else {
        temp -> lchild = tnode;
        tnode -> parent = temp;
    }
}
void* addbsttree(Tree *tree, void* value){
    tNode *node = CreatetNode(value);
    tNode *temp = tree -> root;
    tNode *temppar = tree -> root;

    while(temp){
        if(value > temp -> data){
            temppar = temp;
            temp = temp -> rchild;
        }
        else{
            temppar = temp;
            temp = temp -> lchild;
        }
    }
    if(temppar-> data < value){
        temppar -> rchild = node;
        node -> parent = temppar;
    }
    else if(temppar-> data >= value){
        temppar -> lchild = node;
        node -> parent = temppar;
    }
    return node;
}
void showtree(tNode *root){
    tNode* temp = root;
    if(temp){
        printf("%p, ", temp -> data);
        showtree(temp -> lchild);
        showtree(temp -> rchild);   
    }
}

int treeHeight(tNode *root){
    if(root == NULL) return  0;
    return 1 + MAX(treeHeight(root -> lchild), treeHeight(root -> rchild));
}

int findLowestCommonAncestor(tNode *root, int a, int b){
    while(root){
        void* k =  root -> data;
        printf("%p",k);
        if(k <a && k < b) root = root -> lchild;
        else if(k > a && k > b) root = root -> rchild;
        else return root -> data;
    }
    return -1;
}

