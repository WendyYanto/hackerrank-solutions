#include <bits/stdc++.h>
using namespace std;

// Backtracking 

vector<string> answers;
map<int, int> memos;

bool traverse(string attempt, string words[], int n) {
    // Check if current string already been flag as fail attempt 
    // [by length because it will always different every loop]
    if (memos[attempt.length()] == -1) {
        return false;
    }
    if (attempt == "") {
        // Print out answer
        for(int i=0;i<answers.size();i++) {
            cout<<answers[i];
            if(i < answers.size() - 1) {
                cout<<" ";
            }
        }
        cout<<endl;
        return true;
    }
    for(int i=0;i<n;i++) {
        if (attempt.find(words[i]) == 0) {
            string check = attempt;
            check.erase(0, words[i].length());
            answers.push_back(words[i]);
            // if finally this word[i] concating return false then it is invalid
            if(!traverse(check, words, n)) {
                // Pop back the current word[i] and proceed next word
                memos[check.length()] = -1;
                answers.pop_back();
                continue;
            }
            // Return true when the finally it reach attempt == "", to stop loop
            return true;
        }
    }
    memos[attempt.length()] = - 1;
    return false;
}   

int main() {
    int n;
    cin>>n;
    while(n--) {
        int m;
        cin>>m;
        string words[m+1];
        for(int i=0;i<m;i++) {
            cin>>words[i];
        }
        string attempt;
        cin>>attempt;
        if(!traverse(attempt, words, m)){
            cout<<"WRONG PASSWORD"<<endl;
        }
        memos.clear();
        answers.clear();
    }
    return 0;
}