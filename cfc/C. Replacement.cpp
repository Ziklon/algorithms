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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    vector<int> v;
    cin>>n;
    v.resize(n);
    REP(i,0,n)cin>>v[i];
    sort(all(v));
    
    bool ok=0;
    
    REP(i,0,n){
        if(v[n-i-1]!=1){
            v[n-i-1]=1;
            ok=1;
            break;
        }
    }
    if(!ok)v[0]=2;
    sort(all(v));
    printf("%d",v[0]);
    REP(i,1,n)printf(" %d",v[i]);
    printf("\n");    
    //system("pause");
    return 0;
}
