#include <stdlib.h>
#include <stdio.h>

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
void main(){
    struct Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 15);
    root = insertNode(root, 15);
    root = insertNode(root, 15);
    root = insertNode(root, 15);
}