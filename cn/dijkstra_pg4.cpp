#include <bits/stdc++.h>
using namespace std;
#define infinity 999
void dij(int n, int v, int cost[10][10], int dist[])
{
  int u, flag[10] = { 0 };
  for (int i = 0; i < n; i++)
    dist[i] = cost[v][i]; // make the initial distance from the source node to all other node
  int count = 1;
  while (count < n)
  {
    int min = 99;
    for (int w = 0; w < n; w++)
      if (dist[w] < min && !flag[w])
        min = dist[w], u = w;
    flag[u] = 1;
    count++;
    for (int w = 0; w < n; w++)
      if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
        dist[w] = dist[u] + cost[u][w];
  }
}

int main()
{
  int n, v, i, j, cost[10][10], dist[10];
  cout << "\n Enter the number of nodes:";
  cin >> n;
  cout << "\n Enter the cost matrix:\n";
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      cin >> cost[i][j];
      if (cost[i][j] == 0 && i != j) // basically it means that this node is not directly connected
        cost[i][j] = infinity;
    }
  }
  cout << "\n Enter the source node:";
  cin >> v;
  dij(n, v, cost, dist);
  cout << "\n Shortest path:\n";
  for (i = 0; i < n; i++)
    if (i != v)
      cout << v << "->" << i << "," << "cost=" << dist[i] << endl;
  return 0;
}

/* Input cost matrix:-
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0
*/

/* Output
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
*/