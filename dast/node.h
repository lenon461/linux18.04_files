typedef struct Node {
    struct Node *next;
    void* data;
} Node;
typedef struct tNode {
    struct tNode *lchild;
    struct tNode *rchild;
    struct tNode *parent;
    void* data;
} tNode;
void* CreateNode(void* value){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode -> next = NULL;
    newnode -> data = value;
    return newnode;
}
void* CreatetNode(void* value){
    tNode *newtnode = (tNode*)malloc(sizeof(tNode));
    newtnode -> lchild = NULL;
    newtnode -> rchild = NULL;
    newtnode -> parent = NULL;
    newtnode -> data = value;
    return newtnode;
}

