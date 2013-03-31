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
int A[1<<10];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,d;
    scanf("%d %d",&n,&d);
    REP(i,0,n)scanf("%d",&A[i]);
    int ans=0;
    REP(i,0,n)
        REP(j,i+1,n)
            if(abs(A[i]-A[j])<=d)
                ans++;
    cout<<(ans*2)<<endl;
    //system("pause");
    return 0;
}
