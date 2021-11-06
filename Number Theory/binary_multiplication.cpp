#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binMul(long long a, long long b);

//a<=10^9, b<=10^9, M<=10^9 --> we assummed this in binExp
//if a<=10^18 and m<=10^9 then we can take a%m.
//if a<=10^18 and m<=10^18, a=(a*1LL*a)%M is not possible because of overflow.
//so rather than multiplying directly we add them and take modulo.


int binExp(long long a, long long b) {
   int ans = 1;
   while (b) {
      if (b & 1) {
         ans = binMul(ans, a);
      }
      a = binMul(a, a);
      b >>= 1;
   }
   return ans;
} //log^2(N) complexity

int binMul(long long a, long long b) {
   int ans = 0;
   while (b) {
      if (b & 1) {
         ans = (ans + a) % M;
      }
      a = (a + a) % M;
      b >>= 1;
   }
   return ans;
}

int main() {
   int a = 2, b = 13;
   cout << binExp(a, b) << endl;


   return 0;
}