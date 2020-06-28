#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int moneys;
    cin>>n;
    cin>>moneys;
    int totalToys[n];
    int counter = 0;
    for(int i=0;i<n;i++){
        cin>>totalToys[i];
    }
    sort(totalToys, totalToys+n);
    for(int i=0;i<n;i++){
        if((moneys - totalToys[i])>0){
            moneys -= totalToys[i];
            counter++;
        }else{
            break;
        }
    }
    cout<<counter<<endl;
    return 0;
}