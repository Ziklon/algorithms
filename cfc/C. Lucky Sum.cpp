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
vector<long long > v;
long long n,m,ans,x;
void rec(long long a){
    if(a>10000000000LL)return;
    if(a!=0)v.push_back(a);
    rec((a*10) +4);
    rec((a*10) +7);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m;
    ans=0;
    rec(0);
    sort(all(v));
    int index=lower_bound(all(v),n)-v.begin();
    for(;index<v.sz;index++){
        if(n>m)break;        
        x=min(v[index]-n+1,m-n+1);
        ans+=x*v[index];
        n+=x;
        //cout<<x<<" "<<ans<<" "<<n<<endl;        
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
