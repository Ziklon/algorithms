/*
ID: winftc2
PROG: milk
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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int toi(string &s,string &sv){
  int ans=0;
  REP(i,0,s.sz){
    ans=(ans*10)+(s[sv[i]-'0']-'0');
  }
  return ans; 
}

string nums[12];

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n,k,ans,aux;
   string cad;
   cin>>n>>k;
   cad="";
   ans=1<<29;
   REP(i,0,n)cin>>nums[i];
   REP(i,0,k)cad=cad+string(1,'0'+i);
   do{
      int maxi=0;
      int mini=1<<29;
      REP(i,0,n){
        aux=toi(nums[i],cad);
        maxi=max(aux,maxi);
        mini=min(aux,mini);
      }
      ans=min(ans,maxi-mini);    
      
   }while(next_permutation(all(cad)));
   
   
   cout<<ans<<endl; 
   //system("pause");
   return 0;
}
