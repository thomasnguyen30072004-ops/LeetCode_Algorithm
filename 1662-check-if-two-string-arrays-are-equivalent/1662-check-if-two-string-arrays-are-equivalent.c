#include <stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    // Khoi tao cac con tro vi tri
    int p1 = 0, p2 = 0; // Chi so cua chuoi trong mang
    int i = 0, j = 0;   // Chi so cua ky tu trong chuoi

    // Duyet den khi mot trong hai mang het chuoi de xet
    while (p1 < word1Size && p2 < word2Size) {
        // Neu ky tu hien tai khong giong nhau thi sai luon
        if (word1[p1][i] != word2[p2][j]) {
            return false;
        }

        // Tang con tro ky tu len de xet ky tu tiep theo
        i++;
        j++;

        // Neu da duyet het ky tu cua chuoi hien tai trong word1
        if (word1[p1][i] == '\0') {
            p1++; // Chuyen sang chuoi tiep theo trong mang
            i = 0; // Reset index ky tu ve dau chuoi moi
        }

        // Neu da duyet het ky tu cua chuoi hien tai trong word2
        if (word2[p2][j] == '\0') {
            p2++; // Chuyen sang chuoi tiep theo trong mang
            j = 0; // Reset index ky tu ve dau chuoi moi
        }
    }

    // Neu ca hai mang deu duoc duyet het cung mot luc thi hop le
    return (p1 == word1Size && p2 == word2Size);
}