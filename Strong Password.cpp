#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    bool isUpper = false;
    bool isLower = false;
    bool isNumber = false;
    bool isSpecial = false;
    // Return the minimum number of characters to make the password strong
    for(int i=0;i<n;i++) {
        if (isdigit(password[i])) {
            isNumber = true;
        } 
        if (isupper(password[i])) {
            isUpper = true;
        }
        if (islower(password[i])) {
            isLower = true;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i]
        == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' ||
        password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] ==
        '-' || password[i] == '+') {
            isSpecial = true;
        }
    }
    if (isNumber && isUpper && isLower && isSpecial) {
        if (n < 6) {
            return 6 - n;
        } else {
            return 0;
        }
    }
    int count = 0;
    if (!isNumber) {
        count++;
    } 
    if (!isLower) {
        count++;
    }
    if (!isUpper) {
        count++;
    }
    if (!isSpecial) {
        count++;
    }

    // count = total characters should add
    // 6 is at least
    if (n > 6) {
        return count;
    } else {
        if (count + n >= 6) {
            return count;
        } else {
            return 6 - n;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
