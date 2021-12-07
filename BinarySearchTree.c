// Binary Search Tree : Recursive Insertion  -----------  Inorder Traversal


include<stdio.h>
#include<stdlib.h>
struct btree{
  int data;
  struct btree* right;
  struct btree* left;
};
struct btree* insert(struct btree* root, int x){
    struct btree* newnode = (struct btree*)malloc(sizeof(struct btree));
    newnode->data = x;
    newnode->left = root;
    newnode->right = root;
    root=newnode;
    return root;
}
struct btree* recursiveInsertion(struct btree* root, int x){
    if(root==NULL){
    struct btree* newnode = (struct btree*)malloc(sizeof(struct btree));
    newnode->data = x;
    newnode->left= NULL;
    newnode->right= NULL;
    return newnode;
    }
    else
    {
        if(root->data<x)
        {
            root->right = recursiveInsertion(root->right,x);
        }
        else
        {
            root->left=recursiveInsertion(root->left,x);
        }
    }
    return root;
}
void display(struct btree* root){
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf( "%d\t",root->data);
    display(root->right);
}
 
int main(){
    struct btree* root = NULL;
    root = insert(root,10);
    root = recursiveInsertion(root,20);
    root = recursiveInsertion(root,30);
    root = recursiveInsertion(root,5);
    root = recursiveInsertion(root,40);
    root = recursiveInsertion(root,18);
    root = recursiveInsertion(root,15);    
    root = recursiveInsertion(root,50);
    display(root);
    return 0;
}
