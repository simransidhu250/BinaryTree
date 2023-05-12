#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


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

bool  Search(struct Node* root, int val){
    if(root == NULL) return false;
    else if(root->data == val) return true;
    else if(val < root->data) return Search(root->left, val);
    else return Search(root->right, val);

}
void main(){
    struct Node* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 11);
    root = insertNode(root, 14);
    root = insertNode(root, 16);
    root = insertNode(root, 8);

    int n=0;
    printf("Enter the number you want to search in binary tree: ");
    scanf("%d", &n);
    if(Search(root,n)== true)
        printf("Number found\n");
    else
        printf("Number not found\n");

}