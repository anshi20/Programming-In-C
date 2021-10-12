#include<stdlib.h>
#include<stdio.h>
# define N 5
int queue[N];front =-1,rear=-1;
void enqueue(int n)
{
  if(rear==N-1)
   {printf("Overflow!");
    return ;
   }
  else if(rear==-1&&front==-1)
  {
    front=0;
    rear=0;
    queue[rear]=n;
  }
  else
  {
    rear++;
    queue[rear]=n;
  }
}
void dequeue()
{
  if(front==-1&&rear==-1)
  {
    printf("Underflow condition!");
    return;
  }
  else if(front==rear)
  {
    printf("Dequeued element : %d",queue[front]);
    front=-1;
    rear=-1;
  }
  else
  {
    printf("Dequeued element : %d",queue[front]);
    front++;
  }
}
void display()
{
  int i;
  if(front==-1&&rear==-1)
  {
    printf("Queue is empty!\n");
    return;
  }
  else
  {
    for(i=front;i<rear+1;i++)
       printf("%d",queue[i]);
  }
}
void peek()
{
  if(front==-1&&rear==-1)
  {
    printf("Queue is empty!");
    return;
  }
  else
    printf("%d",queue[front]);
}


int main()
{ int num,choice;
  printf("1.Enqueue/t/t2.Dequeue/t/t3.Display/t/t4.Peek/t/t/5.Exit/n");
  scanf("%d",&choice);
  while(1)
 {switch(choice)
  {
    case 1: printf("\nEnter the number : ");
            scanf("%d",&num);
            enqueue(num);
            break;
    case 2: printf("\n");
            dequeue();
            break;
    case 3: printf("\n");
            display();
            break;
    case 4: printf("\n");
            peek();
            break;
    case 5: exit(0);
    default:printf("Invalid choice!");
            break;
 
  }
 }
 return 0;
}
