// To Do

// #include <iostream>
// using namespace std;
// int parent[1000];

// void makeSet(int n){
// 	for(int i=0;i<n;i++){
// 		parent[i] = i;	
// 	}
// }

// int findParent(int n){
// 	if(parent[n] == n){
// 		return parent[n];
// 	}
// 	parent[n] = findParent(parent[n]);
// }

// void merge(int source, int destination){
// 	parent[findParent(source)] = findParent(destination);
// }

// bool isSameSet(int a, int b){
// 	return findParent(a) == findParent(b);
// }

// int main() {

//     return 0;
// }