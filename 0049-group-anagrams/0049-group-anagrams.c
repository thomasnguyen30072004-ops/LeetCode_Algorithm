#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Dinh nghia cau truc de luu thong tin tung chuoi
typedef struct {
    char* original; // Con tro tro toi chuoi goc trong mang strs
    char* sorted;   // Chuoi da duoc sap xep de lam khoa (Key)
} WordNode;

// Ham so sanh hai ky tu (dung cho qsort sap xep ky tu trong chuoi)
int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

// Ham so sanh hai WordNode dua tren chuoi da sap xep (dung de gom nhom)
int compareNodes(const void* a, const void* b) {
    return strcmp(((WordNode*)a)->sorted, ((WordNode*)b)->sorted);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * returnColumnSizes must be malloced too, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Cap phat mang cac Node de xu ly
    WordNode* nodes = (WordNode*)malloc(strsSize * sizeof(WordNode));
    for (int i = 0; i < strsSize; i++) {
        nodes[i].original = strs[i];
        nodes[i].sorted = strdup(strs[i]); // Copy chuoi de sap xep
        qsort(nodes[i].sorted, strlen(nodes[i].sorted), sizeof(char), compareChars);
    }

    // Sap xep mang cac Node. Cac chuoi la Anagram cua nhau se nam canh nhau
    qsort(nodes, strsSize, sizeof(WordNode), compareNodes);

    // Cap phat mang ba chieu de chua ket qua cuoi cung
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    int groupCount = 0;

    int i = 0;
    while (i < strsSize) {
        int j = i;
        // Tim xem co bao nhieu chuoi co cung khoa 'sorted' giong nhau
        while (j < strsSize && strcmp(nodes[i].sorted, nodes[j].sorted) == 0) {
            j++;
        }

        int currentGroupSize = j - i;
        // Cap phat bo nho cho nhom hien tai
        result[groupCount] = (char**)malloc(currentGroupSize * sizeof(char*));
        (*returnColumnSizes)[groupCount] = currentGroupSize;

        // Dua cac chuoi goc vao nhom
        for (int k = 0; k < currentGroupSize; k++) {
            result[groupCount][k] = nodes[i + k].original;
        }

        groupCount++;
        i = j; // Chuyen sang nhom tiep theo
    }

    *returnSize = groupCount;

    // Giai phong bo nho dem dung de lam khoa sorted
    for (int i = 0; i < strsSize; i++) {
        free(nodes[i].sorted);
    }
    free(nodes);

    return result;
}