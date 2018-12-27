#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

   
int main()
{
    tNode *r = CreatetNode((void*)10);
    Tree *tree = initTree(r);
    tNode *a = addchild(r, (void*)5); 
    tNode *b = addchild(r, (void*)15); 
    tNode *c = addchild(a, (void*)3); 
    tNode *d = addchild(a, (void*)8); 
    tNode *e = addchild(c, (void*)1); 
    tNode *f = addchild(b, (void*)20); 
   
    showtree(r);
    printf("%d\n", treeHeight(r));
    
    tNode *bstr = CreatetNode((void*)5);
    Tree *bst = initTree(bstr);
    addbsttree(bst, (void*)1);
    addbsttree(bst, (void*)3);
    addbsttree(bst, (void*)9);
    addbsttree(bst, (void*)7);
    addbsttree(bst, (void*)6);
    addbsttree(bst, (void*)2);
    addbsttree(bst, (void*)8);
    addbsttree(bst, (void*)4);
    addbsttree(bst, (void*)0);
    showtree(bstr);
    printf("%d\n",findLowestCommonAncestor(bstr, 2, 4));
}
