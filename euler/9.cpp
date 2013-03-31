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
  int a=1,b=1,c=1;
  for(int i=0;i<=1000;i++)
    for(int j=i+1;j<=1000;j++)
      for(int k=j+1;k<=1000;k++){
        if(i+j+k==1000){
          if(i*i+j*j==k*k){
            a=i;
            b=j;
            c=k;
          }
        }
      }
  cout<<a*b*c<<endl;
  system("pause"); 
}
