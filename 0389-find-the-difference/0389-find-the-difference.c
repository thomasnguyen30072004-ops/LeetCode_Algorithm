char findTheDifference(char* s, char* t) {
    char result = 0;
    
    // XOR toan bo ky tu cua chuoi s
    for (int i = 0; s[i] != '\0'; i++) {
        result ^= s[i];
    }
    
    // XOR tiep toan bo ky tu cua chuoi t
    for (int i = 0; t[i] != '\0'; i++) {
        result ^= t[i];
    }
    
    // Ket qua con lai chinh la ky tu duoc them vao
    return result;
}