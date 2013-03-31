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
int A[1001];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,n,ans=0;
    cin>>x;
    set<int> S;
    fill(A,0);
    REP(i,0,x){
        cin>>n;
        S.insert(n);
        A[n]++;
        ans=max(ans,A[n]);
    }
    cout<<ans<<" "<<S.sz<<endl;
    //system("pause");
    return 0;
}
