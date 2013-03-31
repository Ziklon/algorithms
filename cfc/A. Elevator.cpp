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
#define MAX 100000005

using namespace std;
struct node{
    int x,y,t,i,r;
}
bool cmpTime(node p, node q){
    return p.t<q.t;
}
bool cmpIndex(node p, node q){
    return p.i<q.i;
}

int S[1<<20];
int P[1<<20];
node B[1<<20];



int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long n,m,x,y,m;
    cin>>n>>m;
    REP(i,0,n){
        node nd;
        cin>>nd.x>>nd.y>>nd.t;
        nd.i=i;
        B[i]=nd;
    }
    sort(B,B+n,cmpTime);
    int xs=m*2 +1;
    int pun=0;
    int xo=0;
    for(int i=0;i<=MAX;i+=xs){
        xo=xo^1;
        while(pun<n && B[i].t<=i){
           int mod=B[i]%(xs);
           if(xo){
                
            }else{
            
            }
            
        }
    }
    system("pause");
    return 0;
}
