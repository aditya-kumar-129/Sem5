#include <bits/stdc++.h>
using namespace std;
int front_hp = -1, rear_hp = -1, front_lp = -1, rear_lp = -1;
#define MAX 25
int queue_hp[MAX], queue_lp[MAX];
void Insert()
{
  cout << "Enter the element to be inserted :- ";
  int ele;
  cin >> ele;
  cout << "Press 1 to insert in High Priority Queue OR 0 to insert in Low Priority Queue:- ";
  int choice;
  cin >> choice;
  if (choice == 1)
  {
    if (rear_hp == MAX - 1)
      cout << "Queue overflow can't insert the element:(\n";
    if (front_hp == -1)
      front_hp++;
    queue_hp[++rear_hp] = ele;
    cout << "ELement inserted successfully in High Priority Queue\n";
  }
  else
  {
    if (rear_lp == MAX - 1)
      cout << "Queue overflow can't insert the element:(\n";
    if (front_lp == -1)
      front_lp++;
    queue_lp[++rear_lp] = ele;
    cout << "ELement inserted successfully in Low Priority Queue\n";
  }
}
void delete_q()
{
  if (front_hp == -1 || front_hp > rear_hp)
  {
    cout << "High Priority Queue is empty\n";
    if (front_lp == -1 || front_lp > rear_lp)
      cout << "Low Priority Queue is empty\n";
    else
    {
      cout << "Deleting element form Low Priority Queue\n";
      cout << "Element to be deleted is :- " << queue_lp[front_lp++]<<endl;
    }
  }
  else
  {
    cout << "Deleting element form High Priority Queue\n";
    cout << "Element to be deleted is :- " << queue_hp[front_hp++]<<endl;
  }
}
void display()
{
  if(front_hp == -1 || front_hp > rear_hp)
    cout<<"High Priority Queue is empty\n";
  else
  {
    cout<<"Displaying the content of High Priority Queue:- \n";
    for(int i=front_hp;i<=rear_hp;i++)
      cout<<queue_hp[i]<<" ";
  }
  cout<<endl;
  if(front_lp == -1 || front_lp > rear_lp)
    cout<<"Low Priority Queue is empty\n";
  else
  {
    cout<<"Displaying the content of Low Priority Queue:- \n";
    for(int i=front_lp;i<=rear_lp;i++)
      cout<<queue_lp[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  while (1)
  {
    cout << "Enter the corresponding number to perform the corresponding operation\n";
    cout << "1.)Insert\n2.)Delete\n3.)Display\n4.)exit\n";
    cout << "Enter the choice:- ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
      Insert();
      break;
    case 2: // delete is a c++ keyword so you can't use them
      delete_q();
      break;
    case 3:
      display();
      break;
    case 4:
      cout << "Existing the program.";
      exit(0);
      break;
    default:
      cout << "Enter valid choice:(" << endl;
      break;
    }
  }
}