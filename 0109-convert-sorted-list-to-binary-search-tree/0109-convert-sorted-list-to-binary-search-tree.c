#include <stdio.h>
#include <stdlib.h>

// Ham khoi tao mot nut cay moi
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Ham de quy bien doi Linked List thanh BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    // Truong hop co so: list rong
    if (head == NULL) return NULL;
    
    // Truong hop co so: list chi co 1 phan tu
    if (head->next == NULL) {
        return createTreeNode(head->val);
    }
    
    // Dung thuat toan Fast & Slow pointer de tim phan tu giua (Mid)
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL; // Luu nut dung truoc slow de cat chuoi
    
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Luc nay 'slow' chinh la nut o chinh giua (Mid) -> lam Root
    struct TreeNode* root = createTreeNode(slow->val);
    
    // Be doi Linked List tai vi tri truoc 'slow' de co lap nhanh ben trai
    if (prev != NULL) {
        prev->next = NULL;
    }
    
    // De quy xay dung cay con ben trai va ben phai
    // Nhanh trai chay tu head den truoc slow (vua duoc cat bang NULL)
    root->left = sortedListToBST(head);
    // Nhanh phai chay tu phan tu dung sau slow den het
    root->right = sortedListToBST(slow->next);
    
    return root;
}