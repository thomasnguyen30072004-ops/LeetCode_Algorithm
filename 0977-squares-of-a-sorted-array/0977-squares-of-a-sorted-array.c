#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // Cap phat mang ket qua bang dung kich thuoc mang goc
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int left = 0;
    int right = numsSize - 1;
    
    // Con tro p dung de dien ket qua, bat dau tu cuoi mang (vi tri phan tu lon nhat)
    int p = numsSize - 1;
    
    while (left <= right) {
        int squareLeft = nums[left] * nums[left];
        int squareRight = nums[right] * nums[right];
        
        // Thang nao co binh phuong lon hon thi bo vao cuoi mang ket qua
        if (squareLeft > squareRight) {
            result[p] = squareLeft;
            left++; // Dich con tro trai sang phai
        } else {
            result[p] = squareRight;
            right--; // Dich con tro phai sang trai
        }
        p--; // Lui con tro dien ket qua ve phia truoc
    }
    
    return result;
}