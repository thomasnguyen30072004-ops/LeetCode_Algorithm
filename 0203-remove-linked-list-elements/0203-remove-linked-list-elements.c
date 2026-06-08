#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua Linked List tren Leetcode
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Tao mot nut gia de lam diem tua dung truoc head
    struct ListNode dummy;
    dummy.next = head;
    
    // Dung con tro curr bat dau tu nut gia de duyet danh sach
    struct ListNode* curr = &dummy;
    
    while (curr->next != NULL) {
        // Neu nut tiep theo can xoa
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next; // Giu lai de free bo nho
            curr->next = curr->next->next;      // Nhay qua nut can xoa
            free(temp);                         // Giai phong bo nho cua nut bi xoa
        } else {
            // Neu khong xoa thi dich con tro curr len tiep
            curr = curr->next;
        }
    }
    
    // Tra ve dau danh sach moi nam sau nut gia
    return dummy.next;
}