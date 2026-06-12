#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int maxCandies = candies[0];
    for (int i=0; i < candiesSize; i++){
        if (candies[i] > maxCandies){
            maxCandies = candies[i];
        }
    }

    // Cap phat bo nho dong cho mang ket qua
    bool *result = (bool *)malloc(candiesSize * sizeof(bool));

    *returnSize = candiesSize;

    for (int i=0; i < candiesSize; i++){
        if (candies[i] + extraCandies >= maxCandies){
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}