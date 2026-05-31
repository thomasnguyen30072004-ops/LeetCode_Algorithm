void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Khoi tao 3 con tro
    int i = m - 1;       // Con tro cuoi phan tu hop le cua nums1
    int j = n - 1;       // Con tro cuoi phan tu cua nums2
    int k = m + n - 1;   // Con tro vi tri dien o cuoi mieu cua nums1

    // Duyet khi ca hai mang deu con phan tu
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Neu nums2 van con phan tu (nums1 het truoc), chep not vao nums1
    // Neu nums1 con thi khong can vi no da nam dung vi tri san roi
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}