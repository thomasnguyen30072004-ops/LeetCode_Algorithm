#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1; // Stack rong khi top = -1

    for (int i = 0; i < asteroidsSize; i++) {
        int ast = asteroids[i];
        bool destroyed = false;

        // Xet va cham: Chi xay ra khi dinh stack di sang phai (>0) va thien thach hien tai di sang trai (<0)
        while (top >= 0 && stack[top] > 0 && ast < 0) {
            if (stack[top] < abs(ast)) {
                top--;
                continue; 
            } 
            else if (stack[top] == abs(ast)) {
                top--;
                destroyed = true; 
                break;
            } 
            // Neu thien thach dinh stack lon hon -> thien thach hien tai bi no
            else {
                destroyed = true;
                break;
            }
        }

        // Neu thien thach hien tai khong bi pha huy sau cac cu va cham thi nap vao stack
        if (!destroyed) {
            stack[++top] = ast;
        }
    }

    // Luu kich thuoc mang ket qua
    *returnSize = top + 1;
    
    // Thu nho bo nho cua mang stack ve dung kich thuoc thuc te truoc khi tra ve
    int* result = (int*)realloc(stack, (*returnSize) * sizeof(int));
    
    return result;
}