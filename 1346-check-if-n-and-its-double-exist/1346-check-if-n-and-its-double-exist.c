#include <stdbool.h>
#include <string.h>

bool checkIfExist(int* arr, int arrSize) {
    // Kich thuoc 2001 de phu hop tu -1000 den 1000 (cong offset 1000)
    int visited[2001] = {0};
    
    for (int i = 0; i < arrSize; i++) {
        int v = arr[i];
        
        // Kiem tra xem thang gap doi (2 * v) da xuat hien truoc do chua
        int double_v = 2 * v;
        if (double_v >= -1000 && double_v <= 1000) {
            if (visited[double_v + 1000] > 0) {
                return true;
            }
        }
        
        // Kiem tra xem thang bang mot nua (v / 2) da xuat hien chua (v phai chia het cho 2)
        if (v % 2 == 0) {
            int half_v = v / 2;
            if (visited[half_v + 1000] > 0) {
                return true;
            }
        }
        
        // 3. Danh dau gia tri hien tai da gap
        visited[v + 1000]++;
    }
    
    return false;
}