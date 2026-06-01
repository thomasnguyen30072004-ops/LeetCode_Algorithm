#include <stdlib.h>
#include <string.h>

char* makeGood(char* s) {
    int len = strlen(s);
    
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1; // Stack rong khi top = -1
    
    for (int i = 0; i < len; i++) {
        // Neu Stack khong rong va ky tu hien tai triet tieu voi ky tu dinh Stack
        if (top >= 0 && abs(s[i] - stack[top]) == 32) {
            top--; // Pop khoi Stack (huy cap ky tu xau)
        } else {
            stack[++top] = s[i]; // Push ky tu vao Stack
        }
    }
    
    // Them ky tu ket thuc chuoi tai vi tri ke tiep cua dinh Stack
    stack[top + 1] = '\0';
    
    return stack;
}