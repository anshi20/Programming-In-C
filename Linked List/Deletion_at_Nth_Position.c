
//  Deletion of element at the Nth position in linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void Insert(int x, int pos)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    if(pos==1)
    {
        temp1->data=x;
        temp1->next=head;
        head=temp1;
        return ;
    }
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node*));
    temp1=head;
    int pos1=1;
    while(pos1!=pos-1)
    {    
    temp1=temp1->next;
    pos1++;
    }
    temp2->data=x;
    temp2->next=temp1->next;
    temp1->next=temp2;
}
void Display()
{
    if(head==NULL)
       {
           printf("\nList is empty!");
           return;
       }
    else
       {
           struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
           temp=head;
           while(temp!=NULL)
           {   printf("%d\t",temp->data);
               temp=temp->next;
           }
       }
}
void delete(int del_pos)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node*));
    
    if(del_pos==1)
    {
        temp1=head;
        temp2=temp1->next;
        head=temp2;
    }
    else{
    temp1=head;
    temp2=head;
    int pos1=1;
    while(pos1!=del_pos-1)
    {    
    temp1=temp1->next;
    temp2=temp2->next;
    pos1++;
    }
    temp2=temp2->next;
    temp1->next=temp2->next;
    free(temp2);   
    }
}
int main()
{
    int i,n,num,position,del;
    printf("How many elements you want to insert in the list ? ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element : ");
        scanf("%d",&num);
        if(head!=NULL){
        printf("Enter the position : ");
        scanf("%d",&position);
        Insert(num,position);
        }
        else
        {
        Insert(num,1);
        }
    }
    printf("List now is : \n");
    Display();
    printf("\nEnter the position of element to be deleted : ");
    scanf("%d",&del);
    delete(del);
    Display();
    return 0;
}
