#include <stdbool.h>

bool isPerfectSquare(int num) {
    // Truong hop dac biet: so 1 luon la so chinh phuong (1 * 1 = 1)
    if (num == 1) return true;
    
    long long left = 1;
    long long right = num;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        
        if (square == num) {
            return true; 
        } 
        else if (square < num) {
            left = mid + 1; // Thap qua, tim o nua ben phai
        } 
        else {
            right = mid - 1; // Cao qua, tim o nua ben trai
        }
    }
    
    return false;
}