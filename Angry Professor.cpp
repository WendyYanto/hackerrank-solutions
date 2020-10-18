#include <bits/stdc++.h>
using namespace std;

int main() {
  int countOfTestCase;
  cin>>countOfTestCase;
  while(countOfTestCase--) {
    int countOfStudent, cancelledThreshold;
    cin>>countOfStudent>>cancelledThreshold;
    vector<int> students;
    while(countOfStudent--) {
      int student;
      cin>>student;
      students.push_back(student);
    }
    int countOfOnTimeStudents = 0;
    for(int i=0;i<students.size();i++) {
      if (students[i] <= 0) {
        countOfOnTimeStudents++;
      }
    }
    if (countOfOnTimeStudents >= cancelledThreshold) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
    }
  }
  return 0;
}