// PENDING CODE

#include<stdio.h>
#include<stdlib.h>
struct btree{
  int data;
  struct btree* right;
  struct btree* left;
};
struct btree* insert(int x){
    struct btree* newnode = (struct btree*)malloc(sizeof(struct btree));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right =NULL;
    return newnode;
}
struct btree* recursiveInsertion(struct btree* root, int x){
    if(root==NULL){
        return insert(x);
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
 
struct btree* MinimumElement(struct btree* root)
{
    struct btree* temp = root;
    while((temp!=NULL)&&(temp->left!=NULL)){
        temp = temp->left;
    }
    return temp;
}

struct btree* Delete(struct btree* root, int n)
{
    if(root==NULL)
       return root;
    if(root->data<n)
    {
        
    }
    else if(root->data>n)
    {
        
    }
    else 
    {  if((root->left==NULL)&&(root->right=NULL)){
        
       }
       else if(root->left==NULL)
       {
           
       }
       else if(root->right==NULL)
       {
           
       }
    }
}

int main(){
    struct btree* root = NULL;
    
    //root = insert(root,10);
    root = recursiveInsertion(root,50);
    root = recursiveInsertion(root,30);
    root = recursiveInsertion(root,20);
    root = recursiveInsertion(root,40);
    root = recursiveInsertion(root,70);
    root = recursiveInsertion(root,60);
    root = recursiveInsertion(root,80);    
    //root = recursiveInsertion(root,50);
    display(root);
    return 0;
}
