#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int data[105];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int peek(Queue* q) {
    return q->data[q->front];
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void freeQueue(Queue* q) {
    free(q);
}

typedef struct {
    Queue* q1; // Queue chinh chua cac phan tu dung thu tu Stack
    Queue* q2; // Queue phu dung de dao thu tu khi push
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    // 1. Dua phan tu moi vao q2
    enqueue(obj->q2, x);
    
    // 2. Chuyen toan bo phan tu tu q1 sang q2 de phan tu x nam o dau hang doi
    while (!isQueueEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    
    // 3. Swap q1 va q2 de q1 luon la hang doi chinh
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    // Vi dau q1 luon la dinh Stack nen chi can dequeue tu q1
    return dequeue(obj->q1);
}

int myStackTop(MyStack* obj) {
    // Lay gia tri dau cua q1 ma khong xoa
    return peek(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q1);
    freeQueue(obj->q2);
    free(obj);
}