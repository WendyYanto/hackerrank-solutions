#include <bits/stdc++.h>
#include <map>

using namespace std;

int absolute(int a){
	if(a<0){
		return -a;
	}
	return a;
}

int makeAnagram(string a, string b) {
    map<char, int> characterMap;
	
    for(int i=0;i<a.length();i++){
		characterMap[a[i]]++;
    }

    for(int i=0;i<b.length();i++){
		characterMap[b[i]]--;
    }

    int output = 0;
	for(map<char, int>::iterator it = characterMap.begin();it != characterMap.end(); ++it){
		output += absolute(it->second);
	}
    return output;
}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);
	
	cout<<res<<endl;

	return 0;
}

