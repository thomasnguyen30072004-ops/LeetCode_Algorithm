#include <stdbool.h>

bool judgeCircle(char* moves) {
    int x = 0; 
    int y = 0; 
    
    // Duyet qua tung ky tu trong chuoi cho den khi gap ky tu ket thuc chuoi '\0'
    for (int i = 0; moves[i] != '\0'; i++) {
        switch (moves[i]) {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
        }
    }
    
    // Robot ve lai vi tri cu khi va chi khi ca x va y deu bang 0
    return (x == 0 && y == 0);
}