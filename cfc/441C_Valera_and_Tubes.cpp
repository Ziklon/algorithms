#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define MAXN 100000
int w, h, k;

vector<pair<int, int> > G[MAXN];


int main() {
    scanf("%d %d %d", &w, &h, &k);
    
    freopen("output.txt","w",stdout);
    
    int cnt = 0;
    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) {
            int curj = j;
            
            if(i & 1)curj = (h - j - 1);

            int toAdd = cnt / 2;
            if(toAdd >= k)toAdd = k - 1;
            
            G[toAdd].push_back(make_pair(i + 1, curj + 1));
            
            cnt++;
        }
    }
    for(int i = 0; i < k; ++i) {
        cout<<G[i].size();
        
        for(auto p  : G[i]){
            cout<<" "<<p.first<<" "<<p.second;
        }
        cout<<endl;
    }
    return 0;
}
