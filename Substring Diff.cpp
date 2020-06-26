// #include <bits/stdc++.h>
// using namespace std;

// // Solution
// //https://www.quora.com/What-is-the-algorithmic-approach-to-solve-hackerrank-problem-Substring-Diff

// To Do

// // Too Much Memory
// int memo[1500][1500][1500];

// int max(int a, int b) {
//     if (a>b){
//         return a;
//     }
//     return b;
// }

// int longestCommon(int firstIndex, int secondIndex, string first, string second, int k) {
//     // Not slow but maximum number is 1500 which mean 1500^3 causing error in array
//     if (memo[firstIndex][secondIndex][k] != -1) {
//         return memo[firstIndex][secondIndex][k];
//     }
//     if (k < 0) {
//         return 0;
//     }
//     if (firstIndex == (int) first.size() || secondIndex == (int) second.size()) {
//         return 0;
//     }
//     if (first[firstIndex] == second[secondIndex]) {
//         return memo[firstIndex][secondIndex][k] = 1 + longestCommon(firstIndex+1, secondIndex+1, first, second, k);
//     }
//     return memo[firstIndex][secondIndex][k] = 1 + max(
//         longestCommon(firstIndex, secondIndex+1, first, second, k - 1),
//         longestCommon(firstIndex+1, secondIndex, first, second, k - 1)
//     );
// }

// int main() {
//     int n;
//     cin>>n;
//     while(n--) {
//         int k;
//         cin>>k;
//         string first,second;
//         cin>>first>>second;
//         int length = first.length();
//         int maxLength = 0;
//         // Still miss one test case
//         for(int i=0;i<length && maxLength < length - i;i++) {
//             for(int j=0;j<length && maxLength < length - j;j++) {
//                 int I = i;
//                 int J = j;
//                 int diff = 0;
//                 int L = 0;
//                 while(I < length && J < length) {
//                     if (first[I] != second[J]) {
//                         diff++;
//                     }
//                     L++;
//                     if (diff <= k) {
//                         maxLength = max(maxLength, L);
//                     } else {
//                         break;
//                     }
//                     I++;
//                     J++;
//                 }
//             }
//         }
//         cout<<maxLength<<endl;
//     }
//     return 0;
// }

// Correct Solution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1500
int main(void){
    int num_cases;
    int k;
    char string1[MAX_SIZE+1],string2[MAX_SIZE+1];
    char diff_array[MAX_SIZE][MAX_SIZE];
    int length;
    int i;

    scanf("%d",&num_cases);
    while(num_cases--){
        scanf("%d %s %s",&k,string1,string2);
        length=strlen(string1);


        int j;
        for(i=0;i<length;i++){
            for(j=0;j<length;j++)
                diff_array[i][j]=(string1[i]!=string2[j]);
        }
        int front_pointer,back_ptr1,back_ptr2,front_sum1,front_sum2,curr_max=-1;
        int back_sum1,back_sum2;
        for(i=0;i<length;i++){
            front_sum1=front_sum2=back_sum1=back_sum2=0;
            back_ptr1=back_ptr2=-1;
            for(front_pointer=0;front_pointer+i<length;front_pointer++){
                front_sum1+=diff_array[front_pointer][i+front_pointer];
                front_sum2+=diff_array[i+front_pointer][front_pointer];
                while(front_sum1-back_sum1>k){
                    back_ptr1++;
                    back_sum1+=diff_array[back_ptr1][i+back_ptr1];
                }
                while(front_sum2-back_sum2>k){
                    back_ptr2++;
                    back_sum2+=diff_array[i+back_ptr2][back_ptr2];
                }

                if(front_pointer-back_ptr1>curr_max)
                    curr_max=front_pointer-back_ptr1;
                if(front_pointer-back_ptr2>curr_max)
                    curr_max=front_pointer-back_ptr2;
            }
        }
        printf("%d\n",curr_max);
    }
    return 0;
}