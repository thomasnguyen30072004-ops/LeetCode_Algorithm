#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua Linked List tren Leetcode
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

void deleteNode(struct ListNode* node) {
    // Giu lai con tro cua nut ke tiep de free sau khi xoa
    struct ListNode* temp = node->next;
    
    // Copy gia tri cua nut ke tiep ghi de len nut hien tai
    node->val = temp->val;
    
    // Be con tro next cua nut hien tai nhay qua nut ke tiep
    node->next = temp->next;
    
    // Giai phong bo nho cua nut ke tiep (nut thuc su bi loai bo)
    free(temp);
}