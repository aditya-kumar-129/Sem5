#include <bits/stdc++.h>
using namespace std;
string XOR(string a, string b)
{
  string ans = "";
  int n = b.length();
  for (int i = 1; i < n; i++) // i should initialised from 1 (IMPORTANT)
  {
    if (a[i] == b[i])
      ans += '0';
    else
      ans += '1';
  }
  return ans;
}
string mod2(string data, string key)
{
  int pick = key.length();
  int len = data.length();
  string temp = data.substr(0, pick);
  while (pick < len)
  {
    if (temp[0] == '1')
      temp = XOR(key, temp) + data[pick];
    else
      temp = XOR(std::string(pick, '0'), temp) + data[pick];
    pick++;
  }
  if (temp[0] == '1')
    temp = XOR(key, temp);
  else
    temp = XOR(std::string(pick, '0'), temp);
  return temp;
}
string encodeData(string data, string key)
{
  int len = key.length();
  string augData = data + std::string(len - 1, '0');
  string remain = mod2(augData, key);
  cout<<"Remainder at the sender side is:- "<<remain<<endl;
  string encoded_data = data + remain;
  cout << "Remainder at encoded side :- " << remain << endl;
  cout << "Encoded Dataword at sender side is :- " << encoded_data << endl;
  return encoded_data;
}
void decodedData(string data, string key)
{
  string remain = mod2(data, key);
  cout << "Remainder at Receiver side is:- " << remain << endl;
  int count = 0;
  for (int i = 0; i < remain.length(); i++)
    if (remain[i] == '1')
      count++;
  if (count == 0)
    cout << "No error occured during transmission side\n";
  else
    cout << "Error occured during transmission side\n";
}
int main()
{
  cout << "Enter the data:- ";
  string data;
  cin >> data;
  cout << "Enter the key:- ";
  string key;
  cin >> key;
  string encode_data = encodeData(data, key);
  cout << "Enter the number of bits you want to corrupt:- ";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter the position to alter the bit:- ";
    int pos;
    cin >> pos;
    if (encode_data[pos] == '0')
      encode_data[pos] = '1';
    else
      encode_data[pos] = '0';
  }
  decodedData(encode_data, key);
}