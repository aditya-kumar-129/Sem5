#include <bits/stdc++.h>
using namespace std;
int main()
{
  int window_size, i, frames_to_transmit, frames[50];
  cout << "Enter window size: ";
  cin >> window_size;
  cout << "\nEnter number of frames to transmit: ";
  cin >> frames_to_transmit;
  cout << "\nEnter " << frames_to_transmit << " frames " << endl;
  for (i = 1; i <= frames_to_transmit; i++)
    cin >> frames[i];
  cout << "\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n";
  cout << "After sending " << window_size << " frames at each stage sender waits for acknowledgement sent by the receiver\n\n";
  for (i = 1; i <= frames_to_transmit; i++)
  {
    if (i % window_size == 0)
    {
      cout << frames[i] << "\n";
      cout << "Acknowledgement of above frames sent is received by sender\n\n";
    }
    else
      cout << frames[i] <<" ";
  }
  if (frames_to_transmit % window_size != 0)
    cout << "\nAcknowledgement of above frames sent is received by sender\n";
  return 0;
}