/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<long long> vl;
void generate(long long n){
  if(n>1000000000LL)return;
  if(n!=0)vl.push_back(n);
  generate(n*10+4);
  generate(n*10+7);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    generate(0);
    sort(all(vl));
    long long p1=5,p2=6,v1=8,v2=10,k=1;
    //cin>>p1>>p2>>v1>>v2>>k;
    long long tot=0,mm;
    if(p1>v1){
      swap(p1,v1);
      swap(p2,v2);
    }
    mm=(p2-p1+1)*(v2-v1+1);
    
    
    while(1){
      
      int x=lower_bound(all(vl),p1)-vl.begin();
      int y=x+k-1;
      long long ny=vl[y];      
      long long nx=vl[x];
      
      if(ny>v2 || nx>p2)break;
      tot+=(nx-p1+1LL)*(v2-ny+1LL);
      p1=nx+1;

    }
    //cout<<tot<<endl;
   double ans=(tot*2.0)/(double)mm;
   printf("%0.012f\n",ans);
    
    system("pause");
    return 0;
}
