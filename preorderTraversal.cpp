#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insertNode(struct Node* root, int data){
    if(root == NULL) {
        root = newNode(data);

    } 
    else if(data<=root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}
void main(){
    struct Node* root =NULL;
    insertNode(root,15);
}