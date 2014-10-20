#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; REP(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,0,m)REP(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
using namespace std;
typedef long long ll;
int n, L, x, y ;
ll seq[100005];
bool isInside(ll xi) {
    return binary_search(seq, seq + n, xi);
}

bool func(int dist) {
    REP(i, n) {
        ll p2 = seq[i] + dist;
        if(p2 <= L  && isInside(p2))return 1;
    }
    return 0;
}



int main() {
    cin >> n >> L >> x >> y;

    REP(i, n)cin >> seq[i];


    int mask = 0;
    if(func(x))mask |= 1 << 0;
    if(func(y))mask |= 1 << 1;
    if(mask == 3) {
        cout << 0 << '\n';
        return 0;
    }
    if(mask & (1 << 0)) {
        cout << 1 << '\n' << y << '\n';
        return 0;
    }
    if(mask & (1 << 1)) {
        cout << 1 << '\n' << x << '\n';
        return 0;
    }
    //try one point
    REP(i, n) {
        ll p2  = seq[i] + x;
        if(p2 <= L &&  !isInside(p2)) {
            if(isInside(p2 + y) || isInside(p2 - y)) {
                cout << 1 << '\n' << p2 << '\n';
                return 0;
            }
        }
        ll p3  = seq[i] - x;
        if( p3 >= 0 && !isInside(p3)) {
            if(isInside(p3 + y) || isInside(p3 - y)) {
                cout << 1 << '\n' << p3 << '\n';
                return 0;
            }
        }

    }
    //2 two points
    cout << 2 << '\n';
    cout << x << ' ' << y << '\n';

    return 0;
}

