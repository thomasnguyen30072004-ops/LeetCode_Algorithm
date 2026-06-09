#include <stdio.h>
#include <stdlib.h>

// Ham so sanh dung cho qsort (sap xep tang dan)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // 1. Sap xep mang theo thu tu tang dan bang Quick Sort
    qsort(nums, numsSize, sizeof(int), compare);
    
    int sum = 0;
    
    // 2. Cong don cac phan tu o vi tri chi so chan (0, 2, 4, ...)
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    
    return sum;
}