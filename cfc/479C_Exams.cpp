#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,0,m)REP(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
using namespace std;
typedef long long ll;
#define INF 1<<30
int n;
pair<int, int> seq[5005];

int getDay(int idx, int day) {
    if(day == 0)return seq[idx].first;
    return seq[idx].second;
}
int dp[5002][2];
int go(int idx, int day) {
    if(idx >= n)return getDay(idx - 1, day);
    int& ref = dp[idx][day];
    if(ref != -1)return ref;
    ref = INF;
    int curDay = getDay(idx - 1, day);
    if(curDay <= seq[idx].second)ref = min(ref, go(idx + 1, 1));
    if(curDay <= seq[idx].first)ref = min(ref, go(idx + 1, 0));
    return ref;
}

int main() {
    cin >> n;
    REP(i, n)cin >> seq[i].first >> seq[i].second;
    sort(seq, seq + n);
    memset(dp, -1, sizeof dp);
    int ans = min(go(1, 0), go(1, 1));    
    cout << ans << '\n';
    return 0;
}

