#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Neu luc luong bi triet tieu ve 0, chon ung cu vien moi o vi tri hien tai
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        }
        // Neu gap so giong ung cu vien thi tang mang, khac thi hi sinh 1 mang
        else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}