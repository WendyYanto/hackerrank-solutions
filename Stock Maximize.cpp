#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a>b){
        return a;
    }
    return b;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int maximumStocks(int stocks[], int index, int n, vector<int> curr, int money) {
    // Consume Memory Too Much 
    if (money < 0) {
        return 0;
    }
    if (index == n) {
        return money;
    }
    vector<int> purchase = curr;
    vector<int> sellAll = curr;
    int sell = 0;
    for(int i=0;i<sellAll.size();i++) {
        sell += (stocks[index] - sellAll[i]);
    }
    sellAll.clear();
    purchase.push_back(stocks[index]);
    return max(
        // Do nothing
        maximumStocks(stocks, index+1, n, curr, money),
        // Sell
        maximumStocks(stocks, index+1, n, sellAll, money + sell),
        // Buy
        maximumStocks(stocks, index+1, n, purchase, money)
        );
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int count;
        cin>>count;
        int array[count+1];
        for(int i=0;i<count;i++) {
            cin>>array[i];
        }
        long profit = 0;
        int maxSoFar = 0;
        for(int i=count - 1;i>-1;i--) {
            if (array[i] >= maxSoFar) {
                maxSoFar = array[i];
            }
            profit += (maxSoFar - array[i]);
        }
        cout<<profit<<endl;
    }
    return 0;
}