#include <stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int w1=0, i=0; // con tro cho word1
    int w2=0, j=0; // con tro cho word2

    while (w1 < word1Size && w2 < word2Size){
        if (word1[w1][i] != word2[w2][j]){
            return false; // So sanh tung phan tu trong chuoi
        }

        i++;
        j++;

        // Neu het chuoi thi chuyen sang chuoi ke tiep
        if (word1[w1][i] == '\0'){
            w1++;
            i=0;
        }

        if (word2[w2][j] == '\0'){
            w2++;
            j=0;
        }
    }

    return (w1 == word1Size && w2 == word2Size);
}