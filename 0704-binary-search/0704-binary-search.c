#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        // thay vi dung cach thong thuong la (left + right) / 2
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid; // Tim thay target, tra ve index hien tai
        }
        else if (nums[mid] < target) {
            left = mid + 1; // Target lon hon, bo nua ben trai, tim nua ben phai
        }
        else {
            right = mid - 1; // Target nho hon, bo nua ben phai, tim nua ben trai
        }
    }
    
    return -1;
}