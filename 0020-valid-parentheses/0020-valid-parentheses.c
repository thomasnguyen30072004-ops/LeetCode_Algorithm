#include <stdbool.h>
#include <string.h>

bool isValid(char *s){
    int len = strlen(s);
    if (len % 2 != 0) return false; // Neu chieu dai khong chia het cho 2 thi le nen ko ghep cap duoc

    char stack[len]; // Tao stack bang mang voi kich thuoc bang chieu dai chuoi
    int top = -1; // Stack rong khi top = -1;

    for (int i=0; i<len; i++){
        char c = s[i];
        if (c == '(' || c == '[' || c == '{'){
            stack[++top] = c; // top++; stack[top] = c;
        } else {
            if (top == -1) return false;

            char open = stack[top--]; // Lay phan tu o dinh stack ra de kiem tra

            // Kiem tra xem co khop cap hay khong
            if (c == ')' && open != '(') return false;
            if (c == ']' && open != '[') return false;
            if (c == '}' && open != '{') return false;
        }
    }

    return top == -1; // Neu top = -1 => tat ca deu hop le
}