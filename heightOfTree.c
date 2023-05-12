#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* temp =  (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right  = NULL;
    return temp;
}

struct Node* insertNode(struct Node* root,int val){  
    if(root == NULL){
        root = newNode(val);
    }
    else if(root->data>val) root->left = insertNode(root->left, val);
    else if(root->data<val) root->right =insertNode(root->right, val);  
    return root;
}

int FindHeight(struct Node* root){
    if(root == NULL){
        return -1;
    }
    return __max(FindHeight(root->left), FindHeight(root->right))+1;
}

void main(){
    struct Node* root = NULL;

    root = insertNode(root, 15);
    root = insertNode(root, 11);
    root = insertNode(root, 14);
    root = insertNode(root, 16);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);

    int height = FindHeight(root);
    printf("Max height of tree is: %d", height);
}