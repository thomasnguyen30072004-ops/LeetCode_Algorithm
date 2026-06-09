#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc Linked List tren Leetcode
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Tao mot nut gia dung truoc head de xu ly moi truong hop bien
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // 1. Cho con tro fast di truoc n buoc
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    // 2. Cho ca fast va slow cung di chuyen cho den khi fast cham den nut cuoi cung
    // (fast->next == NULL thi slow se dung ngay truoc nut can xoa)
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // 3. Tien hanh xoa nut
    struct ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next; // Nhay qua nut can xoa
    free(nodeToDelete);            // Giai phong bo nho
    
    // Tra ve head moi dung sau nut gia
    return dummy.next;
}