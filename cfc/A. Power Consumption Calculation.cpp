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
    int P[3],n,T[2],l,r,ans=0;
    cin>>n;
    REP(i,0,3)cin>>P[i];
    REP(i,0,2)cin>>T[i];
    int last=0;
    int sob=0;
    REP(i,0,n){
        cin>>l>>r;
        ans+=(r-l)*P[0];
        if(i>0){
            sob=l-last;
            if(sob>0){
                ans+=min(T[0],sob)*P[0];
                sob-=min(T[0],sob);
            }
            if(sob>0){
                ans+=min(sob,T[1])*P[1];
                sob-=min(sob,T[1]);
            }
            if(sob>0){
                ans+=sob*P[2];
            }                      
        }
        last=r;
            
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
