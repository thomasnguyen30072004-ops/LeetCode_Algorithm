#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc Linked List tren Leetcode
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* partition(struct ListNode* head, int x) {
    // Tao 2 nut gia de lam diem tua cho 2 nhanh
    struct ListNode beforeHead;
    struct ListNode afterHead;
    
    // Con tro dung de chay va build danh sach cho 2 nhanh
    struct ListNode* before = &beforeHead;
    struct ListNode* after = &afterHead;
    
    // Con tro dung de duyet qua danh sach goc
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val < x) {
            before->next = curr; // Cam vao nhanh nho hon x
            before = before->next; // Dich con tro truoc len
        } else {
            after->next = curr;  // Cam vao nhanh lon hon hoac bang x
            after = after->next;  // Dich con tro sau len
        }
        curr = curr->next; // Chuyen sang nut tiep theo cua mang goc
    }
    
    // Chot chan quan trong: Cat duoi nhanh lon de tranh bi vong lap vo han (cycle)
    after->next = NULL;
    
    // Noi duoi cua nhanh nho vao dau cua nhanh lon (bo qua nut gia afterHead)
    before->next = afterHead.next;
    
    // Tra ve dau danh sach moi (bo qua nut gia beforeHead)
    return beforeHead.next;
}