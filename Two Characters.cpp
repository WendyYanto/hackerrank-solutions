#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    return b;
}

int main() {
    int n;
    string word;
    cin >> n;
    cin >> word;
    int count[26][26] = {0};
    int matrix[26][26];

    if (n == 1) {
        cout << 0 << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            // traverse columns
            for (int j = 0; j < 26; j++) {
                if (matrix[index][j] == index) {
                    count[index][j] = -1;
                }
                if (count[index][j] != -1) {
                    matrix[index][j] = index;
                    count[index][j]++;
                }
            }
            // traverse row
            for (int j = 0; j < 26; j++) {
                if (matrix[j][index] == index) {
                    count[j][index] = -1;
                }
                if (count[j][index] != -1) {
                    matrix[j][index] = index;
                    count[j][index]++;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (count[i][j] != -1) {
                    result = max(result, count[i][j]);
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}