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
    vector<pair<int,int> >v;
    int n,x,y;
    scanf("%d",&n);
    REP(i,0,n){
      scanf("%d %d",&x,&y);
      v.push_back(make_pair(x,y));
    }
    sort(all(v));
    int ans=0;
    int far=0;
    REP(i,0,n){
        if(v[i].second<=far)ans++;
        far=max(far,v[i].second);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
