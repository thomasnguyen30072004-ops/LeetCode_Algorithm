#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc de luu trong Stack
typedef struct {
    char ch;
    int count;
} Node;

char* removeDuplicates(char* s, int k) {
    int len = strlen(s);
    
    // Cap phat mang lam Stack
    Node* stack = (Node*)malloc(len * sizeof(Node));
    int top = -1;

    for (int i = 0; i < len; i++) {
        // Neu Stack khong rong va ky tu giong chu o dinh Stack
        if (top >= 0 && stack[top].ch == s[i]) {
            stack[top].count++;
            // Du so luong k thi xoa khoi Stack
            if (stack[top].count == k) {
                top--;
            }
        } else {
            // Ky tu moi hoac Stack rong thi push vao
            top++;
            stack[top].ch = s[i];
            stack[top].count = 1;
        }
    }

    // Build lai chuoi ket qua tu cac ky tu con sot lai trong Stack
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < stack[i].count; j++) {
            result[idx++] = stack[i].ch;
        }
    }
    result[idx] = '\0';

    free(stack);
    return result;
}