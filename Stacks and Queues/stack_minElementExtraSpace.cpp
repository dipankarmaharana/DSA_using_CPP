#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e3 + 7;

stack<int> s;
stack<int> ss;

void push(int a) {
   if (ss.empty() || ss.top() >= a) {
      ss.push(a;)
   }
   s.push(a);
   return;
}

int pop() {
   if (s.empty()) return -1;
   int ans = s.top();
   s.pop();
   if (ss.top() == ans) ss.pop();
   return ans;
}

int getMinElement() {
   if (ss.empty()) return -1;
   return ss.top();
}

int main() {

}