#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
int n, x;
vector<int> G[2005];

void saveRecords(int idx, vector<int>&v) {
    if(idx >= 2005)return;
    if(G[idx].size() == 0) {
        saveRecords(idx + 1, v);
        return;
    }
    for(int i = 0; i < G[idx].size(); ++i)v.push_back(G[idx][i]);
    saveRecords(idx + 1, v);
}

bool makePerm(int idx) {
    if(idx >= 2005)return false;
    if(G[idx].size() <= 1)return makePerm(idx + 1);
    if(next_permutation(all(G[idx])))return true;
    return makePerm(idx + 1);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        G[x].push_back(i + 1);
        sort(all(G[x]));
    }
    vector<vector<int> >ans(3);

    for(int i = 0; i < 3; ++i) {
        saveRecords(0, ans[i]);
        if(i <= 1 && !makePerm(0)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(vector<int> v : ans) {
        for(int item : v)cout << item << ' ';
        cout << '\n';
    }

    return 0;
}

