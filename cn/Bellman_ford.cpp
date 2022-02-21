#include<bits/stdc++.h>
using namespace std;
#define infinity 99999

struct node
{
  int u, v, wt;
  node(int source, int destination, int weight)
  {
    u = source;
    v = destination;
    wt = weight;
  }
};

int main()
{
  cout << "Enter the number of vertex present in the graph:- ";
  int n;
  cin >> n;
  cout << "Enter the number of edges present in the graph:- ";
  int e;
  cin >> e;
  vector<node> edge;
  for (int i = 0;i < e;i++)
  {
    cout << "Enter the source node of the edge followed by destination node of the edge and the weight of the edge:- ";
    int s, d, w;
    cin >> s >> d >> w;
    edge.push_back(node(s, d, w));
  }

  cout << "Enter the source node:- ";
  int source;
  cin >> source;

  int dist[n];
  for (int i = 0;i < n;i++)
    dist[i] = infinity;

  dist[source] = 0;

  for (int i = 0;i < n - 1;i++)
    for (auto it : edge)
      if (dist[it.u] + it.wt < dist[it.v])
        dist[it.v] = dist[it.u] + it.wt;

  bool flag = false;

  for (auto it : edge)
  {
    if (dist[it.u] + it.wt < dist[it.v])
    {
      cout << "Negative cycle exist can't find the sortest path:(" << endl;
      flag = true;
      break;
    }
  }

  if (!flag)
  {
    for (int i = 0;i < n;i++)
      cout << "0-> " << i << " weight= " << dist[i] << " " << endl;
  }
}

/*
input 
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
*/

/*
output
Vertex   Distance from Source
0                0
1                -1
2                2
3                -2
4                1
*/