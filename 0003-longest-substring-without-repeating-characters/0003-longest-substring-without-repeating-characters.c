#include <string.h>

int lengthOfLongestSubstring(char* s) {

    int last_seen[256];
    for (int i = 0; i < 256; i++) {
        last_seen[i] = -1;
    }
    
    int max_len = 0;
    int left = 0; 
    
    for (int right = 0; s[right] != '\0'; right++) {
        char current_char = s[right];
        
        // Neu ky tu da tung xuat hien va vi tri cua no nam trong cua so hien tai
        if (last_seen[(unsigned char)current_char] >= left) {
            // Dich con tro left sang ben phai vi tri trung lap do 1 don vi
            left = last_seen[(unsigned char)current_char] + 1;
        }
        
        // Vi tri xuat hien moi nhat cua ky tu hien tai
        last_seen[(unsigned char)current_char] = right;
        
        // Tinh chieu dai cua so hien tai va cap nhat max_len
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}