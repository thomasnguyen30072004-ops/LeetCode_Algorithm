#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int data[105];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1; // Stack rong khi top = -1
    return s;
}

void push(Stack* s, int x) {
    s->data[++(s->top)] = x;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

void freeStack(Stack* s) {
    free(s);
}

typedef struct {
    Stack* s1; // Luu cac phan tu moi nap vao (In-stack)
    Stack* s2; // Luu cac phan tu cho de lay ra (Out-stack)
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s1 = createStack();
    queue->s2 = createStack();
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    // Luon luon push vao s1 (O(1))
    push(obj->s1, x);
}

// Ham phu tro: Neu s2 rong, do het du lieu tu s1 sang s2 de dao nguoc thu tu
void shiftStacks(MyQueue* obj) {
    if (isStackEmpty(obj->s2)) {
        while (!isStackEmpty(obj->s1)) {
            push(obj->s2, pop(obj->s1));
        }
    }
}

int myQueuePop(MyQueue* obj) {
    // Dam bao s2 co du lieu de lay ra
    shiftStacks(obj);
    return pop(obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    // Dam bao s2 co du lieu de xem
    shiftStacks(obj);
    return peek(obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    // Queue rong khi va chi khi ca hai stack deu khong con phan tu
    return isStackEmpty(obj->s1) && isStackEmpty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
    freeStack(obj->s1);
    freeStack(obj->s2);
    free(obj);
}