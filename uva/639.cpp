/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,ans,x,y,p,q,a,b,k;
    vector<string> v;
    while(cin>>n && n){
      
        v.resize(n);
        vector<int> xs,ys;
        for(int i=0;i<n;i++){
          cin>>v[i];
        }
        
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(v[i][j]=='X'){
          xs.push_back(i);
          ys.push_back(j);
        }
        ans=0;
        for(int mask=1;mask<(1<<(n*n));mask++){
            vector<int> vi;
            for(int j=0;j<(n*n);j++){
                if(mask&(1<<j))
                  vi.push_back(j);
            }
            bool ok=1;
            for(int i=0;i<vi.sz && ok;i++){
              x=vi[i]/n;
              y=vi[i]%n;
              if(v[x][y]=='X')ok=0;
              for(int j=i+1;j<vi.sz && ok;j++){
                p=vi[j]/n;
                q=vi[j]%n;
                if(p==x){
                  ok=0;
                  a=min(y,q);
                  b=max(y,q);
                  for(k=a+1;k<b;k++)if(v[p][k]=='X')ok=1;
                }
                if(q==y){
                  ok=0;
                  a=min(p,x);
                  b=max(p,x);
                  for(k=a+1;k<b;k++)if(v[k][y]=='X')ok=1;
                }
              }         
            }
            if(ok && vi.sz>ans){
              ans=vi.sz;
            }           
        }
        printf("%d\n",ans);
        
    }
    
    
    //system("pause");
    return 0;
}
