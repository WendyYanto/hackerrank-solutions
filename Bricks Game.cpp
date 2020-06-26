#include <bits/stdc++.h>
using namespace std;

// I Don't Understand This Shit
// To Do

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

long long maximum(int index, long long bricks[], int n) {
    long long F[n];
    long long sum = 0;
    for(int i=n-1; i>=0; i--) {
        sum += bricks[i];
        if(i >= n-3) {
            // Base Case
            F[i] = sum;
        } else {
            // This will always find maximum step
            // For Each Opponent
            // [First and Second]
            long long take1 = sum - F[i+1];
            long long take2 = sum - F[i+2];
            long long take3 = sum - F[i+3];
            F[i] = max(take1, max(take2, take3));
        }
    }
    // Why should index 0
    return F[0];
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int t;
        cin>>t;
        long long bricks[t+1];
        for(int i=0;i<t;i++){
            cin>>bricks[i];
        }
        cout<<maximum(0, bricks, t)<<endl;
    }
    return 0;
}

// Other Solution

// int main() {
// 	int T;
// 	cin>>T;
// 	while(T > 0) {
// 		int N;
// 		cin>>N;
// 		long long *bricks = new long long[N];
// 		long long *sum = new long long[N]; // sum[i] = sum of bricks up to i
// 		for(int i = 0; i < N; i++) {
// 			cin>>bricks[N-i-1];
// 		}
// 		sum[0] = bricks[0];
// 		for(int i = 1; i < N; i++) {
// 			sum[i] = sum[i-1] + bricks[i];
// 		}
// 		if(N < 4) {
// 			// Edge case
// 			cout<<sum[N-1]<<"\n";
// 			T--;
// 		} else {
// 			// Notice that taking Y bricks is equivalent to playing a new game with N-Y bricks where
// 			// your friend goes first and you start with a score of the sum of the Y bricks.
// 			long long *dp = new long long[N];
// 			dp[0] = sum[0];
// 			dp[1] = sum[1];
// 			dp[2] = sum[2];
// 			for(int i = 3; i < N; i++) {
// 				// Take the # of bricks which maximizes your score
// 				dp[i] = sum[i] - dp[i-3]; // 3 bricks
// 				dp[i] = max(dp[i], sum[i] - dp[i-2]); // 2 bricks
// 				dp[i] = max(dp[i], sum[i] - dp[i-1]); // 1 brick
// 			}
// 			cout<<dp[N-1]<<"\n";
// 			T--;
// 		}
// 	}
// 	return 0;
// }
