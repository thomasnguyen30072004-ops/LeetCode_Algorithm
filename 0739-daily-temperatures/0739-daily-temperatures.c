#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    // Cap phat mang ket qua va khoi tao tat ca bang 0
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    
    // Cap phat mang lam Stack luu tru index cua cac ngay
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1; // Stack rong khi top = -1
    
    for (int i = 0; i < temperaturesSize; i++) {
        // Neu Stack khong rong VA nhiet do ngay hien tai lon hon nhiet do o dinh Stack
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev_index = stack[top--]; // Pop index o dinh stack ra
            answer[prev_index] = i - prev_index; // Tinh so ngay phai cho
        }
        
        // Push index cua ngay hien tai vao Stack de cho cac ngay tuong lai xet
        stack[++top] = i;
    }
    
    free(stack);
    
    return answer;
}