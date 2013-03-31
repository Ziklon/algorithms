#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
int next(int t) {
    // return next larger int with same hamming weight as t
    int b = t & (-t);
    int s = t/b + 1;
    int c = s & (-s);
    return s * b + c/2 - 1;
}

int solve(vector<int> & D) {
    int k = D.size();
    sort(D.begin(), D.end());
    int end = 1<<k;
    map<int, map<int,int> > tab; // set -> (this side -> other side)
    tab[0][0] = 0;
    for (int j = 0; j < k; ++j)
        tab[1<<j][0] = D[j];
    for (int i = 2; i <= k; ++i) {
        cerr << "Doing size " << i << endl;
        for (int s = (1<<i) - 1; s < end; s = next(s)) {
            bool is_new = true;
            for (int j=1; is_new && j < k; ++j) {
                if (D[j] == D[j-1] && ((1<<j) & s) && !((1<<(j-1)) & s)) {
                    is_new = false;
                    tab[s] = tab[s - (1<<j) + (1 << (j-1))];
                }
            }
            if (! is_new) continue;
            map<int,int> tabs;
            int last_D = -1;
            for (int j = 0; j < k; ++j) {
                if ((1<<j) & s) {
                    if (last_D == D[j]) continue;
                    int t = s - (1<<j);
                    for (map<int,int>::iterator p = tab[t].begin();
                             p != tab[t].end(); ++p) {
                        int ts = p->first;
                        int os = p->second;
                        int ns = max(ts + 1 + D[j], os + 1);
                        if (tabs.count(os)) tabs[os] = min(tabs[os], ns);
                        else tabs[os] = ns;
                    }
                    last_D = D[j];
                }
            }
            // prune tabs and put in tab[s]
            for (map<int,int>::iterator p = tabs.begin();
                     p != tabs.end(); ++p) {
                map<int,int>::reverse_iterator q = tab[s].rbegin();
                if (q != tab[s].rend() && q->second <= p->second)
                    continue;
                tab[s].insert(*p);
            }
        }
    }
    int res = -1;
    for (map<int,int>::iterator p = tab[end-1].begin();
             p != tab[end-1].end(); ++p) {
        if (res == -1)
            res = p-> second;
        else
            res = min(res, p->second);
    }
    return res;
}

int main() {
    int k;
    cin >> k;
    vector<int> D(k);
    for (int i=0; i < k; ++i) cin >> D[i];
    cout << solve(D) << endl;
    return 0;
}
