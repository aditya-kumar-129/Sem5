#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int checksum(int flag)
{
  char in[100];
  scanf(" %[^\n]s", in);
  int n = strlen(in);
  if (n % 2 != 0)
    n = (n + 1) / 2;
  else
    n = n / 2;
  int sum = 0, temp;
  for (int i = 0;i < n;i++)
  {
    temp = in[i * 2];
    temp = (temp * 256) + in[(i * 2) + 1];
    sum += temp;
  }
  int temp1;
  if (flag == 1)
  {
    printf("ENter the checksum value:- ");
    scanf("%x", &temp1);
    sum += temp1;
  }
  if(sum%65536!=0)
  {
    n=sum%65536;
    sum = (sum/ 65536) + n;
  }
  sum = 65535 - sum;
  return sum;
}

int main()
{
  int choice, sum;
  while (1)
  {
    printf("Enter corresponding number to perform the corresponding operation:- \n");
    printf("1.)Encode\n2.)Decode\n3.)Exit\n");
    printf("Enter your choice:- ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the string:- ");
      sum = checksum(0);
      printf("The checksum to append is:- %x \n", sum);
      break;
    case 2:
      printf("Enter the string:- ");
      sum = checksum(1);
      if (sum != 0)
        printf("Data get currupted during transmission:(\n");
      else
        printf("Data safely reached the destination:)\n");
      break;
    case 3:
      printf("Exixting the program:) \n");
      exit(0);
    default:
      printf("Please enter correct choice:-\n");
      break;
    }
  }
}