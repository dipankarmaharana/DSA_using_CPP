#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*Euler Totient Function(ETF): For a number N, count of K
s.t 1<=K<=N where K,N-->coprimes. Ex. ETF(5)=4, ETF(6)=2.

@link https://cp-algorithms.com/algebra/phi-function.html
*/


int binExp(int a, long long b, int m) {
   int ans = 1;
   while (b) {
      if (b & 1) {
         ans = (ans * 1LL * a) % m;
      }
      a = (a * 1LL * a) % m;
      b >>= 1;
   }
   return ans;
}


int main() {
   //50^64^32
   cout << binExp(a, binExp(64, 32, M - 1), M) << endl; //using Eular's Theorem


   return 0;
}