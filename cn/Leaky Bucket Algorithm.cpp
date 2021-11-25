#include<bits/stdc++.h>
using namespace std;

int main()
{
  cout<<"Enter the bucket size:- ";
  int bucket_size;
  cin>>bucket_size;
  cout<<"Enter the output rate:- ";
  int output_rate;
  cin>>output_rate;
  cout<<"Enter the value of n:- ";
  int n;
  cin>>n;
  int arr[n]={0};
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<"Second\tIncoming\tOutgoing\tDropped\tinBucket\n";
  int count=0,drop=0;
  for(int i=0;count||i<n;i++)
  {
    cout<<"    "<<i+1<<"\t";
    cout<<arr[i]<<"\t";
    cout<<min((arr[i]+count),output_rate)<<"\t";
    int x = arr[i] + count - output_rate;
    if(x>0)
    {
      if(x>bucket_size)
      {
        count=bucket_size;
        drop=x-bucket_size;
      }
      else
      {
        count=x;
        drop=0;
      }
    }
    else
    {
      count=0;
      drop=0;
    }
    cout<<drop<<"\t"<<count<<endl;
  }
}