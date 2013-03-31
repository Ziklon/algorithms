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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,S,P;
    scanf("%d\n",&T);
    REP(i,0,T){
      scanf("%d %d\n",&S,&P);
      string ans="";
      bool ok=1;
      while(ok){
         int j;
         ok=0;
         for(j=9;j>=1;j--){
            if((S-j)<=(P-(j*j)) && (S-j)>=0 && (P-(j*j))>=0){
               S-=j;
               P-=j*j;
               ok=1;
               ans+='0'+j;
               break;
            }
         }
      }
      sort(all(ans));
      //cout<<"aaaaaaaaaaa"<<endl;
      
      if(S==0 && P==0 && ans.sz<=100)
            cout<<ans<<endl;
      else 
            cout<<"No solution"<<endl;
            
      
    }  
    //system("pause");
    return 0;
}
