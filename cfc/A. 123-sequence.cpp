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
int A[4];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    cin>>n;
    fill(A,0);
    REP(i,0,n){
        cin>>m;
        A[m]++;
    }
    int ans=1<<29;
    ans=min(ans,A[1]+A[2]);
    ans=min(ans,A[3]+A[2]);
    ans=min(ans,A[1]+A[3]);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
