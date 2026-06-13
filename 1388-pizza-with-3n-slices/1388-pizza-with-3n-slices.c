#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ham tim so lon hon
int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateMaxLinear(int* subSlices, int subSize, int n) {
    // Tao bang DP co kich thuoc (subSize + 1) x (n + 1)
    int** dp = (int**)malloc((subSize + 1) * sizeof(int*));
    for (int i = 0; i <= subSize; i++) {
        dp[i] = (int*)calloc((n + 1), sizeof(int));
    }

    for (int i = 1; i <= subSize; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1) {
                dp[i][j] = subSlices[0]; // Neu chi co 1 mieng banh
            } else {
                // Ap dung cong thuc tinh tien trang thai DP
                dp[i][j] = max(dp[i - 1][j], subSlices[i - 1] + dp[i - 2][j - 1]);
            }
        }
    }

    int result = dp[subSize][n];

    // Giai phong bo nho dong cua bang DP
    for (int i = 0; i <= subSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int maxSizeSlices(int* slices, int slicesSize) {
    int n = slicesSize / 3; // So luong mieng banh ban thuc su duoc thit

    // Truong hop 1: Bo phan tu cuoi cung (Xet tu 0 den slicesSize - 2)
    int* case1 = (int*)malloc((slicesSize - 1) * sizeof(int));
    memcpy(case1, slices, (slicesSize - 1) * sizeof(int));
    int res1 = calculateMaxLinear(case1, slicesSize - 1, n);

    // Truong hop 2: Bo phan tu dau tien (Xet tu 1 den slicesSize - 1)
    int* case2 = (int*)malloc((slicesSize - 1) * sizeof(int));
    memcpy(case2, slices + 1, (slicesSize - 1) * sizeof(int));
    int res2 = calculateMaxLinear(case2, slicesSize - 1, n);

    free(case1);
    free(case2);

    return max(res1, res2);
}