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
int n;
string A[25];
string trim(string s){
  int i,j;
  for(i=0;i<s.sz&&s[i]==' ';i++);
  for(j=s.sz-1;j>=0&&s[j]==' ';j--);
  return s.substr(i,j-i+1);  
}
int main(){
   //freopen("in2.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   cin>>n;
   int pt=n;
   int a=0;
   A[0]=string(2*n-1,' ')+" 0";
   REP(i,1,(n+1))
      A[i]=A[i-1].substr(2)+" "+string(1,'0'+i);
   REP(i,1,n+1){
      string tmp=trim(A[i]);
      reverse(all(tmp));
      tmp=tmp.substr(1);
      A[i]=A[i]+tmp;      
   }      
   REP(i,0,n+1)
      cout<<A[i]<<endl;
   REP(i,1,n+1)
      cout<<A[n-i]<<endl;
   //system("pause");   
   return 0;
}
