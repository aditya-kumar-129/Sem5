#include<bits/stdc++.h>
using namespace std;
int main()
{
  cout << "Enter the bucket size:- ";
  int bucket_size;
  cin >> bucket_size;
  cout << "Enter the output rate:- ";
  int output_rate;
  cin >> output_rate;
  cout << "Enter the number of sencod for which there is frames are coming:- ";
  int n;
  cin >> n;
  int frames[50] = { 0 };
  for (int i = 0;i < n;i++)
  {
    cout << "Enter the frames that come at " << i + 1 << " second:- ";
    cin >> frames[i];
  }
  cout << "Second\tIncoming\tOutgoing\tCount\tDrop\n";
  int count = 0, drop = 0;
  for (int i = 0;count || i < n;i++)
  {
    cout << "  " << i + 1 << "\t   ";
    cout << frames[i] << "\t\t   ";
    cout << min(count + frames[i], output_rate) << "\t\t  ";
    int x = count + frames[i] - output_rate;
    if (x > 0)
    {
      if (x > bucket_size)
      {
        count = bucket_size;
        drop = x - bucket_size;
      }
      else
      {
        count = x;
        drop = 0;
      }
    }
    else
    {
      count = 0;
      drop = 0;
    }
    cout << count << "\t " << drop << "\n";
  }
}