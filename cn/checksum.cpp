#include<bits/stdc++.h>
using namespace std;
int checksum(int fl)
{
  char in[50];
  cin>>in;
  int n;
  if(strlen(in)%2!=0)
    n = (strlen(in)+1)/2;
  else
    n = strlen(in)/2;
  int temp=0,sum=0;
  for(int i=0;i<n;i++)
  {
    temp=in[(i*2)];
    temp = (temp*256) + in[(i*2)+1];
    sum+=temp;
  }
  if(fl==1)
  {
    cout<<"Enter the checksum:- ";
    scanf("%x",&temp);
    sum+=temp;
  }
  if(sum%65535!=0)
  {
    n= sum%65535;
    sum = (sum/ 65535 ) + n;
  }
  sum = 65535-sum;
  printf("%x",sum);
  cout<<endl;
  return sum;
}
int main()
{
  int sum;
  while(1)
  {
    cout<<"Enter corresponding number to performcorresponding operation!!"<<endl;
    cout<<"1.)Encode\n2.)Decode\n3.)Exit\n";
    int choice;
    cout<<"Enter your choice:- ";
    cin>>choice;
    switch (choice)
    {
    case 1:
      cout<<"Enter the string:- ";
      sum = checksum(0);
      printf("Checksum to be appended is :- %x",sum);
      cout<<endl;
      break;
    case 2:
      cout<<"Enter the string :- ";
      sum = checksum(1);
      if(sum!=0)
        cout<<"Error occurred!"<<endl;
      else
        cout<<"No error"<<endl;
    case 3:
      cout<<"Exiting the program"<<endl;
      exit(0);
    default:
      cout<<"ENter valid choice:-\n";
      break;
    }
  }
}