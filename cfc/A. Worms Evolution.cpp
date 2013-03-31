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
int A[110];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    REP(i,0,n)cin>>A[i];

    bool ok=0;
    REP(i,0,n){
        if(ok)break;
        REP(j,0,n){
            if(ok)break;
            REP(k,j+1,n){
                if(A[i]==A[j]+A[k] && i!=j && i!=k){
                   cout<<(i+1)<<" "<<(j+1)<<" "<<(k+1)<<endl;
                   ok=1;
                   break;            
                }
            }
            
        }
    }
    if(!ok)cout<<-1<<endl;
    //system("pause");
    return 0;
}
