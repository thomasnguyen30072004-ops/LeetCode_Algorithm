#include <stdio.h>

// Ham bo tro DFS dung de loang va "nhan chim" toan bo hon dao
void sinkIsland(char** grid, int m, int n, int r, int c) {
    // Dieu kien dung de quy: Neu vuot qua bien ma tran hoac gap o nuoc ('0')
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
        return;
    }
    
    // Bien o dat lien hien tai thanh nuoc de danh dau la da quet qua
    grid[r][c] = '0';
    
    // Loang tiep ra 4 huong xung quanh
    sinkIsland(grid, m, n, r - 1, c); // Len tren
    sinkIsland(grid, m, n, r + 1, c); // Xuong duoi
    sinkIsland(grid, m, n, r, c - 1); // Sang trai
    sinkIsland(grid, m, n, r, c + 1); // Sang phai
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    
    int m = gridSize;          // So hang
    int n = gridColSize[0];    // So cot
    int islandCount = 0;
    
    // Duyet qua tung o cua ma tran bieu do
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Neu phat hien thay dat lien ('1'), chung to day la mot hon dao moi
            if (grid[i][j] == '1') {
                islandCount++;
                // Dung DFS de quet sach va lam chim hon dao nay
                sinkIsland(grid, m, n, i, j);
            }
        }
    }
    
    return islandCount;
}