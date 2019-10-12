#include <stdio.h>
#include <malloc.h>
#include "Node.h"

void            preOrder(struct Node *);
void            deleteTree(struct Node *);
void            mirrorATree(struct Node *);

int             heightOfATree(struct Node*);
int             max(int, int);
int             diameterOfATree(struct Node*);

struct Node*    addNewNode(struct Node *root, int data);
struct Node*    deleteANode(struct Node *, int data);
struct Node*    inorderPredecessor(struct Node*);
struct Node*    inorderSuccessor(struct Node*);


int main() {

    struct Node* root = NULL;
    root = malloc(sizeof (*root));
    root->data = 19;

    addNewNode(root, 10);
    addNewNode(root, 16);
    addNewNode(root, 120);
    addNewNode(root, 210);
    addNewNode(root, 30);
    addNewNode(root, 211);
    addNewNode(root, 11);
    preOrder(root);
//    
//    struct Node* inPreNode = inorderPredecessor(root);
//    printf("Inorder Predecessor of Root -> %d\n", inPreNode -> data);
//    
//    struct Node* inSuccNode = inorderSuccessor(root);
//    printf("Inorder Successor of Root -> %d\n", inSuccNode -> data);
//    
//    deleteANode(root, 120);
//    preOrder(root);
//
//    deleteTree(root);
//    root = NULL;
//    preOrder(root);
    
    int treeHeight = heightOfATree(root);
    printf("Tree Height = %d.\n", treeHeight);
    
    int treeDiameter = diameterOfATree(root);
    printf("Tree Diameter = %d.\n", treeDiameter);
    
    mirrorATree(root);
    preOrder(root);
    
    return 1;
}

void mirrorATree(struct Node* root) {
    if (root != NULL) {
        struct Node* leftSubTree    =   root->left;
        struct Node* rightSubTree   =   root->right;

        root->left  = rightSubTree;
        root->right = leftSubTree;

        mirrorATree(root->left);
        mirrorATree(root->right);
    }

}

int diameterOfATree(struct Node* root) {
    if(root == NULL) return 0;
    
    int leftTreeHeight  =   heightOfATree(root->left);
    int rightTreeHeight  =   heightOfATree(root->right);
    int leftDia     =   diameterOfATree(root->left);
    int rightDia    =   diameterOfATree(root->right);
    
    int finalDiameter = max(leftTreeHeight + rightTreeHeight + 1, max(leftDia, rightDia));
    printf("Diameter for Node(%d) = %d.\n", root->data, finalDiameter);
    
    return finalDiameter;
}

struct Node* inorderPredecessor(struct Node* root) {
    if(root == NULL) return NULL;
    struct Node* ptrToCurrNode = root -> left;
    
    while(ptrToCurrNode != NULL && ptrToCurrNode -> right != NULL) ptrToCurrNode = ptrToCurrNode -> right;
    
    return ptrToCurrNode;
}

struct Node* inorderSuccessor(struct Node* root) {
    if(root == NULL) return NULL;
    struct Node* ptrToCurrNode = root->right;
    
    while(ptrToCurrNode != NULL && ptrToCurrNode -> left != NULL) ptrToCurrNode = ptrToCurrNode -> left;
    
    return ptrToCurrNode;
}

struct Node* deleteANode(struct Node *root, int data) {
    if (root == NULL) return NULL;

//    printf("Deleteing %d from %d \n", data, root->data);
    struct Node *ptrToPrevNode = NULL;
    struct Node *ptrToCurrNode = root;

    while (ptrToCurrNode != NULL && ptrToCurrNode -> data != data) {
        ptrToPrevNode = ptrToCurrNode;
        if (ptrToCurrNode -> data < data) ptrToCurrNode = ptrToCurrNode->right;
        else if (ptrToCurrNode -> data > data) ptrToCurrNode = ptrToCurrNode -> left;
        else break;
    }

//    printf("ptrToCurrNode -> %d\n", ptrToCurrNode -> data);
    //If Node is present
    if (ptrToCurrNode != NULL) {
        //If Leaf Node
        //then remove pointers to it from it's root and free the memory
        if (ptrToCurrNode -> left == NULL && ptrToCurrNode -> right == NULL) {
            if (ptrToPrevNode  != NULL && ptrToPrevNode -> left != NULL && ptrToPrevNode -> left == ptrToCurrNode) ptrToPrevNode -> left = NULL;
            if (ptrToPrevNode  != NULL && ptrToPrevNode -> right != NULL && ptrToPrevNode -> right == ptrToCurrNode) ptrToPrevNode -> right = NULL;
            free(ptrToCurrNode);
            return NULL;
        }
        
        //hasSingleChild
        //If has right child then find the inorder successor
        //copy the value and delete the successor by recursive call
        if (ptrToCurrNode -> left == NULL && ptrToCurrNode -> right != NULL) {
            struct Node* inorderSuccessorNode   =   inorderSuccessor(ptrToCurrNode);
            ptrToCurrNode -> data   =   inorderSuccessorNode -> data;
            ptrToCurrNode -> right  =   deleteANode(ptrToCurrNode -> right, inorderSuccessorNode -> data);
        } else {
            //if has the left child then 
            //find and copy the data from inorder predecessor and 
            //delete the predecessor by recursive call
            struct Node* inorderPredecessorNode =   inorderPredecessor(ptrToCurrNode);
            ptrToCurrNode -> data   =   inorderPredecessorNode -> data;
            ptrToCurrNode -> left   =   deleteANode(ptrToCurrNode -> left, inorderPredecessorNode -> data);
        }
    }
    return ptrToCurrNode;
}

void preOrder(struct Node* root) {
    if (root == NULL) return;

    printf("%d\n", root->data);
    preOrder(root -> left);
    preOrder(root -> right);
}

int heightOfATree(struct Node* root) {
    if(root == NULL) return 0;
    return 1 + max(heightOfATree(root->left), heightOfATree(root->right));
}

int max(int x, int y) {
    return x >= y ? x : y;
}
//free memory from bottom to top	-	recursively
void deleteTree(struct Node *root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

struct Node* addNewNode(struct Node *root, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof (struct Node *));
    newNode -> data = data;
    if (root == NULL) newNode;

    struct Node *ptrToPrevNode = root;
    struct Node *ptrToCurrNode = root;

    while (ptrToCurrNode != NULL) {
        ptrToPrevNode = ptrToCurrNode;
        if (ptrToCurrNode -> data < data) {
            ptrToCurrNode = ptrToCurrNode->right;
        } else {
            ptrToCurrNode = ptrToCurrNode -> left;
        }
    }

    //add the newNode here
    if (ptrToPrevNode -> data > data) ptrToPrevNode -> left = newNode;
    else ptrToPrevNode -> right = newNode;

    root;
}


