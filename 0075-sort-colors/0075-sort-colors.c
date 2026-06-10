#include <stdio.h>

// Ham hoan doi hai phan tu bang con tro
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int curr = 0;
    int high = numsSize - 1;
    
    while (curr <= high) {
        if (nums[curr] == 0) {
            // Nem so 0 ve phia dau mang
            swap(&nums[curr], &nums[low]);
            low++;
            curr++;
        } 
        else if (nums[curr] == 1) {
            // So 1 giu nguyen o giua, chi can di tiep
            curr++;
        } 
        else { // nums[curr] == 2
            // Nem so 2 ve phia cuoi mang
            swap(&nums[curr], &nums[high]);
            high--;
            // Khong tang curr o day vi can check phan tu moi vua swap ve
        }
    }
}