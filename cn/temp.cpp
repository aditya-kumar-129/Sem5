// BELLMAN-FORD ALGORITHM
// #include<bits/stdc++.h>
// using namespace std;
// #define infinity 99999

// struct node
// {
//   int source, destination, weight;
//   node(int u, int v, int wt)
//   {
//     source = u;
//     destination = v;
//     weight = wt;
//   }
// };

// int main()
// {
//   cout << "Enter the number of vertex present in the graph:- ";
//   int no_of_vertex;
//   cin >> no_of_vertex;
//   cout << "Enter the number of edges present in the graph:- ";
//   int no_of_edge;
//   cin >> no_of_edge;
//   int s, d, wt;
//   vector<node> edge;
//   for (int i = 0;i < no_of_edge;i++)
//   {
//     cout << "Enter the source node followed by destination node and weight of the edge:- ";
//     cin >> s >> d >> wt;
//     edge.push_back(node(s, d, wt));
//   }
//   int dist[no_of_vertex];
//   for (int i = 0;i < no_of_vertex;i++)
//     dist[i] = infinity;

//   cout << "Enter the source vertex:- ";
//   int source;
//   cin >> source;
//   dist[source] = 0;

//   for (int i = 0;i < no_of_vertex - 1;i++)
//     for (auto it : edge)
//       if (dist[it.source] + it.weight < dist[it.destination])
//         dist[it.destination] = dist[it.source] + it.weight;

//   bool flag = true;
//   for (auto it : edge)
//   {
//     if (dist[it.source] + it.weight < dist[it.destination])
//     {
//       cout << "Negative cycle exist" << endl;
//       flag = false;
//       break;
//     }
//   }

//   if (flag)
//     for (int i = 0;i < no_of_vertex;i++)
//       cout << dist[i] << " ";
// }

// DIJKSTRA ALGORITHM
// #include<bits/stdc++.h>
// using namespace std;
// #define infinity 9999

// void dij(int no_of_vertex,int source,int cost[10][10],int dist[])
// {
//   for(int i=0;i<no_of_vertex;i++)
//     dist[i] = cost[source][i];

//   int count = 1;
//   int flag [no_of_vertex] = {0};
//   int index;
//   while(count<no_of_vertex)
//   {
//     int min = 99;
//     for(int i=0;i<no_of_vertex;i++)
//       if(dist[i]<min && !flag[i])
//         min = dist[i] ,index = i;
//     flag[index] = 1 ;
//     count++;
//     for(int i=0;i<no_of_vertex;i++)
//       if(dist[index] + cost[index][i] < dist[i])
//         dist[i] = dist[index] + cost[index][i];
//   }
// }

// int main()
// {
//   cout<<"Enter the number of vertex present in the graph:- ";
//   int no_of_vertex;
//   cin>>no_of_vertex;
//   cout<<"Enter the cost matrix:- ";
//   int cost[10][10];
//   for(int i=0;i<no_of_vertex;i++)
//   {
//     for(int j=0;j<no_of_vertex;j++)
//     {
//       cin>>cost[i][j];
//       if(cost[i][j]==0)
//         cost[i][j] = infinity;
//     }
//   }
//   cout<<"Enter the source vertex:- ";
//   int source;
//   cin>>source;
//   int dist[no_of_vertex];
//   dij(no_of_vertex,source,cost,dist);
//   for(int i=0;i<no_of_vertex;i++)
//     if(i!=source)
//       cout<<dist[i]<<" ";
// }

// CRC ALGORITHM

// #include<bits/stdc++.h>
// using namespace std;
// string XOR(string a, string b)
// {
//   int len = b.length();
//   string ans = "";
//   for (int i = 1;i < len;i++)
//   {
//     if (a[i] == b[i])
//       ans += "0";
//     else
//       ans += "1";
//   }
//   return ans;
// }

// string MODULUS(string data, string key)
// {
//   int data_len = data.length();
//   int key_len = key.length();
//   string temp = data.substr(0, key_len);
//   while (key_len < data_len)
//   {
//     if (temp[0] == '1')
//       temp = XOR(key, temp) + data[key_len];
//     else
//       temp = XOR(std::string(key_len, '0'), temp) + data[key_len];
//     key_len++;
//   }
//   if (temp[0] == '1')
//     temp = XOR(key, temp);
//   else
//     temp = XOR(std::string(key_len, '0'), temp);
//   return temp;
// }

// string encode_data(string data, string key)
// {
//   int key_len = key.length();
//   string temp = std::string(key_len - 1, '0');
//   string augmented_data = data + temp;
//   string rem = MODULUS(augmented_data, key);
//   string encoded_data = data + rem;
//   return encoded_data;
// }

// void decode_data(string data, string key)
// {
//   string remain = MODULUS(data, key);
//   int count = 0;
//   int len = remain.length();
//   for (int i = 0;i < len;i++)
//     if (remain[0] == '1')
//       count++;
//   if (count != 0) 
//   {
//     cout << "data get currupted" << endl;
//     cout << remain << endl;
//   }
//   else
//     cout << "data has reached the destination safely" << endl;
// }

// int main()
// {
//   string data;
//   cout << "Enter the data to be encoded:- ";
//   cin >> data;
//   string key;
//   cout << "Enter the key:- ";
//   cin >> key;
//   string encoded_data = encode_data(data, key);
//   cout << "Encoded data is:- " << encoded_data << endl;
//   cout << "Enter the number of bits you wanted to currupt:- ";
//   int no_of_bit;
//   cin >> no_of_bit;
//   for (int i = 0;i < no_of_bit;i++)
//   {
//     cout << "Enter the positions at which data get corrupted:- ";
//     int pos;
//     cin >> pos;
//     if (encoded_data[pos] == '1')
//       encoded_data[pos] = '0';
//     else
//       encoded_data[pos] = '1';
//   }
//   decode_data(encoded_data, key);
//   return 0;
// }

// INTERNET CHECKSUM

// #include<bits/stdc++.h>
// using namespace std;

// int checksum(int flag)
// {
//   char in[100];
//   scanf(" %[^\n]s", in);
//   int n = strlen(in);
//   if (n % 2 != 0)
//     n = (n + 1) / 2;
//   else
//     n = n / 2;
//   int temp, sum = 0;
//   for (int i = 0;i < n;i++)
//   {
//     temp = in[i * 2];
//     temp = (temp * 256) + in[(i * 2) + 1];
//     sum += temp;
//   }
//   int temp1;
//   if (flag == 1)
//   {
//     cout << "Enter the checksum" << endl;
//     scanf("%x", &temp1);
//     sum += temp1;
//   }
//   if (sum % 65536 != 0)
//   {
//     n = sum % 65536;
//     sum = (sum / 65536) + n;
//   }
//   sum = 65535 - sum;
//   return sum;
// }

// int main()
// {
//   int sum = 0;
//   while (1)
//   {
//     cout << "Enter the corresponding number to perform the corresponding operation:- " << endl;
//     cout << "1.)ENcode\n2.)Decode\n3.)Exit\n";
//     cout << "Enter your choice:- ";
//     int choice;
//     cin >> choice;
//     switch (choice)
//     {
//     case 1:
//       cout << "Enter the string:- ";
//       sum = checksum(0);
//       printf("checksum to append is:- %x\n", sum);
//       break;
//     case 2:
//       cout << "Enter the string:- ";
//       sum = checksum(1);
//       if (sum != 0)
//         cout << "Data get currupted" << endl;
//       else
//         cout << "Data safe" << endl;
//       break;
//     case 3:
//       cout << "Exiting the program:(" << endl;
//       exit(0);
//       break;
//     default:
//       cout<<"Please enter valid choice:- "<<endl;
//       break;
//     }
//   }
// }

// Leaky bucket algorithm

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//   cout<<"Enter the bucket size:- ";
//   int bucket_size;
//   cin>>bucket_size;
//   cout<<"Enter outgoing rate:- ";
//   int outgoing_rate;
//   cin>>outgoing_rate;
//   cout<<"Enter the number of seconds for which there is incoming of files:- ";
//   int no_of_second;
//   cin>>no_of_second;
//   int frames[50]={0};
//   for(int i=0;i<no_of_second;i++)
//     cin>>frames[i];
//   int count=0,drop=0;
//   cout<<"Second\tIncoming\tOutgoing\tCount\tDrop\n";
//   for(int i=0;count||i<no_of_second;i++)
//   {
//     cout<<i+1<<"    ";
//     cout<<frames[i]<<"   ";
//     cout<<min(count+frames[i],outgoing_rate)<<"\t\t";
//     int x = count + frames[i] - outgoing_rate;
//     if(x>0)
//     {
//       if (x > bucket_size)
//         count = bucket_size, drop = x - bucket_size;
//       else
//         count = x, drop = 0;
//     }
//     else
//       count=0,drop=0;
//     cout<<count<<"\t"<<drop<<endl;
//   }
// }

// PRIOROTY QUEUE
// #include<bits/stdc++.h>
// using namespace std;
// #define MAX 25
// int front_hp=-1,rear_hp=-1,front_lp=-1,rear_lp=-1;
// int queue_hp[MAX],queue_lp[MAX];

// void insert()
// {
//   cout << "Enter the number to be inserted :- ";
//   int temp;
//   cin >> temp;
//   cout<<"Press 1 to insert in High PQ and 0 for low PQ"<<endl;
//   int choice;
//   cin>>choice;
//   if(choice==1)
//   {
//     if (rear_hp == MAX - 1)
//       cout << "High PQ is full, can't insert" << endl;
//     else
//     {
//       if (front_hp == -1)
//         front_hp++;
//       queue_hp[++rear_hp] = temp;
//       cout << temp << " has been succfully inserted in the High PQ" << endl;
//     }
//   }
//   else
//   {
//     if (rear_lp == MAX - 1)
//       cout << "Low PQ is full, can't insert" << endl;
//     else
//     {
//       if (front_lp == -1)
//         front_lp++;
//       queue_lp[++rear_lp] = temp;
//       cout << temp << " has been succfully inserted in the Low PQ" << endl;
//     }
//   }
// }

// void delete_q()
// {
//   if(front_hp==-1 || front_hp>rear_hp)
//   {
//     cout<<"High PQ is empty.Deleting elements from Low PQ"<<endl;
//     if(front_lp==-1 || front_lp>rear_lp)
//       cout << "High PQ is empty.Noe elements to delete" << endl;
//     else
//       cout<<queue_lp[front_lp++]<< " is being deleted from Low PQ"<<endl;
//   }
//   else
//     cout << queue_hp[front_hp++] << " is being deleted from High PQ" << endl;
// }

// void display()
// {
//   if (front_hp == -1 || front_hp > rear_hp)
//     cout<<"High PQ is empty."<<endl;
//   else
//   {
//     cout<<"Displaying the content of High PQ:- "<<endl;
//     for(int i=front_hp;i<=rear_hp;i++)
//       cout<<queue_hp[i]<<" ";
//     cout<<endl;
//   }
//   if (front_lp == -1 || front_lp > rear_lp)
//     cout << "Low PQ is empty." << endl;
//   else
//   {
//     cout << "Displaying the content of Low PQ:- " << endl;
//     for (int i = front_lp;i <= rear_lp;i++)
//       cout << queue_lp[i] << " ";
//     cout << endl;
//   }

// }

// int main()
// {
//   while(1)
//   {
//     cout<<"Enter the corresponding number to perform the corresponding operation:- "<<endl;
//     cout<<"1.)Insert\n2.)Delete\n3.)Display\n4.)Exit"<<endl;
//     cout<<"Enter your choice:- ";
//     int choice;
//     cin>>choice;
//     switch (choice)
//     {
//     case 1:
//       insert();
//       break;
//     case 2:
//       delete_q();
//       break;
//     case 3:
//       display();
//       break;
//     case 4:
//       cout<<"Exixtiing the program:("<<endl;
//       break;
//     default:
//       cout<<"Please enter valid choice"<<endl;
//       break;
//     }
//   }
// }

// GO BACK N

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//   cout<<"Enter window size:- ";
//   int window_size;
//   cin>>window_size;
//   cout<<"Enter no of frames to send:- ";
//   int no_of_frames;
//   cin>>no_of_frames;
//   int frames[no_of_frames];
//   cout<<"Enter the frame values:- "<<endl;
//   for(int i=1;i<=no_of_frames;i++)
//     cin>>frames[i];
//   for (int i = 1; i <= no_of_frames  ; i++)
//   {
//     if(i%window_size==0)
//     {
//       cout<<frames[i]<<" "<<endl;
//       cout<<"Acknowledgement of above frames has been reached to sender"<<endl;
//     }
//     else  
//       cout<<frames[i]<<" ";
//   }
//   if(no_of_frames&window_size!=0)
//     cout<<endl << "Acknowledgement of above frames has been reached to sender" << endl;
// }

// RSA Algorithm
// #include<bits/stdc++.h>
// using namespace std;

// int gcd(int a, int h)
// {
//   while(1)
//   {
//     int temp = a % h;
//     if (temp == 0)
//       return h;
//     a = h;
//     h = temp;
//   }
// }

// int main()
// {
//   double p=3,q=7;
//   double n = p * q;
//   double totient = (p-1)*(q-1);
//   double e = 2;
//   while (e<totient )
//   {
//     int count = gcd(e,totient);
//     if(count!=1)
//       e++;
//     else
//       break;
//   }
//   double d = ((2*totient) + 1 ) /e;
//   double message = 12;
//   double encrypted_message = fmod(pow(message,e),n);
//   double decrypted_message = fmod(pow(encrypted_message,d),n);
//   cout<<decrypted_message<<endl;
//   return 0;
// }