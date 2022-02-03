#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e3 + 7;

void sort_k_sorted_array(int *arr, int n, int k)
{
   priority_queue <int, vector<int>, greater<int>> minh;
   int j = 0;
   for (int i = 0; i < n; i++)
   {
      minh.push(arr[i]);
      if (minh.size() > k)
      {
         arr[j] = minh.top();
         minh.pop();
         j++;
      }
   }
   while (minh.size() > 0)
   {
      j++;
      arr[j] = minh.top();
      minh.pop();
   }

}

void print_array(int *arr, int n)
{
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

int main() {

   int arr[] = {6, 5, 3, 2, 8, 10, 9};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;
   cout << "Sort the k sorted array in which k = 3" << endl;
   cout << "\nThe Sorted array : ";
   sort_k_sorted_array(arr, n, k);
   print_array(arr, n);
   return 0;

}