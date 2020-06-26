#include <bits/stdc++.h>
using namespace std;

int previousIndex = 0;
int currentRank = 1;

int getRank(int n, int scores[]) {
    for(int i=previousIndex; i>=0; i--) {
        if (currentRank == 1) {
            break;
        }
        if (scores[i] > n) {
            previousIndex = i;
            break;
        }
        currentRank--;
    }
    if (currentRank <= 0) {
        currentRank = 1;
    }
    return currentRank;
}

vector<int> fetchRanks(vector<int> array, vector<int> scores, int arraySize, int scoreSize) {
    vector<int> answer;
    int uniqueScores[scoreSize + 1];
    uniqueScores[0] = scores[0];
    int prev = scores[0];
    int count = 1;
    for(int i=1;i<scoreSize; i++) {
        if (scores[i] == prev) {
            continue;
        }
        uniqueScores[count] = scores[i];
        prev = scores[i];
        count++;
    }
    int size = count;
    previousIndex = size - 1;
    currentRank = size + 1;
    for(int i=0; i<arraySize; i++) {
        if (currentRank <= 0) {
            answer.push_back(1);
        } else {
            answer.push_back(getRank(array[i], uniqueScores));
        }
    }
    return answer;
}

int main() {
    int n;
    cin>>n;
    vector<int> scores;
    for(int i=0;i<n;i++) {
        int input;
        cin>>input;
        scores.push_back(input);
    }
    int count;
    cin>>count;
    vector<int> array;
    for(int i=0;i<count;i++) {
        int input;
        cin>>input;
        array.push_back(input);
    }
    vector<int> result = fetchRanks(array, scores, count, n);
    for (int i=0;i<result.size();i++) {
        cout<<result[i]<<endl;
    }
    return 0;
}