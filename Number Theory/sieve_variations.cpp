#include <bits/stdc++.h>
using namespace std;
const int N = 10e7 + 10;
vector<bool> is_prime(N, 1);
vector<int> lp(N, 0), hp(N);

//Sieve Algorithm

int main() {
   is_prime[0] = is_prime[1] = false;
   for (int i = 2; i < N; ++i)
   {
      if (is_prime[i] == true)
      {
         lp[i] = hp[i] = i;
         for (int j = 2 * i; j < N; j += i)
         {
            is_prime[j] = false;
            hp[j] = i;
            if (lp[j] == 0) lp[j] = i;
         }
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int num;
      cin >> num;
      while (num > 1) {
         int prime_factor = hp[num];
         while (num % prime_factor == 0) {
            num /= prime_factor;
            primefactors[prime_factor]++;
         }
      }
   }
   for (auto factor : primefactors) {
      cout << factor.first << " " << factor.second << endl;
   }
   return 0;
}