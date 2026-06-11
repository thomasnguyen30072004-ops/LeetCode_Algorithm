#include <stdio.h>

int mySqrt(int x) {
    // Truong hop dac biet: x bang 0 hoac 1 thi can bac hai bang chinh no
    if (x == 0 || x == 1) return x;
    
    long long left = 1;
    long long right = x;
    long long ans = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        
        if (square == x) {
            return (int)mid; // Tim thay can bac hai chinh xac
        } 
        else if (square < x) {
            ans = mid;     // Luu lai gia tri lam tron xuong tiem nang
            left = mid + 1; // Tim o nua ben phai xem co so nao lon hon khong
        } 
        else {
            right = mid - 1; // Vuot qua x, thu tim o nua ben trai
        }
    }
    
    return (int)ans;
}