#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* insertAtBeg( struct node* head, int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
    return head;
}
struct node* insertAtEnd( struct node* head, int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    struct node* ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=  ptr->next;
    }
    ptr->next = newnode;
    return head;
}
struct node* insertInMiddle( struct node* head, int prev, int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    struct node* ptr =head;
    while(ptr->next->data!=prev){
     ptr = ptr->next;
    }
    ptr=ptr->next;
    newnode->next = ptr->next;
    ptr->next=newnode;/*
    if((ptr->next==NULL)&&(ptr->data==x)){
        
     }
    }*/
    return head;
}
void display( struct node* ptr)
{
    if(ptr==NULL)
    {
        printf("\nEmpty list!!\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr= ptr->next;
    }
}

struct node* DeleteFromBeg(struct node* head)
{
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node* DeleteFromEnd( struct node* head)
{
    struct node* ptr = head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct node* temp = ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}

int main()
{
    struct node* head= NULL;
    printf("\nNew element : 10 (Inserted in beginning)\n");
    head=insertAtBeg(head,10);
    display(head);
    printf("\nNew element : 20 (Inserted in beginning)\n");
    head=insertAtBeg(head,20);
    display(head);
    printf("\nNew element : 30 (Inserted in beginning)\n");
    head=insertAtBeg(head,30);
    display(head);
    printf("\n");
    head=insertAtEnd(head,40);
    printf("\nNew element : 40 (Inserted at end) \n");
    display(head);
    head=insertAtEnd(head,60);
    printf("\nNew element : 60 (Inserted at end)\n");
    display(head);
    printf("\n");
    head=insertInMiddle(head,20,50);
    printf("\nNew element : 50 to be inserted after 20\n");
    display(head);
    head=insertInMiddle(head,60,70);
    printf("\nNew element : 70 to be inserted after 60\n");
    display(head);
    printf("\n");
    head = DeleteFromBeg(head);
    printf("\nDeletion From Beginning!\n");
    display(head);
    printf("\n");
    head = DeleteFromBeg(head);
    printf("\nDeletion From Beginning!\n");
    display(head);
    printf("\n");
    head = DeleteFromEnd(head);
    printf("\nDeletion From End!\n");
    display(head);
    printf("\n");
    head = DeleteFromEnd(head);
    printf("\nDeletion From End!\n");
    display(head);
    printf("\n");
    return 0;
}
