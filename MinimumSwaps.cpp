#include<bits/stdc++.h> 
using namespace std;

int minimumSwaps(int numbers[], int n){
    int counter = 0;
    vector< pair<int,int> > sortedNumbers;
    for(int i=0;i<n;i++){
        sortedNumbers.push_back(make_pair(numbers[i], i));
    }
    sort(sortedNumbers.begin(), sortedNumbers.end());
    map<int, int> visited;
    for(int i=0;i<n;i++){
        int size = 0;
        if(visited[i] != 0) {
            continue;
        }
        if(sortedNumbers[i].second == i) {
            continue;
        }
        int temp = i;
        while(visited[temp] == 0) {
            visited[temp] = 1;
            temp = sortedNumbers[temp].second;
            size++;
        }
        counter += (size - 1);
    }
    return counter;
}

int main(){
    int n;
    cin>>n;
    int numbers[n+1];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    cout<<minimumSwaps(numbers, n)<<endl;
    return 0;
}