#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
int level[N];
int vis[N];

void bfs(int source) {
   queue<int> q;
   q.push(source);
   vis[source] = 1;

   while (!q.empty()) {
      int currentvtx = q.front();
      q.pop();
      cout << currentvtx << " ";
      for (int child : g[currentvtx]) {
         if (!vis[child]) {
            q.push(child);
            vis[child] = 1;
            level[child] = level[currentvtx] + 1;
         }
      }
   }
} //O(V+E)


int main() {
   int n;
   cin >> n ;
   for (int i = 0; i < n - 1; ++i)
   {
      int v1, v2;
      cin >> v1 >> v2;
      g[v1].push_back(v2);
      g[v2].push_back(v1);

   }
   bfs(1);

   for (int i = 1; i <= n; ++i)
   {
      cout << i << ": " << level[i] << endl;
   }




   return 0;
}