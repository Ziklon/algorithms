#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,x;
    vector<pair<int,int> > v;
    cin>>n;

    REP(i,0,n){
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(all(v));
    cout<<v[0].second+1;
    
    REP(i,1,v.sz)
      cout<<" "<<v[i].second+1;
    //system("pause");
    return 0;
}
