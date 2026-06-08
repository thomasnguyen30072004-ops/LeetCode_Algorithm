#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* data;      // Mang dong luu du lieu
    int head;       // Con tro quan ly dau hang doi (lay data ra)
    int tail;       // Con tro quan ly cuoi hang doi (them data vao)
    int size;       // So luong phan tu hien tai dang co
    int capacity;   // Suc chua toi da cua queue (chinh la k)
} MyCircularQueue;

// Khoi tao queue voi dung luong k
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(k * sizeof(int));
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

// Kiem tra queue co trong hay khong
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

// Kiem tra queue da day hay chua
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

// Them phan tu vao cuoi queue
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) return false;
    
    // Ghi du lieu vao vi tri tail hien tai
    obj->data[obj->tail] = value;
    // Tinh tien tail theo vong tron bang phep chia lay du %
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;
    
    return true;
}

// Xoa phan tu o dau queue
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;
    
    // Chi can tinh tien con tro head len theo vong tron
    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    
    return true;
}

// Lay phan tu o dau queue
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->data[obj->head];
}

// Lay phan tu o cuoi queue
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    
    // Vi tail luon tro vao o trong tiep theo, nen phan tu cuoi thuc su
    // nam o vi tri ngay truoc tail. Can cong capacity de tranh index bi am.
    int lastIdx = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[lastIdx];
}

// Giai phong bo nho
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}