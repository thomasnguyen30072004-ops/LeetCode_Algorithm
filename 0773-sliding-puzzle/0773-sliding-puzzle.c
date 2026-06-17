#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Cau truc luu trang thai trong hang doi Queue
typedef struct {
    char str[7]; // Chuoi 6 ky tu + 1 ky tu '\0'
    int steps;
} State;

// Ban do di chuyen hop le cua so 0 dua tren tung vi tri index (0 den 5)
const int dirs[6][4] = {
    {1, 3, -1, -1},    // Index 0 doi duoc voi 1, 3
    {0, 2, 4, -1},    // Index 1 doi duoc voi 0, 2, 4
    {1, 5, -1, -1},    // Index 2 doi duoc voi 1, 5
    {0, 4, -1, -1},    // Index 3 doi duoc voi 0, 4
    {1, 3, 5, -1},    // Index 4 doi duoc voi 1, 3, 5
    {2, 4, -1, -1}     // Index 5 doi duoc voi 2, 4
};

// Ham kiem tra xem chuoi da tung xuat hien trong danh sach visited chua
bool isVisited(char visited[][7], int visitedCount, char* target) {
    for (int i = 0; i < visitedCount; i++) {
        if (strcmp(visited[i], target) == 0) {
            return true;
        }
    }
    return false;
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    // Ep phang mang 2 chieu thanh chuoi
    char startStr[7];
    int p = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            startStr[p++] = board[i][j] + '0';
        }
    }
    startStr[6] = '\0';
    
    char targetStr[] = "123450";
    
    // Neu trang thai dau giong het dich thi return 0 luon
    if (strcmp(startStr, targetStr) == 0) return 0;
    
    // Khoi tao mang Queue va Visited set (Toi da 720 trang thai khac nhau)
    State queue[1000];
    char visited[1000][7];
    int head = 0, tail = 0;
    int visitedCount = 0;
    
    // Day phan tu dau tien vao Queue va Visited
    strcpy(queue[tail].str, startStr);
    queue[tail].steps = 0;
    tail++;
    
    strcpy(visited[visitedCount++], startStr);
    
    // 2. Chay vong lap BFS
    while (head < tail) {
        State curr = queue[head++];
        
        // Neu cham den dich, return so buoc
        if (strcmp(curr.str, targetStr) == 0) {
            return curr.steps;
        }
        
        // Tim vi tri cua ky tu '0'
        int zeroIdx = 0;
        while (curr.str[zeroIdx] != '0') zeroIdx++;
        
        // Duyet qua cac huong di hop le tu vi tri zeroIdx
        for (int i = 0; i < 4; i++) {
            int nextIdx = dirs[zeroIdx][i];
            if (nextIdx == -1) break; // Het huong di hop le
            
            // Tao chuoi moi bang cach hoan doi (swap)
            char nextStr[7];
            strcpy(nextStr, curr.str);
            
            char temp = nextStr[zeroIdx];
            nextStr[zeroIdx] = nextStr[nextIdx];
            nextStr[nextIdx] = temp;
            
            // Neu trang thai moi nay chua tung duoc quet qua
            if (!isVisited(visited, visitedCount, nextStr)) {
                // Them vao visited
                strcpy(visited[visitedCount++], nextStr);
                
                // Day vao duoi hang doi Queue
                strcpy(queue[tail].str, nextStr);
                queue[tail].steps = curr.steps + 1;
                tail++;
            }
        }
    }
    
    return -1;
}