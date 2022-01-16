#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e3 + 7;

stack<int> s;
int minEle;

void push(int a) {
   if (s.empty()) {
      s.push(a);
      minEle = a;
   }
   else {
      if (a > minEle) s.push(a);
      else if (a < minEle) {
         s.push(2 * a - minEle);
         minEle = a;
      }
   }
}

void pop() {
   if (s.empty()) return -1;
   else {
      if (s.top() >= minEle) s.pop();
      else if (s.top() < minEle) {
         minEle = 2 * minEle - s.top();
         s.pop();
      }
   }
}

int top() {
   if (s.empty()) return -1;
   else {
      if (s.top() >= minEle) return s.top();
      else return minEle;
   }
}

int getMinElement() {
   if (s.empty()) return -1;
   return minEle;
}

int main() {

}