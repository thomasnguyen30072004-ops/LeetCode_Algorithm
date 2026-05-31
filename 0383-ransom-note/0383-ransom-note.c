#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int char_counts[26] = {0};
    
    for (int i = 0; magazine[i] != '\0'; i++) {
        // Lay ky tu tru di 'a' de ra chi so tu 0 den 25
        char_counts[magazine[i] - 'a']++;
    }
    
    // Kiem tra xem magazine co du ky tu cho ransomNote khong
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = ransomNote[i] - 'a';
        char_counts[index]--;
        
        if (char_counts[index] < 0) {
            return false;
        }
    }
    
    return true;
}