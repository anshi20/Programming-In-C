
// C program to sort a stack using recursion 

#include <stdio.h> 
#include <stdlib.h> 
struct stack 
{ 
    int data; 
    struct stack *next; 
}; 
  
// This function is initialising the top of stack to NULL
void initStack(struct stack **s) 
{ 
    *s = NULL; 
} 
  
// Utility function to chcek if stack is empty 
int isEmpty(struct stack *s) 
{ 
    if (s == NULL) 
        return 1; 
    return 0; 
} 
  
// This function is used to push an item into the stack 
void push(struct stack **s, int x) 
{ 
    struct stack *p = (struct stack *)malloc(sizeof(*p)); 
  
    if (p == NULL) 
    { 
        printf("Memory allocation failed."); 
        return; 
    } 
  
    p->data = x; 
    p->next = *s; 
    *s = p; 
} 
  
// Utility function to remove an item from stack 
int pop(struct stack **s) 
{ 
    int x; 
    struct stack *temp; 
  
    x = (*s)->data; 
    temp = *s; 
    (*s) = (*s)->next; 
    free(temp); 
  
    return x; 
} 
  
// Function to find top item 
int top(struct stack *s) 
{ 
    return (s->data); 
} 
  
// Recursive function to insert an item x in sorted way 
void sortedInsert(struct stack **s, int x) 
{ 
    // Base case: Either stack is empty or newly inserted 
    // item is greater than top (more than all existing) 
    if (isEmpty(*s) || x > top(*s)) 
    { 
        push(s, x); 
        return; 
    } 
  
    // If top is greater, remove the top item and recur 
    int temp = pop(s); 
    sortedInsert(s, x); 
  
    // Put back the top item removed earlier 
    push(s, temp); 
} 
  
// Function to sort stack 
void sortStack(struct stack **s) 
{ 
    // If stack is not empty 
    if (!isEmpty(*s)) 
    { 
        // Remove the top item 
        int x = pop(s); 
  
        // Sort remaining stack 
        sortStack(s); 
  
        // Push the top item back in sorted stack 
        sortedInsert(s, x); 
    } 
} 
  
// This function is used to print the elements of the stack 
void printStack(struct stack *s) 
{ 
    while (s) 
    { 
        printf("%d ", s->data); 
        s = s->next; 
    } 
    printf(" "); 
} 

int main() 
{ 
    struct stack *top; 
    int n;
    initStack(&top); // It is declaring top null !
    printf("Enter the no of elements you want to enter in the stack : ");
    scanf("%d",&n);
    while(n--){
    	int num;
    	printf("\nEnter the elemnt : ");
    	scanf("%d",&num);
		push(&top,num);
	} 
  
    printf("\nStack elements before sorting : \n"); 
    printStack(top); 
    
    sortStack(&top); 
  
    printf("\nStack elements after sorting : \n"); 
    printStack(top); 
  
    return 0; 
} 

