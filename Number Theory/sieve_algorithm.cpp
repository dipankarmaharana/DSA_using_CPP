#include <bits/stdc++.h>
using namespace std;
const int N = 10e7 + 10;
vector<bool> is_prime(N, 1);

//Sieve Algorithm

int main() {
   is_prime[0] = is_prime[1] = false;
   for (int i = 2; i < N; ++i)
   {
      if (is_prime[i] == true)
      {
         for (int j = 2 * i; j < N; j += i)
         {
            is_prime[j] = false;
         }
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int num;
      cin >> num;
      if (is_prime[num]) {
         cout << "prime" << endl;
      } else {
         cout << "not prime" << endl;
      }
   }
   return 0;
}