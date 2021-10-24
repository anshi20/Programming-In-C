// Counting no. of nodes in linked list

#include<stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=head;
    head=temp;
}
void display()
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
int count()
{
    int no_of_nodes=0;
    if(head==NULL)
       {
           printf("\nList is empty!\n");
           return 0;
       }
    else
       {   
           struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
           temp=head;
           while(temp!=NULL)
           {   
               no_of_nodes++;
               temp=temp->next;
           }
       }
       return no_of_nodes;
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
    int choice,num,position;
    do{
    printf("\n                                              MENU\n");
    printf("1. Insertion \t\t2. Deletion \t\t3. Count Elements \t\t4.Display List \t\t5. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
     {
        case 1 : printf("\nEnter the element : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
        case 2 : printf("\nEnter position of element to be deleted : ");
                 scanf("%d",&position);
                 delete(position);
                 break;
        case 3 : printf("\n No. of nodes in linked list : %d",count());
                 break;
        case 4 : printf("\nDisplaying linked list.......\n");
                 display();
                 break;
        case 5 : printf("Exiting\n");
                 exit(0);
        default: printf("Invalid choice!!");
     }
     
    }while(choice);
    
    return 0;
}
