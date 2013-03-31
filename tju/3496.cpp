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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}

int rever(int a){
  int n=0;
  while(a){
    n=n*10+a%10;
    a/=10;
  }
  return n;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n=0;
  cin>>n;
  while(n){
    int x,y,a;
    cin>>x>>y;
    x=rever(x);
    y=rever(y);
    a=x+y;
    printf("%d\n\n",a);
    n--;    
  } 
  return 0;
}

