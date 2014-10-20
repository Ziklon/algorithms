#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,0,m)REP(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    ans = max(ans, (a + b) * c);
    ans = max(ans, (a * b) * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, (a + b + c));
    cout << ans << endl;
    return 0;
}

