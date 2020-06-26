#include <bits/stdc++.h>
using namespace std;

bool isKaprekar(long long n) {
    long long target = n;
    long long square = n*n;
    long long digit = to_string(n).size();
    long long right = 0;
    long long index = 0;
    long long power = 1;
    while(index < digit) {
        int remainder = square % 10;
        remainder *= power;
        right += remainder;
        square /= 10;
        power *= 10;
        index++;
    }
    return square + right == n;
}

vector<long long> generateKaprekarNumbers(long long start, long long end) {
    vector<long long> result;
    for(long long i=start;i<=end;i++) {
        if (isKaprekar(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    long start,end;
    cin>>start>>end;
    vector<long long> output = generateKaprekarNumbers(start, end);
    int size = output.size();
    if (size == 0) {
        cout<<"INVALID RANGE"<<endl;
    } else {
        for(int i=0;i<size;i++) {
            cout<<output[i];
            if(i < size - 1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}