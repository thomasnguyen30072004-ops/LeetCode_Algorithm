#include <stdlib.h>

/*
 * // Day la interface cua CustomFunction da duoc Leetcode khai bao san:
 *
 * int customFunction(int x, int y);
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes must be malloced, assume caller calls free().
 */
int** findSolution(int (*customFunction)(int, int), int z, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int count = 0;
    
    int x = 1;
    int y = 1000;
    
    // Thuc hien ky thuat hai con tro huong tam cheo
    while (x <= 1000 && y >= 1) {
        int val = customFunction(x, y);
        
        if (val == z) {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = x;
            result[count][1] = y;
            (*returnColumnSizes)[count] = 2; // Moi hang luon co 2 phan tu
            count++;
            
            x++;
            y--;
        }
        else if (val < z) {
            x++; // Gia tri thap qua, tang x de day gia tri len
        }
        else {
            y--; // Gia tri cao qua, giam y de keo gia tri xuong
        }
    }
    
    *returnSize = count; // Gan tong so luong cap nghiem tim duoc
    return result;
}