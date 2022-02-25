#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int h)
{
  while(1)
  {
    int temp = a % h;
    if (temp == 0)
      return h;
    a = h;
    h = temp;
  }
}

int main()
{
  double p=3,q=7;
  double n = p * q;
  double totient = (p-1)*(q-1);
  double e = 2;
  while (e<totient )
  {
    int count = gcd(e,totient);
    if(count!=1)
      e++;
    else
      break;
  }
  cout<<"e:- "<<endl;
  double d = ((2*totient) + 1 ) /e;
  cout<<"d:- "<<d<<endl;
  double message = 12;
  cout<<"Message :- "<<message<<endl;
  double encrypted_message = fmod(pow(message,e),n);
  cout<<"Encrypted message:- "<<encrypted_message<<endl;
  double decrypted_message = fmod(pow(encrypted_message,d),n);
  cout<<decrypted_message<<endl;
  return 0;
}