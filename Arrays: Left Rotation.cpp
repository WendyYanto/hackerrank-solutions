#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n;
    int rotate;
    cin>>n;
    cin>>rotate;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int x = rotate%n;
    for(int i=x;i<n;i++){
        cout<<array[i]<<" ";
    }
    for(int i=0;i<x;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
