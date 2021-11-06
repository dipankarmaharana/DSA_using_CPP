#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int m_ct[N];
int hsh[N];


int main() {
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i)
   {
      int x;
      cin >> x;
      hsh[x]++;
   }
   for (int i = 1; i < N; ++i)
   {
      for (int j = i; j < N; j += i)
      {
         m_ct[i] += hsh[j];
      }
   }
   int t;
   cin >> t;
   while (t--) {
      int p, q;
      cin >> p >> q;
      long long lcm = p * 1LL * q / __gcd(p, q);
      long ans = m_ct[p] + m_ct[q];
      if (lcm < N) {
         ans -= m_ct[lcm];
      }
      cout << ans << endl;
   }
   return 0;
}