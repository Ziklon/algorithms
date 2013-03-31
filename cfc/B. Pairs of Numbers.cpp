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

int dfs(int x, int y){
    if(x==1 && y==1)return 0;
    if(x==y)return 1<<20;
    if(x>y)
        return dfs(x-y,y)+1;
    else
        return dfs(x,y-x)+1;
    
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,ans;
    ans=1<<20;
    cin>>n;
    REP(i,1,n+1)
        ans=min(ans,dfs(n,i));
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
