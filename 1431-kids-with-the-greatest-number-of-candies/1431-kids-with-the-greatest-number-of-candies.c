#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // Tim so keo lon nhat hien tai
    int maxCandies = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }

    // Cap phat bo nho dong cho mang ket qua
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    
    // Gan kich thuoc mang tra ve cho Leetcode quan ly
    *returnSize = candiesSize;

    // Kiem tra tung dua tre sau khi nhan them keo extra
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}