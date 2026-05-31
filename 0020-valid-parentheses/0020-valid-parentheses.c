#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // Neu chieu dai chuoi le thi chac chan khong the khop cap
    if (len % 2 != 0) return false;
    
    // Tao stack bang mang voi kich thuoc bang chieu dai chuoi
    char stack[len];
    int top = -1; // Stack rong khi top = -1
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // Neu la dau ngoat mo, push vao stack
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        // Neu la dau ngoat dong
        else {
            // Stack rong ma gap dau ngoat dong thi sai
            if (top == -1) return false;
            
            // Lay phan tu o dinh stack ra de kiem tra
            char openBracket = stack[top--];
            
            // Kiem tra xem co khop cap hay khong
            if (c == ')' && openBracket != '(') return false;
            if (c == ']' && openBracket != '[') return false;
            if (c == '}' && openBracket != '{') return false;
        }
    }
    
    // Neu top == -1 tuc la tat ca deu duoc khop cap hop le
    return top == -1;
}