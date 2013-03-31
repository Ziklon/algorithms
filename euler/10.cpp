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
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
string tos(int n) { stringstream ss; ss<<n; return ss.str();}
long long  toi(string s){ istringstream ss(s); long long n; ss>>n; return n;}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}
bool v[20000000];
int t=2000000;
long long sm=0;
void criba(){
  mem(v,1);   
  v[1]=0;
  v[0]=0;   
  for(int i=2;i*i<=t;i++)
    if(v[i])
      for(int j=i*i;j<=t;j=j+i)
        v[j]=0;
}
int main(){
  freopen("8.in","r",stdin);
  freopen("8.out","w",stdout);    
  criba();   
  for(int i=2;i<=t;i++){
    if(v[i])sm+=i;
  }
  cout<<sm<<endl;
  system("pause"); 
}
