/*
ID: winftc2
PROG: milk
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


int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int N,M,x,y,cnt=0;
    long long ans=0;
    vector<pair<long long,long long> > v;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
      scanf("%d %d",&x,&y);
      v.push_back(make_pair(x,y));
    }
    sort(all(v));
    for(int i=0;i<M && N;i++){
       if(N>=v[i].second){
          N-=v[i].second;
          ans+=v[i].second*v[i].first;
       }else{
          ans+=N*v[i].first;
          N=0;
       } 
    }
    cout<<ans<<endl;    
    //system("pause");
    return 0;
}
