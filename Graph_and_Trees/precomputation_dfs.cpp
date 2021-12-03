#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

/*
Print Subtree sum of v and no of even integer in the subtree of v.
*/

vector<int> g[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vtx, int par = 0) {
   //take action on vertex after entering
   //the vertex
   if (vtx % 2 == 0) even_ct[vtx]++;
   subtree_sum[vtx] += vtx;
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (child == par) continue;
      dfs(child, vtx);
      //take action on child after exiting
      //child node
      subtree_sum[vtx] += subtree_sum[child];
      even_ct[vtx] += even_ct[child];
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
   dfs(1);
   int q;
   while (q--) {
      int v;
      cin >> v;
      cout << subtree_sum[v] << even_ct[v] << endl;
   }


   return 0;
}