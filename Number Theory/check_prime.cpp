#include <bits/stdc++.h>
using namespace std;
//const int M = 10e9 + 7;


int main() {
   int n;
   cin >> n;
   bool is_prime = true;
   for (int i = 2; i * i < n; ++i)
   {
      if (n % i == 0) {
         is_prime = false;
         break;
      }
   }
   //O(N)
   cout << is_prime << endl;
   return 0;
}