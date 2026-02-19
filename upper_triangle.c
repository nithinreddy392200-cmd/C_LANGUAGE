#include<stdio.h>
#include<stdlib.h>
    int main()
  {
    int rows;
    int col;
    printf("enter no of rows:\n");
    scanf("%d",&rows);
    printf("enter no of colums:\n");
    scanf("%d",&col);
    for(int i=1;i<=col;i++) 
    {
    for(int j=1;j<=col;j++)
    {
    if(i==1||j==col||i==j||i<j)
    {
       printf("* ");
    } 
    else
    {
    printf("  ");
   }
  }
   printf ("\n");
   }
  }