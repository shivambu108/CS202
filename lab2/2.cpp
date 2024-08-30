// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 2
// 23/08/2024
// Program 2 : Implement quick sort on user input.


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j<r; j++) {
        if(a[j]<pivot) swap(a[++i], a[j]);
    }
    swap(a[i+1], a[r]);
    return i+1;
}


void quickSort(vector<int> &a, int l, int r) {
    if(l<r) {
        int pi = partition(a, l, r);
        quickSort(a, l, pi-1);
        quickSort(a, pi+ 1 , r );
    }
}


int main() {
    int n;
    cout<< "Enter the number of elements: "; cin>> n;

    vector<int> a(n);
    cout<< "Enter the elements: ";
    for(int i = 0; i<n; i++) cin>>a[i];

    quickSort(a, 0, n-1);

    cout << "Sorted array: ";
    for(int i = 0; i<n; i++)  cout<<a[i]<<" ";
    cout<<endl;
   
    return 0;
}
