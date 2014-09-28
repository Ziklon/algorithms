#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
map<int, int>M;
int x;
int main() {
    bool can = 0;
    for(int i = 0; i < 6; ++i) {
        cin >> x;
        M[x]++;
        if(M[x] == 4) {
            M.erase(x);
            can = 1;
        }
    }
    if(can && M.size() == 1)cout << "Elephant" << endl;
    else
        if(can && M.size() == 2)cout << "Bear" << endl;
        else cout << "Alien" << endl;
    return 0;
}

