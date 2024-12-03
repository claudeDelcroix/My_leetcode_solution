

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} queue;

typedef struct {
    queue *q1, *q2;
} MyStack;

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;

    return q;
}

void enqueue(queue* q, int data) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));

    temp->data = data;
    temp->next = NULL;

    if ( q->rear == NULL ) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(queue* q) {
    if ( q->front == NULL ) return -1;

    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if ( q->front == NULL )
        q->rear = NULL;

    free(temp);

    return data;
}

bool is_empty(queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));

    stack->q1 = create_queue();
    stack->q2 = create_queue();

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    while (obj->q1->front && obj->q1->front->next) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    int popped = dequeue(obj->q1);

    queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return popped;
}

int myStackTop(MyStack* obj) {
    while (obj->q1->front && obj->q1->front->next) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    int top = obj->q1->front->data;

    enqueue(obj->q2, dequeue(obj->q1));

    queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return top;
}

bool myStackEmpty(MyStack* obj) {
    return is_empty(obj->q1);
}

void myStackFree(MyStack* obj) {
    while ( !is_empty(obj->q1) )
        myStackPop(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/


//un code plus leger 7.8 mb

#define MAX_SIZE 100

typedef struct {
    int top;
    int* arr;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*) malloc(sizeof(MyStack));
    stack->arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    stack->top = -1;

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->top += 1;
    obj->arr[obj->top] = x;
}

int myStackPop(MyStack* obj) {
    int temp = obj->arr[obj->top];
    obj->top = obj->top - 1;

    return temp;
}

int myStackTop(MyStack* obj) {
    if (obj->top == -1) return -1;
    return obj->arr[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return (obj->top == -1);
}

void myStackFree(MyStack* obj) {
    if (obj) {
        free(obj->arr);
        free(obj);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

//un autre code de 8mb 



typedef struct {
    int stack[100];
    int topindex;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->topindex = -1;
    memset(&obj->stack[0], 0, sizeof(int)*100);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->stack[++obj->topindex] = x;
}

int myStackPop(MyStack* obj) {
    int ret = obj->stack[obj->topindex--];
    return ret;
}

int myStackTop(MyStack* obj) {
    return obj->stack[obj->topindex];
}

bool myStackEmpty(MyStack* obj) {
    return (obj->topindex==-1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

// un autre code de 8.1mb
typedef struct {
    int stack[100];
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stk = malloc(sizeof(MyStack));
    stk->top = -1;
    return stk;
}

void myStackPush(MyStack* obj, int x) {
    obj->stack[++obj->top] = x;
}

int myStackPop(MyStack* obj) {
    return obj->stack[obj->top--];
}

int myStackTop(MyStack* obj) {
    return obj->stack[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
