// Shivambu Dev Pandey
// 23bcs123
// CS202 - DAA
// Lab 5
// 23/08/2024
// Program 2 :  Greedy Knapsack


#include <bits/stdc++.h>
using namespace std;

struct Item {
    int val, wt;
    Item(int val, int wt) {
        this->val = val;
        this->wt = wt;
    }
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.val / (double)a.wt;
    double r2 = (double)b.val / (double)b.wt;
    return r1>r2;
}

double fracKnapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), cmp);

    int curWt = 0;
    double finalVal = 0.0;

    for(int i = 0; i<n; i++) {
        if(curWt + items[i].wt <= W) {
            curWt += items[i].wt;
            finalVal += items[i].val;
        } else {
            int remWt = W - curWt;
            finalVal += items[i].val * ((double)remWt / (double)items[i].wt);
            break;
        }
    }

    return finalVal;
}

int main() {
    int n, W;
    cout<<"Enter the number of items: ";   cin>>n;
    cout<<"Enter the knapsack capacity: "; cin>>W;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        int val, wt;
        cout<<"Enter val and wt for item "<<i+1<<": ";
        cin>>val>>wt;
        items.push_back(Item(val, wt));
    }

    double maxVal = fracKnapsack(W, items, n);
    cout<<"Maximum val in Knapsack = "<<maxVal<<endl;

    return 0;
}
