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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long N,L,U,M;
int tam;
string tobin(long long n){
  string ans="";
  int cnt=0;
  while(n>0){
    ans=string(1,'0'+n%2)+ans;
    n/=2;
    cnt++;
  }
  tam=max(tam,cnt);
  return ans;
}
long long toten(string s){
  long long ans=0;
  for(int i=0;i<s.sz;i++)
    ans=ans*2 + s[i]-'0';
  return ans;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  string a,b,c,ans;
  
  while(cin>>N>>L>>U ){
      tam=0;
      a=tobin(N);
      b=tobin(L);
      c=tobin(U);
      
      
      if(a.sz<tam)a=string(tam-a.sz,'0')+a;
      if(b.sz<tam)b=string(tam-b.sz,'0')+b;
      if(c.sz<tam)c=string(tam-c.sz,'0')+c;
      ans=b;
      M=0;
      
      for(int j=tam-1;j>=0;j--){
          if(a[j]==ans[j] && ans[j]=='0'){
            ans[j]='1';
            if(ans>c){
              ans[j]='0';                
              break;
            }
          }
      }
      M=toten(ans);
      if((N|M)< (N|U))
        M=U;
      cout<<M<<endl;      
  }
  return 0;
}
