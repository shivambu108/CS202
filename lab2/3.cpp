//not working 

#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& a, int l, int m, int r) {
    int sz1 = m - l + 1, sz2 = r - m;


    vector<int> A1(sz1), A2(sz2);


    for (int i = 0; i < sz1; i++) A1[i] = a[l + i];
    for (int j = 0; j < sz2; j++) A2[j] = a[m + 1 + j];


    int i = 0, j = 0, k = l;


    while (i < sz1 && j < sz2) {
        if (A1[i] <= A2[j]) a[k] = A1[i++];
        else a[k] = A2[j++];
        k++;
    }


    while (i < sz1) {
        a[k] = A1[i];
        i++;
        k++;
    }
    while (j < sz2) {
        a[k] = A2[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& a, int n) {
    int width = 1;
    while (width < n) {
        int l = 0;
        while (l < n) {
            int m = l + width - 1;
            int r = min(l + 2 * width - 1, n - 1);


            int randomL = l + rand() % (m - l + 1);
            int randomR = m + 1 + rand() % (r - m);


            swap(a[randomL], a[randomR]);


            merge(a, l, m, r);
            l += 2 * width;
        }
        width *= 2;
    }
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;


    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];


    mergeSort(a, n);


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;


    return 0;
}
