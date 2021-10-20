#include<stdio.h>
int isPalindrome(int num)
{
  int n,r,rev=0;
  n=num;
  while(n)
  {
    r=n%10;
    rev=rev*10+r;
    n/=10;
  }
  return (num==rev);
}
int main()
{
  int num;
  printf("Enter a number : ");
  scanf("%d",&num);
  if(isPalindrome(num))
    printf("\nIt is Palindrome !\n");
  else
    printf("\nIt is not a Palindrome !\n");
  return 0;
}
