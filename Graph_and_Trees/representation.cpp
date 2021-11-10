#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

const int N = 1e3 + 10;
int graph[N][N];

vector<int> graph2[N];

int main() {
   int n, m;
   int graph[n + 1][n + 1];
   for (int i = 0; i < m; ++i)
   {
      int v1, v2;
      cin >> v1 >> v2;
      graph[v1][v2] = 1;
      graph[v2][v2] = 1;
      //0(N^2) -- space complexity
      // not possible if N >= 10^3

      graph2[v1].push_back(v2);
      graph2[v2].push_back(v1);
      //o(n+m)
   }






   return 0;
}