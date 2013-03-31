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
bool isPrime(int n){ 
  for(int i=2;i*i<=n;i++)
  if(n%i==0)
    return 0;
  return 1;
}

int main(){
  freopen("8.in","r",stdin);
  freopen("8.out","w",stdout);  
  long m=0;
  string s="",tmp;
  while(getline(cin,tmp))s=s+tmp;
  for(int i=4;i<s.sz;i++){
   long ltm=1;       
   for(int j=i-4;j<=i;j++)
     ltm*=(s[j]-'0');
   m=max(m,ltm);
  }
  cout<<m<<endl;
  cin>>s;
  system("pause"); 
}
