#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
string s ;
int k, n;

int main() {
    cin >> s >> k;
    n = s.size();
    int ans = k >> 1;

    if(n <= k) {
        int sum = (n + k);
        if(sum & 1)sum--;
        ans = max(ans, sum);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            int len = (j - i + 1);
            string sub1 = s.substr(i, len);
            string sub2 = s.substr(j + 1);
            int mini = min(sub1.size(), sub2.size());
            bool can = 1;
            if(len >= mini  && mini + k < len )continue;
            for(int k = 0; k < mini; ++k)if(sub1[k] != sub2[k])can = 0;
            if(can) ans = max(ans, len * 2);
        }
    }
    cout << ans << endl;
    return 0;
}
