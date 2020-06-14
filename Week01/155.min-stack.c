typedef struct TagNode{
    int data;
    int min;
    struct TagNode *next; 
} Node;

typedef struct { 
    Node *top;
    int size;
} MinStack;

Node *CreateNode(int x)
{
    Node *n = calloc(1, sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    MinStack *obj = calloc(1, sizeof(MinStack));
    obj->top = CreateNode(0);
    obj->size = 0;
    return obj;
}
void minStackPop(MinStack* obj) {
    Node *tmp;
    if (obj->size == 0 || !obj->top->next) {
        return ;
    }
    tmp = obj->top->next;
    obj->top->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
    --obj->size;
}

int minStackTop(MinStack* obj) {
    if (obj->size == 0 || !obj->top->next) {
        return 0;
    }
    return obj->top->next->data;

}

int minStackGetMin(MinStack* obj) {
    if (obj->size == 0 || !obj->top->next) {
        return 0;
    }
    return obj->top->next->min;
}

void minStackPush(MinStack* obj, int x) 
{
    Node *p= CreateNode(x);
    /* only one element, min is itself */
    if (obj->size == 0){
        p->min = x;
    } else {
        p->min = minStackGetMin(obj);
        p->min = p->min > x ? x : p->min;
    }

    p->next = obj->top->next;
    obj->top->next = p;
    obj->size++;
}

void minStackFree(MinStack* obj) {

}