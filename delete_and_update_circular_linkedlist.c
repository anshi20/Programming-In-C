#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node** start, int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=*start;
    *start=newnode;
}

bool search(struct node* start, int key)
{   struct node* temp = start;
    do 
    {
        if(temp->data==key)
           return true;
        temp=temp->next;
    }while(temp!=start);
    return false;
}

void delete(struct node **head, int key)
{
      //temp is used to freeing the memory
      struct node *temp;
      struct node* previous = (*head);
      struct node* current = (*head);
      //key found on the head node.
      //move to head node to the next and free the head.
      if((*head)->data == key)
      {
          
          if ((*head)->next==(*head)) {
          *head = NULL;
          return;
         }
         while ((previous->next) != (*head)) {
          previous = previous->next;
         }
         previous->next = current->next;
         *head=previous->next;
         free(current);
      }
      

      else
      {
          struct node *current  = *head;
          do
          {
              //if yes, we need to delete the current->next node
              if(current->next->data == key)
              {
                  temp = current->next;
                  //node will be disconnected from the linked list.
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  current = current->next;
          }while(current->next != *head);
      }
    

}

void display(struct node* start)
{
    struct node* temp= start;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=start);
}

void makecircular(struct node** start)
{
    struct node* ptr= *start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=*start;
}

int main()
{
    struct node* start  = NULL;
    int ch=1,num;
    
    printf("\nSINGLY  LINKED  LIST\n");
    while(ch)
    {
        printf("Enter value of node to be inserted : ");
        scanf("%d",&num);
        insert(&start,num);
        printf("\nNode inserted");
        printf("\nWant to enter more? Press 1, Else Press 0 : ");
        scanf("%d",&ch);
    }
    makecircular(&start);
    printf("\nCircular linked list : \n");
    display(start);
    int elem;
    printf("\nEnter the key to be searched  : ");
    scanf("%d",&elem);
    if(search(start,elem))
    {
        delete(&start,elem);
    }
    else
    {
        printf("\nKey not found!\n");
    }
    printf("\nlinked list : \n");
    display(start);
    return 0;
}
