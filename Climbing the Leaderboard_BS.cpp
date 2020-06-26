#include <bits/stdc++.h>
using namespace std;

int last_right = -1;

int binarySearch(int left, int right, int n, vector<int> scores) {
    int mid = (left + right) / 2;
    // 100 90 80 75 60
    if (left < right) {
        if (n == scores[mid]) {
            last_right = right;
            return mid + 1;
        } else if (n < scores[mid]) {
            return binarySearch(mid+1, right, n, scores);
        } else if (n > scores[mid]) {
            return binarySearch(left, mid, n, scores);
        }
    }
    last_right = right;
    return left + 1;
}

vector<int> fetchRanks(vector<int> array, vector<int> scores) {
    vector<int> answer;
    vector<int> uniqueScores;
    uniqueScores.push_back(scores[0]);
    int prev = scores[0];
    for(int i=1;i<scores.size(); i++) {
        if (scores[i] == prev) {
            continue;
        }
        uniqueScores.push_back(scores[i]);
        prev = scores[i];
    }
    int output;
    last_right = uniqueScores.size() - 1;
    for(int i=0; i<array.size(); i++) {
        if (uniqueScores[last_right] > array[i]) {
            output = last_right + 2;
        } else if (last_right == 0) {
            output = 1;
        } else {
            output = binarySearch(0, last_right, array[i], uniqueScores);
        }
       answer.push_back(output);
    }
    return answer;
}

int main() {
    int n;
    cin>>n;
    vector<int> scores;
    while(n--) {
        int input;
        cin>>input;
        scores.push_back(input);
    }
    int count;
    cin>>count;
    vector<int> array;
    while(count--) {
        int input;
        cin>>input;
        array.push_back(input);
    }
    vector<int> result = fetchRanks(array, scores);
    for (int i=0;i<result.size();i++) {
        cout<<result[i]<<endl;
    }
    return 0;
}