/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct tagNode {
    struct TreeNode *t;
    struct tagNode *next;
} Node;

void Push(Node *head, struct TreeNode *t)
{
    Node *n = calloc(1, sizeof(Node));
    n->t = t;
    n->next = head->next;
    head->next = n;
}

Node * Pop(Node *head)
{
    if (head->next == NULL) {
        printf("Empty\n");
        return NULL;
    }
    Node *n = head->next;
    head->next = n->next;
    return n;
}

bool IsEmpty(Node *head)
{
    return head->next == NULL ? true : false;
}

bool Inorder(struct TreeNode *t)
{
    Node *head, *node;
    long num, popdata;
    struct TreeNode *cur;

    cur = t;
    head = calloc(1, sizeof(Node));
    num = LONG_MIN;

    while (cur != NULL || !IsEmpty(head)) {
        while (cur) {
            Push(head, cur);
            cur = cur->left;
        }

        /* keep the inorder is asc order */
        node = Pop(head);
        cur = node->t;
        popdata = cur->val;
        if (popdata <= num) {
            return false;
        }
        num = popdata; 
        cur =  cur->right;
    }
    return true;
}

bool isValidBST(struct TreeNode* root)
{
    if (!root) {
        return true;
    }

    return Inorder(root);    
}
// @lc code=end

