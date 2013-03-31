#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
using namespace std;
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}

int gn(char c){
  return c-48;
}
string sum(string a,string b){
  reverse(all(a));
  reverse(all(b));
  if(b.sz>a.sz) swap(a,b);
  string res="";
  int lleva=0,sm;
  for(int i=0;i<a.sz;i++){
    if(i<b.sz){
      sm=gn(a[i])+gn(b[i])+lleva;
      res+=string(1,sm%10 +'0');
      lleva=(sm>=10)?1:0;           
    }else{
      sm=gn(a[i])+lleva;
      res+=string(1,sm%10 +'0');
      lleva=(sm>=10)?1:0; 
    }
  }
  if(lleva)res+=string(1,1+'0');
  reverse(all(res));
  return res;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nC=0;
    cin>>nC;
    string a,b,c;
    for(int i=1;i<=nC;i++){
      cin>>a>>b;
      c=sum(a,b);
      printf("Case %d:\n",i);
      cout<<a<<" + "<<b<<" = "<<c<<endl;
      if(i!=nC)cout<<endl;
    } 
    return 0;
}
