/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,res;
    vector<string> v;
    string line,text;
    map<string,int>M;
    bool vis[20][20];
    fill(vis,0);
    
    cin>>n>>m;
    REP(i,0,n){
      cin>>line;
      v.push_back(line);
      M[line]=i;
    }
    REP(i,0,m){
      cin>>line>>text;
      vis[M[line]][M[text]]=1;
      vis[M[text]][M[line]]=1;
    }
    sort(all(v));
    res=0;
    for(int mask=0;mask<(1<<n);mask++){
        vector<int> aux;
        REP(i,0,n){
          if(mask&(1<<i))
            aux.push_back(M[v[i]]);
        }
        bool ok=1;
        REP(i,0,aux.sz){
          REP(j,i+1,aux.sz){
            if(vis[aux[i]][aux[j]])
              ok=0;
          }
        }
        if(ok && __builtin_popcount(mask)>__builtin_popcount(res)){
            res=mask;
        }
        
    }
    n=__builtin_popcount(res);
    cout<<n<<endl;
    REP(i,0,v.sz){
        if(res&(1<<i))
          cout<<v[i]<<endl;
    }
    //system("pause");
    return 0;
}
