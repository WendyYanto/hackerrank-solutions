#include <bits/stdc++.h>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    // by using arithmetic equation 
    // a + (n-1) b = a1 + (n-1) b1
    double n = (double) (x1 - x2 - v1 +  v2) /  (v2  - v1);
    // By arithmetic equation n cannot be 0 or less 
    if  (n <= 0) {
        return "NO";
    } 
    // if n results in fraction then it is invalid
    if (n != (int) n) {
        return "NO";
    } 
    return "YES";
}