#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) {
  if (a>b) return b;
  return a;
}

int main() {
  int target;
  string firstWord, secondWord;
  cin>>firstWord>>secondWord;
  cin>>target;
  int firstWordLength = firstWord.length();
  int secondWordLength = secondWord.length();
  int n = min(firstWordLength, secondWordLength);
  int equalLength = 0;
  for(int i=0;i<n;i++) {
    if (firstWord[i] != secondWord[i]) {
      break;
    }
    equalLength++;
  }
  if (firstWordLength + secondWordLength - (2*equalLength) > target) {
    // To handle definitely invalid
    // Example: "Hallo" and "Haiiii" , target = 8
    // Need to delete llo (3 chars) and append into iiii (4 chars) -> operation should be equal to 7
    // ha (2) + llo (3) + ha (2) + iiii (4) - 2 * ha (2) = 7
    cout<<"No"<<endl;
  } else if ((firstWordLength + secondWordLength - (2*equalLength))%2 == target%2) {
    // To handle substring firstWord in secondWord or viceversa
    // Example 1 - "Hi" and "Hihi" , target = 6
    // Need to delete hi (2) remainder 4 can be used append then delete (useless operation to satisty target)
    // Example 2 - "HiHi" and "Hihih", target = 2
    // Will need to 1 delete operation
    // but cannot append and delete because it should equal to odd to satisty useless operation
    cout<<"Yes"<<endl;
  } else if (firstWordLength + secondWordLength - target < 0) {
    // To handle additional delete operation on empty string 
    // Example: "Hi" and "Haa", target = 8
    // Need to delete Haa and add Hi, remainder can be used to delete empty string
    cout<<"Yes"<<endl;
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}