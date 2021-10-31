#include<stdio.h>
#include<stdlib.h>

struct stack 
{ 
    int data; 
    struct stack *next; 
}; 
  

void initStack(struct stack **s) 
{ 
    *s = NULL; 
} 

int isEmpty(struct stack *s)
{
    if(s==NULL)
        return 1;
    else
        return 0;
}



void push(struct stack **s, int x) 
{ 
    struct stack *new_node = (struct stack *)malloc(sizeof(*new_node)); 
  
    if (new_node == NULL) 
    { 
        printf("Not enough memory!!\nAborting!!\n"); 
        return; 
    } 
    //Insertion in beginning operation
    new_node->data = x; 
    new_node->next = *s; 
    *s = new_node; 
} 

int pop(struct stack **s) 
{ 
    int element; 
    struct stack *temp; 
  
    element = (*s)->data; 
    temp = *s; 
    (*s) = (*s)->next; 
    free(temp); 
  
    return element; 
} 

int peek(struct stack *s)
{
   return (s->data); 
}

void display(struct stack *s) 
{ 
    while(s) //it will execute till stack does not become empty
    { 
        printf("%d ", s->data); 
        s = s->next; 
    } 
    printf(" "); 
} 
void insert_in_sorted_array(struct stack **s, int element)
{
    if(isEmpty(*s)||element > peek(*s))
    {
        push(s,element);
        return;
    }
    int temp = pop(s);
    insert_in_sorted_array(s,element);
    push(s,temp);
}

void sort(struct stack **s)
{
    if(!isEmpty(*s))
    {
        int x = pop(s);
        sort(s);
        insert_in_sorted_array(s,x);
    }
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
    display(top); 
    
    sort(&top); 
  
    printf("\nStack elements after sorting : \n"); 
    display(top); 
  
    return 0; 
} 
