#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,0,m)REP(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
using namespace std;
typedef long long ll;
int n, k;
pair<int, int> seq[105];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> seq[i].first;
        seq[i].second = i;
    }
    vector<pair<int, int> >ret;
    int mini = 0;
    for(int i = 0; i < k; ++i) {
        sort(seq, seq + n);
        mini = seq[n - 1].first - seq[0].first;
        if(seq[0].first == seq[n - 1].first)break;
        ret.push_back(make_pair(seq[n - 1].second, seq[0].second));
        seq[0].first++;
        seq[n - 1].first--;
    }
    sort(seq, seq + n);
    mini = seq[n - 1].first - seq[0].first;

    cout << mini << " " << ret.size() << '\n';

    for(auto u : ret)cout << (u.first + 1) << " " << (u.second + 1) << '\n';

    return 0;
}

