/*
ID: winftc2
PROG: barn1
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
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int M,S,C;
    int gr=0;
    int ans=0;
    cin>>M>>S>>C;
    vector<int> v(C);
    for(int i=0;i<C;i++)cin>>v[i];
    
    sort(all(v));
    vector<bool> vis(300,0);
    
    for(int j=0;j<C;j++)vis[v[j]]=1; 
    ans=C;
    vector<int> vp;    
    for(int i=0;i<=S;i++){
       if(!vis[i]){
          gr++;
          int j;
          for(j=0;!vis[j+i];j++);
          vp.push_back(j);
          i=i+j-1;          
       }        
    }
    gr=0;
    for(int i=0;i<=S;i++){
       if(vis[i]){
          gr++;
          int j;
          for(j=0;vis[j+i];j++);
          i=i+j-1;          
       }        
    }
    
    vp.erase(vp.begin());
    vp.pop_back();
    int ft=max(0,gr-M);
    sort(all(vp));
    for(int i=0;i<ft;i++){
      ans+=vp[i];
    }  
    
    cout<<ans<<endl;    
    //system("pause");
    return 0;
}
