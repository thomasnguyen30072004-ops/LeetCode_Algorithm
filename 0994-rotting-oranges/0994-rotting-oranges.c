#include <stdio.h>
#include <stdlib.h>

// Cau truc luu toa do o ma tran trong hang doi Queue
typedef struct {
    int r;
    int c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Khoi tao Queue bang mang tinh
    Point queue[1000];
    int head = 0, tail = 0;
    int freshOranges = 0;
    
    // Quet mang lan dau: Dem cam tuoi va day toan bo cam thoi F0 vao Queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[tail].r = i;
                queue[tail].c = j;
                tail++;
            } else if (grid[i][j] == 1) {
                freshOranges++;
            }
        }
    }
    
    // Neu ngay tu dau khong co qua cam tuoi nao, ton 0 phut
    if (freshOranges == 0) return 0;
    
    int minutes = 0;
    // Mang huong di: Len, Xuong, Trai, Phai
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    // Chay BFS theo tung lop thoi gian (tung phut)
    while (head < tail && freshOranges > 0) {
        // Lay so luong cam thoi hien tai cua phut nay de xu ly dong thoi
        int size = tail - head; 
        
        for (int i = 0; i < size; i++) {
            Point curr = queue[head++];
            
            // Lay lan sang 4 huong xung quanh
            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];
                
                // Kiem tra toa do hop le va phai la cam tuoi ('1')
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // Bien thanh cam thoi
                    freshOranges--;   // Giam so cam tuoi
                    
                    // Day qua cam moi thoi vao Queue de phut sau di lay tiep
                    queue[tail].r = nr;
                    queue[tail].c = nc;
                    tail++;
                }
            }
        }
        minutes++; // Ket thuc mot dot lay lan dong loat trong 1 phut
    }
    
    return (freshOranges == 0) ? minutes : -1;
}