// To Do

string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    for(int i=0;i<A.size();i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    //
}