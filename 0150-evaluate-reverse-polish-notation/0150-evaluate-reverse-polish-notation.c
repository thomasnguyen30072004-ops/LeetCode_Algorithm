#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ham kiem tra xem mot chuoi co phai la toan tu hay khong
int isOperator(char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0);
}

int evalRPN(char** tokens, int tokensSize) {
    // Kich thuoc Stack toi da bang so luong tokens
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1; // Stack rong khi top = -1

    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];

        if (isOperator(token)) {
            // Lay toan hang thu hai ra truoc (o dinh stack)
            int b = stack[top--];
            // Lay toan hang thu nhat ra sau
            int a = stack[top--];
            int result = 0;

            // Thuc hien phep tinh dua tren toan tu
            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else if (strcmp(token, "/") == 0) result = a / b; // De bai dam bao b != 0

            // Day ket qua phep tinh tro lai Stack
            stack[++top] = result;
        } else {
            // Neu la so, chuyen tu chuoi sang so roi push vao Stack
            stack[++top] = atoi(token);
        }
    }

    // Phan tu cuoi cung con lai trong Stack chinh la dap an
    int final_result = stack[top];
    
    // Giai phong bo nho dem cua Stack
    free(stack);

    return final_result;
}