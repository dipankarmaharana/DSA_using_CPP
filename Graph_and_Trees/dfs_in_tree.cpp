#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
int height[N], depth[N];

void dfs(int vtx, int par = 0) {
   //take action on vertex after entering
   //the vertex
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (child == par) continue;
      depth[child] = depth[vtx] + 1;
      dfs(child, vtx);
      height[vtx] = max(height[vtx], height[child] + 1);
      //take action on child after exiting
      //child node
   }
   //take action on vertex before exiting
   //the vertex
} //o(v+e)


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
   dfs(1, 0);

   for (int i = 1; i <= n; ++i)
   {
      cout << depth[i] << " " << height[i] << endl;
   }


   return 0;
}