#include<stdlib.h>
#include<stdio.h>
#define MAX 10
int stack[MAX], top=-1;
void push(int n)
{
	if(top==MAX-1)
    {
	    printf("\nInsufficient space ! Stack is full\n");
	    return;
    }
    top++;
    stack[top]=n;
    printf("Element added successfully.");
}
void pop()
{
	if(top==-1)
   {
      printf("Stack is empty !");
	  return ;  	
   }
    int pop_element=stack[top];
	top--;
	printf("Deleted element %d from stack!\n",pop_element);
}
void display()
{
   if(top==-1)
   {
      printf("Stack is empty !");
	  return ;  	
   }	
   printf("\n");
   for(int i=0;i<=top;i++)
      printf("%d\t",stack[i]);
}
void peek()
{
	if(top==-1)
   {
      printf("Stack is empty !");
	  return ;  	
   }
	printf("\nTop element is : %d\n",stack[top]);
}
int main()
{
	int choice, item;
	while(1)
	{
		printf("                            MENU                   ");
		printf("\n1.Push element to stack\t\t2.Pop element from stack\n");
		printf("3.Display the stack\t\t\t4.Peek\t\t\t5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nEnter element : ");
			         scanf("%d",&item);
					 push(item);
					 break; 
			case 2 : printf("\n");
			         pop();
			         break;
			case 3 : printf("\nDisplaying the stack ...\n");
			         display();
			         break;
			case 4 : printf("\nDisplaying the top of the stack...\n");
		             peek();
					 break;
		    case 5 : printf("\nexiting...\n");
		             exit(0);
		    default: printf("\nINVALID CHOICE !!!\n");
		}
	}
	return 0;
}
