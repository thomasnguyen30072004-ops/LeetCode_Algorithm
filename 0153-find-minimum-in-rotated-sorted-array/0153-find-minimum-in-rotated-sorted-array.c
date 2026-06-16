#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    // Vong lap chay cho den khi left va right hoi tu tai 1 diem
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // So sanh phan tu o giua voi phan tu ngoai cung ben phai
        if (nums[mid] > nums[right]) {
            // Diem roi chac chan nam o ben phai mid
            left = mid + 1;
        } else {
            // Diem roi co the la mid hoac nam o ben trai mid
            right = mid;
        }
    }
    
    return nums[left];
}