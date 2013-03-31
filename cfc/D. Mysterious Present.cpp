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

struct node{
  int w,h,i;
  node(){}
  node(int _w,int _h, int _i){
    w=_w;
    h=_h;
    i=_i;
  }  
};

bool orden(node p, node q){
    if(p.w!=q.w)return p.w<q.w;
    return p.h<q.h;
}

int dp[5005];
vector<node>v;
int deph[5005];
int go(int p){
   int& ref=dp[p];
   if(ref!=-1)return ref;   
   ref=0;
   REP(i,p+1,v.sz){
     if(v[i].w>v[p].w && v[i].h>v[p].h){
        if(1+go(i)>ref){
            ref=1+go(i);
            deph[p]=i;
        }
     }   
   } 
   return ref;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N,W,H,a,b;
    scanf("%d %d %d",&N,&W,&H);
    v.push_back(node(W,H,0));
    
    REP(i,0,N){
        scanf("%d %d",&a,&b);
        v.push_back(node(a,b,i+1));
    }
    int index=0,ans;
    sort(all(v),orden);
    REP(i,0,v.sz)
        if(v[i].i==0)index=i;
    fill(dp,-1);
    fill(deph,0);
    ans=go(index);
    cout<<ans<<endl;
    vector<int> res;
    int val=deph[index];
    while(val!=0){
        res.push_back(v[val].i);
        val=deph[val];        
    }        
        
    if(ans>0){
        cout<<res[0];
        REP(i,1,res.sz)
            cout<<" "<<res[i];
        cout<<endl;
    }    
    //system("pause");
    return 0;
}
    
