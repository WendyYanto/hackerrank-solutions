#include <bits/stdc++.h>
using namespace std;

int absolute(int a) {
    if(a<0) {
        return -a;
    }
    return a;
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main() {
    int array[4][4];
    int solutions[8][3][3] = {
            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
    };
    // Or other solutions is rotate (4 times) and transpose (2 times) then compare sum 
    // Complexity is higher n2 + n2 + n2
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            cin>>array[i][j];
        }
    }
    int sum = 15;
    int result = INT_MAX;
    for(int i=0;i<8;i++) {
        int output = 0;
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++){
                output += absolute(solutions[i][j][k] - array[j][k]);
            }
        }
        result = min(result, output);
    }
    cout<<result<<endl;
    return 0;
}





