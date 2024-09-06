// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 3
// 23/08/2024
// Program 2 : Select ith smallest element from an unsorted array.

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j<r; j++)  if(a[j]<pivot) swap(a[++i], a[j]);
    swap(a[i+1], a[r]);
    return i+1;
}

int select(vector<int>& a, int l, int r, int i) {
    if(l==r)  return a[l];
    int p = partition(a, l, r);
    int k = p - l + 1;
    if(i==k)  return a[p];
    else if(i<k) return select(a, l, p - 1, i);
    else  return select(a, p + 1, r, i - k);
}

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++)  cin>>a[i];

    int i;
    cout<<"Enter the value of i (1-indexed): ";
    cin>>i;

    srand(time(0));  

    int res = select(a, 0, n - 1, i);
    cout << "The " << i << "(st/nd/rd/th) smallest element is " << res << endl;

    return 0;
}
