double findMaxAverage(int* nums, int numsSize, int k) {
    // Tinh tong cua cua so dau tien (k phan tu dau)
    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    
    long long max_sum = current_sum;
    
    for (int i = k; i < numsSize; i++) {
        // Cong phan tu moi vao ben phai, tru phan tu cu o ben trai
        current_sum += nums[i] - nums[i - k];
        
        // Cap nhat lai tong lon nhat nhat neu tim thay tong lon hon
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    // Tra ve gia tri trung binh lon nhat 
    return (double)max_sum / k;
}