#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

int main() {
    set<char> S;
    string s;
    getline(cin,s);
    for(char c: s)if(isalpha(c)) S.insert(c);
    
    cout<<S.size()<<endl;
    
    return 0;
}
