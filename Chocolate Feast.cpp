#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  while(n--) {
    int money, price, countOfBonus;
    cin>>money>>price>>countOfBonus;
    int items = (int) (money / price);
    int output = items;
    int bonus = items / countOfBonus;
    int left = items % countOfBonus;
    while(bonus > 0) {
      output += bonus;
      bonus += left;
      left = bonus % countOfBonus;
      bonus = bonus / countOfBonus;
    }
    cout<<output<<endl;
  }
  return 0;
}