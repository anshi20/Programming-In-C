
//  Insertion of elements at the beginning of linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=head;
    head=temp;
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
int main()
{
    int i,n,num;
    printf("How many elements you want to insert in the list ? ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element : ");
        scanf("%d",&num);
        Insert(num);
        printf("List now is : \n");
        Display();
    }
    return 0;
}
