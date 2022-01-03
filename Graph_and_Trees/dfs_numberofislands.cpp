#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e5 + 7;
int arr[N];

class Solution {
public:
   void dfs(int i, int j, vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      if (i < 0 || j < 0) return;
      if (i >= n || j >= m) return;
      if (grid[i][j] == '0' || grid[i][j] == '2') return;

      grid[i][j] = '2'; //visited


      dfs(i + 1, j, grid);
      dfs(i - 1, j, grid);
      dfs(i, j + 1, grid);
      dfs(i, j - 1, grid);

   }

   int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      int ct = 0;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (grid[i][j] == '1')
            {
               dfs(i, j, grid);
               ct++;
            }
         }
      }
      return ct;
   }
};