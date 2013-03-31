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
  int c=0;
  long long m=0;
  for(int i=2;c<10001;i++)
    if(isPrime(i))c++,m=i;
  cout<<m<<endl;
  system("pause"); 
}
