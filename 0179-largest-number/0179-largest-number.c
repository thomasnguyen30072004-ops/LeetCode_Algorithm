#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ham so sanh custom dung cho qsort
int compare(const void* a, const void* b) {
    char ab[50];
    char ba[50];
    
    // Ghep chuoi AB (Lay so thu nhat ghep voi so thu hai)
    strcpy(ab, *(const char**)a);
    strcat(ab, *(const char**)b);
    
    // Ghep chuoi BA (Lay so thu hai ghep voi so thu nhat)
    strcpy(ba, *(const char**)b);
    strcat(ba, *(const char**)a);
    
    // So sanh nguoc de sap xep giam dan (thang nao tao chuoi lon hon se dung truoc)
    return strcmp(ba, ab); 
}

char* largestNumber(int* nums, int numsSize) {
    // Cap phat mang cac chuoi ky tu de chua cac so da chuyen doi
    char** strNums = (char**)malloc(numsSize * sizeof(char*));
    int totalLength = 0;
    
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = (char*)malloc(20 * sizeof(char));
        sprintf(strNums[i], "%d", nums[i]); // Chuyen so thanh chuoi
        totalLength += strlen(strNums[i]);
    }
    
    // Sắp xếp mảng chuỗi theo quy tac so sanh custom (O(N log N))
    qsort(strNums, numsSize, sizeof(char*), compare);
    
    // Bay truong hop bien: Neu so lon nhat sau khi sort la "0", thi ca mang toan so 0
    if (strcmp(strNums[0], "0") == 0) {
        // Giai phong bo nho truoc khi return
        for (int i = 0; i < numsSize; i++) free(strNums[i]);
        free(strNums);
        
        char* zero = (char*)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }
    
    // Cap phat bo nho cho chuoi ket qua cuoi cung
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0'; // Khoi tao chuoi rong
    
    // Noi cac chuoi lai voi nhau sau khi da dat dung vi tri
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
        free(strNums[i]); // Xoa vung nho tam thoi cua tung chuoi
    }
    free(strNums); 
    
    return result;
}