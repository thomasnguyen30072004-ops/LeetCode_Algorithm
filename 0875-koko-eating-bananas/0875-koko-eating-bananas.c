#include <stdio.h>

// Kiem tra xem voi toc do k, Koko co an het chuoi trong h gio khong
long long getHoursRequired(int* piles, int pilesSize, int k) {
    long long totalHours = 0;
    for (int i = 0; i < pilesSize; i++) {
        // Phep chia lam ron len tuong duong ceil((double)piles[i] / k)
        totalHours += (piles[i] + k - 1) / k;
    }
    return totalHours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;
    
    // Tim nai chuoi co so luong lon nhat de lam gioi han right
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }
    
    int ans = right;
    
    // Thuc hien tim kiem nhi phan tren tap ket qua toc do k
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (getHoursRequired(piles, pilesSize, mid) <= h) {
            ans = mid;        // Ghi nhan toc do kha thi
            right = mid - 1;  // Thu giam toc do xuong xem co duoc khong
        } else {
            left = mid + 1;   // An khong kip, bat buoc phai tang toc do len
        }
    }
    
    return ans;
}