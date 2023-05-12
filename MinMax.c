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

int FindMin(struct Node* root){
    if (root == NULL)
        return -1;
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

int FindMax(struct Node* root){
    if(root == NULL)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
    
}
void main(){
    struct Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 11);
    root = insertNode(root, 14);
    root = insertNode(root, 16);
    root = insertNode(root, 8);
    int min = FindMin(root);
    printf("Minimum value in tree is %d\n", min);
    int max = FindMax(root);
    printf("Maximum value in tree is %d\n", max);


}