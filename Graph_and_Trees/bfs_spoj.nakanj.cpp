/*Anjali and Nakul are good friends. They both had a quarrel recently while playing chess. Nakul wants to know the minimum number of moves a knight takes to reach from one square to another square of a chess board (8X8). Nakul is brilliant and he had already written a program to solve the problem. Nakul wants to know whether Anjali can do it. Anjali is very weak in programming. Help her to solve the problem.

A knight can move in the shape of an "L" in a chessboard - two squares either forward, backward, left, or right and then one square to its left or right. A knight move is valid if it moves as mentioned above and it is within the boundary of the chessboard (8 X 8).

knight

Input
There are T test cases in total. The next T lines contain two strings (start and destination) separated by a space.

The strings start and destination will only contain two characters - First character is an alphabet between 'a' and 'h' (inclusive), Second character is a digit between '1' and '8' (inclusive) - (Quotes just for clarity).

To know the knight moves more clearly refer to the above figure.

Output
Print the minimum number of moves a knight takes to reach from start to destination in a separate line.

Constarints
1 <= T <= 4096

Example
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> g[N];
int level[8][8];
int vis[8][8];

int getX(string s) {
   return s[0] - 'a';
}

int getY(string s) {
   return s[1] - '1';
}

bool isValid(int x, int y) {
   return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int, int>> movements = {
   { -1, 2}, {1, 2},
   { -1, -2}, {1, -2},
   {2, -1}, {2, 1},
   { -2, -1}, { -2, 1}
};

int bfs(string src, string des) {
   int srcX = getX(src);
   int srcY = getY(src);
   int desX = getX(des);
   int desY = getY(des);

   queue<pair<int, int>> q;
   q.push({srcX, srcY});
   vis[srcX][srcY] = 1;
   level[srcX][srcY] = 0;
   while (!q.empty()) {
      pair<int, int> cv = q.front();
      int x = cv.first, y = cv.second;
      q.pop();

      for (auto movement : movements) {
         int childX = movement.first + x;
         int childY = movement.second + y;
         if (!isValid(childX, childY)) continue;
         if (!vis[childX][childY]) {
            q.push({childX, childY});
            level[childX][childY] = level[x][y] + 1;
            vis[childX][childY] = 1;
         }
      }
      if (level[desX][desY] != INF) {
         break;
      }

   }
   return level[desX][desY];
}

void reset() {
   for (int i = 0; i < 8; ++i)
   {
      for (int j = 0; j < 8; ++j)
      {
         level[i][j] = INF;
         vis[i][j] = 0;
      }
   }
}


int main() {
   int n;
   cin >> n ;
   while (n--) {
      reset();
      string s1, s2;
      cin >> s1 >> s2;
      cout << bfs(s1, s2) << endl;
   }




   return 0;
}