#include <bits/stdc++.h>
using namespace std;
//const int M = 10e9 + 7;

int main() {
   int n;
   cin >> n;
   vector<int> prime_factors;
   for (int i = 2; i <= n; ++i)
   {
      while (n % i == 0) {
         prime_factors.push_back(i);
         n /= i;
      }
   }
   if (n > 1)
   {
      prime_factors.push_back(n);
   }
   for (int prime : prime_factors)
   {
      cout << prime << endl;
   }
   return 0;
}