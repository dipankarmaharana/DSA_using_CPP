#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
int par[N];

void dfs(int vtx, int p = -1) {
   //take action on vertex after entering
   //the vertex
   par[vtx] = p;
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (child == p) continue;
      dfs(child, vtx);
      //take action on child after exiting
      //child node
   }
   //take action on vertex before exiting
   //the vertex
} //o(v+e)

vector<int> path(int v) {
   vector<int> ans;
   while (v != -1) {
      ans.push_back(v);
      v = par[v];
   }
   reverse(ans.begin(), ans.end());
   return ans;
}


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
   dfs(1);

   int v1, v2;
   cin >> v1 >> v2;
   vector<int> path_v1 = path(v1);
   vector<int> path_v2 = path(v2);

   int min_len = min(path_v1.size(), path_v2.size());
   int lca = -1;
   for (int i = 0; i < min_len; ++i)
   {
      if (path_v1[i] == path_v2[i])
      {
         lca = path_v1[i];
      } else {
         break;
      }
   }
   cout << lca << endl;





   return 0;
}