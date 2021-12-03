#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
int subtree_sum[N];
int val[N];

void dfs(int vtx, int p = -1) {
   //take action on vertex after entering
   //the vertex
   subtree_sum[vtx] += val[vtx - 1];
   for (int child : g[vtx]) {
      //take action on child before entering
      //the child node
      if (child == p) continue;
      dfs(child, vtx);
      subtree_sum[vtx] += subtree_sum[child];
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

   long long ans = 0;
   for (int i = 2; i <= n; ++i)
   {
      int part1 = subtree_sum[i];
      int part2 = subtree_sum[1] - part1;
      ans = max(ans, (part1 * part2 * 1LL) % M);

   }
   cout << ans << endl;





   return 0;
}