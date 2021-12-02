#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
bool vis[N];

bool dfs(int vtx, int par) {
   //take action on vertex after entering
   //the vertex
   // if(vis[vtx]) return;
   vis[vtx] = true;
   bool isLoopExists = false;
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (vis[child] && child == par) continue;
      if (vis[child]) return true;
      isLoopExists |= dfs(child, vtx);
      //take action on child after exiting
      //child node
   }
   //take action on vertex before exiting
   //the vertex
   return isLoopExists;
} //o(v+e)


int main() {
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; ++i)
   {
      int v1, v2;
      cin >> v1 >> v2;
      g[v1].push_back(v2);
      g[v2].push_back(v1);

   }
   bool flag = false;
   int ct = 0;
   for (int i = 1; i <= n; ++i)
   {
      if (vis[i]) continue;
      if (dfs(i, 0)) {
         flag = true;
         break;
      }
   }
   cout << flag << endl;


   return 0;
}