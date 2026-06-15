#include <stdlib.h>
#include <stdbool.h>

// Ham bo tro thuc hien Binary Search tuy bien de tim bien trai hoac bien phai
int findBound(int* nums, int numsSize, int target, bool isLeft) {
    int left = 0;
    int right = numsSize - 1;
    int ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            ans = mid; // Ghi nhan vi tri tiem nang
            
            if (isLeft) {
                right = mid - 1; // Tiep tuc ep sang trai de tim vi tri dau tien
            } else {
                left = mid + 1;  // Tiep tuc ep sang phai de tim vi tri cuoi cong
            }
        } 
        else if (nums[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // Cap phat mang ket qua gom 2 phan tu [start, end]
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // Chay 2 lan Binary Search doc lap de tim ra 2 dau mut
    result[0] = findBound(nums, numsSize, target, true);
    result[1] = findBound(nums, numsSize, target, false);
    
    return result;
}