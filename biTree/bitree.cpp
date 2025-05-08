#include "bitree.h"
#include <queue>

// 创建节点
BiTreeNode* createNode(int data) {
    BiTreeNode* newNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点
BiTreeNode* insertNode(BiTreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// 查找节点
BiTreeNode* searchNode(BiTreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// 删除节点
BiTreeNode* deleteNode(BiTreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // 找到要删除的节点
        if (root->left == NULL) {
            BiTreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BiTreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // 找到右子树的最小值替代当前节点
        BiTreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 中序遍历
void inorderTraversal(BiTreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 前序遍历
void preorderTraversal(BiTreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 后序遍历
void postorderTraversal(BiTreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// 层序遍历
void levelOrderTraversal(BiTreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::queue<BiTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BiTreeNode* current = q.front();
        q.pop();
        printf("%d ", current->data);
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

// 释放二叉树
void freeTree(BiTreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    BiTreeNode* root = NULL;

    // 插入节点
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // 遍历
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // 查找节点
    BiTreeNode* found = searchNode(root, 40);
    if (found) {
        printf("Node with value 40 found.\n");
    } else {
        printf("Node with value 40 not found.\n");
    }

    // 删除节点
    root = deleteNode(root, 50);
    printf("Inorder Traversal after deleting 50: ");
    inorderTraversal(root);
    printf("\n");

    // 释放二叉树
    freeTree(root);

    return 0;
}