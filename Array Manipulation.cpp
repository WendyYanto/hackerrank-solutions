#include <bits/stdc++.h>
using namespace std;

// 1 2 100
// 2 5 100
// 3 4 100

// 100 0 -100 0 0
// 100 100 -100 0 0 -100
// 100 100 0 -100 0

int main() {
    int n, t;
    cin>>n>>t;
    static long long numbers[10000010];
    for(int i=1;i<=n;i++) {
        numbers[i] = 0;
    }
    while(t--) {
        long long start,end,counter;
        cin>>start>>end>>counter;
        numbers[start] += counter;
        // To avoid overriding the previous added end
        // 
        numbers[end + 1] -= counter;
    }
    long long max = 0;
    long long x = 0;
    for(int i=1;i<=n;i++) { 
        x += numbers[i];
        if (x>max) {
            max = x;
        }
    }
    cout<<max<<endl;
    return 0;
}
