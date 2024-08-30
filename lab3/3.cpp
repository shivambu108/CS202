// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 3
// 23/08/2024
// Program 3 : Implement selection sort on user input.

#include<bits/stdc++.h>
using namespace std;


void selectionSort(vector<int>& a, int n) {
    int i, j, mn;

    for(i = 0; i<n-1; i++) {
        mn = i;
        for(j = i+1; j<n; j++)  if(a[j]<a[mn])  mn = j;
        if(mn!=i) swap(a[i], a[mn]);
    }
}


int main() {
    int n;
    cout<< "Enter the number of elements: "; cin>> n;

    vector<int> a(n);
    cout<< "Enter the elements: ";
    for(int i = 0; i<n; i++) cin>>a[i];

    selectionSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i<n; i++)  cout<<a[i]<<" ";
    cout<<endl;
   
    return 0;
}