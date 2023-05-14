#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

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

void levelTraversal(struct Node* root){
    queue<struct Node*> q;
    if(root == NULL){
        cout<<"The tree is empty";
    }
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<"\t";
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        q.pop();
    }
}

int main(){
    struct Node* root = NULL;

    root = insertNode(root, 15);
    root = insertNode(root, 11);
    root = insertNode(root, 14);
    root = insertNode(root, 16);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);

    queue<int> q;
    levelTraversal(root);

    return 0;
}