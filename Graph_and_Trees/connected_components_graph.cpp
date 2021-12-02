#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vtx) {
   //take action on vertex after entering
   //the vertex
   // if(vis[vtx]) return;
   vis[vtx] = true;
   current_cc.push_back(vtx);
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (vis[child]) continue;
      dfs(child);
      //take action on child after exiting
      //child node
   }
   //take action on vertex before exiting
   //the vertex
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
   int ct = 0;
   for (int i = 1; i <= n; ++i)
   {
      if (vis[i]) continue;
      current_cc.clear();
      dfs(i);
      cc.push_back(current_cc);
      ct++;
   }
   cout << cc.size() << endl;
   for (auto c_cc : cc) {
      for (int vtx : c_cc) {
         cout << vtx << " ";
      }
      cout << endl;
   }


   return 0;
}