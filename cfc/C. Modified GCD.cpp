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
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,n,x,y,i,k,p,q,r;
    scanf("%d %d\n",&a,&b);
    if(a>b)swap(a,b);
    scanf("%d\n",&n);
    
    set<int> S;
    for(i=1;i*i<=a;i++){
      k=a/i;
      if(a%i==0 && b%i==0){
         S.insert(i);
      }
      if(a%k==0 && b%k==0){
         S.insert(k);
      }      
    }
    vector<int> ans(all(S));
    REP(i,0,n){
        scanf("%d %d\n",&x,&y);
        q=upper_bound(all(ans),y)-ans.begin()-1;
        
        if(q>=0 && ans[q]>=x){
          cout<<ans[q]<<endl;  
        }else{
            cout<<-1<<endl;
         } 
    }
    
    //system("pause");
    return 0;
}
