#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
} BiTreeNode;

// 创建节点
BiTreeNode* createNode(int data);

// 插入节点
BiTreeNode* insertNode(BiTreeNode* root, int data);

// 查找节点
BiTreeNode* searchNode(BiTreeNode* root, int data);

// 删除节点
BiTreeNode* deleteNode(BiTreeNode* root, int data);

// 中序遍历
void inorderTraversal(BiTreeNode* root);

// 前序遍历
void preorderTraversal(BiTreeNode* root);

// 后序遍历
void postorderTraversal(BiTreeNode* root);

// 层序遍历
void levelOrderTraversal(BiTreeNode* root);

// 释放二叉树
void freeTree(BiTreeNode* root);

#endif // BITREE_H
