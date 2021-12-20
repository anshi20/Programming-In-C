// Code for queue using linked list.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
    //self referential structure..
};


void enqueue(struct Node** front, struct Node** rear, int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if((*front)==NULL && (*rear)== NULL)
    {
        (*front)=temp;
        temp->data=x;
        temp->link=NULL;
        (*rear)=temp;
    }
    else
    {
        (*rear)->link=temp;
        temp->data=x;
        (*rear)=temp;
    }
    
}
void dequeue(struct Node** front, struct Node** rear)
{
    if((*front) == NULL && (*rear) == NULL)
    {
        printf("\nThe queue is empty!\n");
    }
    else
    
    
    
    {
        struct Node* temp;
        temp=(*front);
        printf("\nDeleted element %d \n",(*front)->data);
        (*front)=(*front)->link;
        free(temp);
    }
}
int peek(struct Node** front, struct Node** rear)
{
    if((*front) == NULL && (*rear) == NULL){
         printf("\nQueue is empty!!\n");
    }
    else
         return (*front)->data;
}
void display(struct Node** front, struct Node** rear)
{
    if((*front) == NULL && (*rear) == NULL){
         printf("\nQueue is empty!!\n");
         return;
    }
    struct Node* ptr = (*front);
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int ch,num;
    while(1){
    printf("\nEnter choice : \n");
    printf("1. Enqueue \t\t\t\t 2. Dequeue \t\t\t\t 3. Peek \t\t\t\t 4. Display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : printf("\nEnter number to be inserted : ");
                 scanf("%d",&num);
                 enqueue(&front,&rear,num);
                 break;
        case 2 : dequeue(&front,&rear);
                 break;
        case 3 : printf("\nPrinting front element .... %d",peek(&front,&rear));
                 break;
        case 4 : printf("\nDisplaying elements of queue .... \n");
                 display(&front,&rear);
                 break;
        case 5 : exit(0);
        default: printf("\nInvalid choice!!\n");
    }
    }
    return 0;
}
